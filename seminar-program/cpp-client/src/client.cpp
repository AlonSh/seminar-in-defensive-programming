//
// Created by Alon Shenkler on 10/13/18.
//

#include <tkDecls.h>
#include <string>
#include "Poco::JSON::Object obj"
obj.set("name", "blah");
obj.set("language", "english");

Poco::URI uri("http://the-uri-you-want-to-request-from");
std::string path(uri.getPathAndQuery());
if (path.empty()) path = "/";

HTTPClientSession session(uri.getHost(), uri.getPort());
HTTPRequest request(HTTPRequest::HTTP_POST, path, HTTPMessage::HTTP_1_1);
HTTPResponse response;

request.setContentType("application/json");
std::stringstream ss;
obj.stringify(ss);
request.setContentLength(ss.str().size());
std::ostream& o = session.sendRequest(request);

obj.stringify(o);

// this line is where you get your response
std::istream& s = session.receiveResponse(response);

Poco::JSON::Parser parser;
Poco::JSON::Object::Ptr ret = parser.parse(s).extract<Poco::JSON::Object::Ptr>();

// (*ret) will contain all the members in a json structure returned
if ((*ret).get("success") != true) {
std::cout << "Failed to upload: " << (*ret).get("message").toString();
return;
