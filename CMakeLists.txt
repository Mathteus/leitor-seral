set(CMALE_VERBOSE_FILE ON)
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(Teste)

find_package(Threads)
find_package(PkgConfig)
pkg_check_modules(SERIAL libserial)

set(SERIAL_HEADERS "libs/libserial")
include_directories(${SERIAL_HEADERS})

add_executable(Teste src/main.cpp src/myserial.cpp)
target_link_libraries(${PROJECT_NAME} -lserial ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})


