
cmake_minimum_required (VERSION 2.6)
project (Client)

include_directories(/usr/local/opt/openssl/include/)

find_package(OpenSSL REQUIRED)


find_package(Poco REQUIRED COMPONENTS Foundation Net NetSSL Zip )

add_executable(Client client.cpp)

target_link_libraries(Client PUBLIC Poco::Foundation Poco::Zip Poco::Net Poco::NetSSL OpenSSL::SSL OpenSSL::Crypto)

