
cmake_minimum_required (VERSION 2.6)
project (Client)

find_package(OpenSSL REQUIRED)


find_package(Poco REQUIRED COMPONENTS Foundation Net Zip )

add_executable(Client client.cpp)

target_link_libraries(Client PUBLIC Poco::Foundation Poco::Zip Poco::Net OpenSSL)

