### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Created: Thu Feb 21 11:07:54 2013 (+0100)
## Version: 
## Last-Updated: Tue Mar 12 12:59:56 2013 (+0100)
##           By: Julien Wintz
##     Update #: 16
######################################################################
## 
### Change Log:
## 
######################################################################

cmake_minimum_required(VERSION 2.8.10)

## #################################################################
## 
## #################################################################

project(qleap)

## #################################################################
## 
## #################################################################

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

## #################################################################
## 
## #################################################################

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

## #################################################################
## 
## #################################################################

if(NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
else(NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif(NOT APPLE)

mark_as_advanced(CMAKE_BUILD_TYPE)
mark_as_advanced(CMAKE_INSTALL_PREFIX)
mark_as_advanced(CMAKE_OSX_ARCHITECTURES)
mark_as_advanced(CMAKE_OSX_DEPLOYMENT_TARGET)
mark_as_advanced(CMAKE_OSX_SYSROOT)

enable_testing()

## #################################################################
## Dependencies - Qt
## #################################################################

find_package(Qt5Core    REQUIRED)
find_package(Qt5Gui     REQUIRED)
find_package(Qt5Quick   REQUIRED)
find_package(Qt5Test    REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## #################################################################
## Dependencies - Leap
## #################################################################

find_package(Leap REQUIRED)

include_directories(${LEAP_INCLUDE_DIRS})

## #################################################################
## Dependencies - internal
## #################################################################

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/src/QLeapGui)

## #################################################################
## Input
## #################################################################

add_subdirectory(src)
add_subdirectory(exp)
add_subdirectory(tst)
