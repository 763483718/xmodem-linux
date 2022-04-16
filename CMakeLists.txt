cmake_minimum_required(VERSION 2.8)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_BUILD_TYPE Release)

#set(CMAKE_C_COMPILER gcc)
#set(CMAKE_CXX_COMPILER g++)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(LOCAL_INC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/rkisp_inc)
set(LOCAL_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/rkisp_lib)

include_directories(/usr/include/drm )
include_directories(/usr/include/gstreamer-1.0 )
include_directories(/usr/include/glib-2.0 )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/firefly )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gstreamer )
include_directories(${LOCAL_INC_PATH} )
include_directories(${LOCAL_INC_PATH}/interface )
include_directories(${LOCAL_INC_PATH}/xcore )
include_directories(${LOCAL_INC_PATH}/xcore/ia )
include_directories(${LOCAL_INC_PATH}/ext/rkisp )
include_directories(${LOCAL_INC_PATH}/plugins/3a/rkiq )
include_directories(${LOCAL_INC_PATH}/modules/isp )
include_directories(${LOCAL_INC_PATH}/rkisp/ia-engine )
include_directories(${LOCAL_INC_PATH}/rkisp/ia-engine/include )
include_directories(${LOCAL_INC_PATH}/rkisp/ia-engine/include/linux )
include_directories(${LOCAL_INC_PATH}/rkisp/ia-engine/include/linux/media )
include_directories(${LOCAL_INC_PATH}/rkisp/isp-engine )
include_directories(${LOCAL_INC_PATH}/metadata/libcamera_client/include)
include_directories(${LOCAL_INC_PATH}/metadata/libcamera_metadata/include)
include_directories(${LOCAL_INC_PATH}/metadata/header_files/include/system/core/include)
include_directories(${LOCAL_INC_PATH}/ext/rkisp/usr/include/drm)
include_directories(${CMAKE_SOURCE_DIR}/../3rdparty/drm)

link_directories(/usr/lib/rkisp/ae)
link_directories(/usr/lib/rkisp/af)
link_directories(/usr/lib/rkisp/awb)



set(CMAKE_INSTALL_RPATH "lib")
set(link_libs dl  pthread  )
add_executable(xmodem main.cpp xmodem.cpp usart.cpp crc16.cpp xmodem_linux.cpp ) #usart.cpp crc16.c xmodem_linux.cpp 
target_link_libraries(xmodem ${link_libs})
target_compile_definitions(xmodem PUBLIC RKISP=1)
target_compile_definitions(xmodem PUBLIC LINUX)
target_compile_definitions(xmodem PUBLIC USE_RGA)

#add_library(gstrkisp SHARED
#	gstreamer/gstrkisp.cpp
#	gstreamer/gstxcambuffermeta.cpp
#	gstreamer/gstxcambufferpool.cpp
#	gstreamer/media-controller.c
#	gstreamer/interface/gstxcaminterface.c
#    )
#
#set(gst_link_libs gstbase-1.0 gstreamer-1.0 gobject-2.0	glib-2.0 gstallocators-1.0 gstvideo-1.0	gstvideo4linux2 drm rkisp)
#target_link_libraries(gstrkisp ${gst_link_libs})
#
INCLUDE(GNUInstallDirs)

INSTALL(TARGETS xmodem RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
