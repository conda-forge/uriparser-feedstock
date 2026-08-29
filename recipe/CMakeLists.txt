cmake_minimum_required(VERSION 3.15)
project(uriparser_consumer LANGUAGES C)

find_package(uriparser CONFIG REQUIRED)

add_executable(uriparser_consumer test.c)
target_link_libraries(uriparser_consumer PRIVATE uriparser::uriparser)
