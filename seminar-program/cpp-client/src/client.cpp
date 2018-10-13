//
// Created by Alon Shenkler on 10/13/18.
//

#include <string>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/SSLManager.h>
#include <Poco/Net/Context.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>


int main() {
    Poco::JSON::Object obj;
    obj.set("action", "add");
    obj.set("a", 2);
    obj.set("b", 3);

    Poco::URI uri("http://127.0.0.1:5000/run_task");
    std::string path(uri.getPathAndQuery());
    if (path.empty()) path = "/";

    Poco::Net::Context::Ptr ctx = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", Poco::Net::Context::VERIFY_NONE, 9, true);
    Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), ctx);
    Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, path, Poco::Net::HTTPMessage::HTTP_1_1);
    Poco::Net::HTTPResponse response;

    request.setContentType("application/json");
    std::stringstream ss;
    obj.stringify(ss);
    request.setContentLength(ss.str().size());
    std::ostream &o = session.sendRequest(request);

    obj.stringify(o);

    // this line is where you get your response
    std::istream &s = session.receiveResponse(response);

    // Poco::JSON::Parser parser;
    // Poco::JSON::Object::Ptr ret = parser.parse(s).extract<Poco::JSON::Object::Ptr>();

    int status = response.getStatus();
    if (status != 200) {
        std::cout << "Request Failed\n";
    }
    Poco::StreamCopier::copyStream(s, std::cout);
    return 0;
}