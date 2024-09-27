################################################################################
# If not stated otherwise in this file or this component's Licenses.txt file the
# following copyright and licenses apply:
#
# Copyright 2024 RDK Management
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################
cmake_minimum_required(VERSION 3.3)
project(systemaudioplatform VERSION 1.0.0 LANGUAGES CXX)

set(LIBNAME systemaudioplatform)
set(SRCS systemaudioplatform.cpp)
set(DEFAULT_BUILD_TYPE "Release")

find_package(PkgConfig REQUIRED) 

pkg_check_modules(GSTREAMERBASE REQUIRED gstreamer-app-1.0)
pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)

add_library(${LIBNAME} SHARED ${SRCS})

set_target_properties(${LIBNAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER systemaudioplatform.h
)

target_include_directories(${LIBNAME} PRIVATE ${GSTREAMER_INCLUDES})
target_include_directories(${LIBNAME} PRIVATE ${GSTREAMERBASE_INCLUDE_DIRS})

target_link_libraries(${LIBNAME} PRIVATE ${GSTREAMER_LIBRARIES})
target_link_libraries(${LIBNAME} PRIVATE ${GSTREAMERBASE_LIBRARIES})

install(TARGETS ${LIBNAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
