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
    Poco::URI uri("http://127.0.0.1:5000/run_task");
    std::string path(uri.getPathAndQuery());
    if (path.empty()) path = "/";

    Poco::Net::Context::Ptr ctx = new Poco::Net::Context(Poco::Net::Context::CLIENT_USE, "", Poco::Net::Context::VERIFY_NONE, 9, true);
    Poco::Net::HTTPSClientSession session(uri.getHost(), uri.getPort(), ctx);

    std::cout << "Welcome to task sending.\n";

    int exit = 0;
    char op;
    std::string action;
    int num1, num2;

    while (!exit) {

        std::cout << "Enter operator either + or - or * (or e to exit):\n";
        std::cin >> op;

        if (op == 'e') {
            exit = 1;
            std::cout << "Goodbye!";
            continue;
        }

        switch (op) {
            case '+':
                action = "add";
                break;
            case '-':
                action = "sub";
                break;
            case '*':
                action = "multiply";
                break;
            default:
                std::cout << "Invalid operator " << op << "\n";
                continue;

        }

        std::cout << action;

        std::cout << "Enter two operands: ";
        std::cin >> num1 >> num2;

        Poco::JSON::Object obj;
        obj.set("action", action);
        obj.set("a", num1);
        obj.set("b", num2);

        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_POST, path, Poco::Net::HTTPMessage::HTTP_1_1);
        Poco::Net::HTTPResponse response;

        request.setContentType("application/json");
        std::stringstream ss;
        obj.stringify(ss);
        request.setContentLength(ss.str().size());
        std::ostream &o = session.sendRequest(request);

        obj.stringify(o);

        std::istream &s = session.receiveResponse(response);

        int status = response.getStatus();
        if (status != 200) {
            std::cout << "Request Failed\n";
        }
        Poco::StreamCopier::copyStream(s, std::cout);
        std::cout << "\n";
    }
    return 0;
}