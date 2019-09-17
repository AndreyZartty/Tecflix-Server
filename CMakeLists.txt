cmake_minimum_required(VERSION 3.14)
project(Tecflix_Server)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tecflix_Server main.cpp CurlObj.cpp CurlObj.h Data.cpp Data.h)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(Tecflix_Server ${CURL_LIBRARIES})
