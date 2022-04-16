cmake_minimum_required(VERSION 2.8)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Release)

#set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(CMAKE_INSTALL_RPATH "lib")
set(link_libs dl  pthread  )
add_executable(xmodem ../main.cpp ../xmodem.cpp ../usart.cpp ../crc16.cpp ../xmodem_linux.cpp )
target_link_libraries(xmodem ${link_libs})
target_compile_definitions(xmodem PUBLIC RKISP=1)
target_compile_definitions(xmodem PUBLIC LINUX)
target_compile_definitions(xmodem PUBLIC USE_RGA)


INCLUDE(GNUInstallDirs)

INSTALL(TARGETS xmodem RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
