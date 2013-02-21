### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Created: Thu Feb 21 13:33:35 2013 (+0100)
## Version: 
## Last-Updated: Thu Feb 21 13:49:31 2013 (+0100)
##           By: Julien Wintz
##     Update #: 19
######################################################################
## 
### Change Log:
## 
######################################################################

project(QLeapGuiTest)

## ###################################################################
## Input
## ###################################################################

set(${PROJECT_NAME}_HEADERS
  QLeapMapperTest.h)

set(${PROJECT_NAME}_SOURCES
  QLeapMapperTest.cpp)

## ###################################################################
## Input - introspected
## ###################################################################

create_test_sourcelist(
    ${PROJECT_NAME}_SOURCES_TST
    ${PROJECT_NAME}.cpp
  ${${PROJECT_NAME}_SOURCES})

## ###################################################################
## Build rules
## ###################################################################

add_executable(${PROJECT_NAME}
  ${${PROJECT_NAME}_SOURCES_TST}
  ${${PROJECT_NAME}_SOURCES})

## ###################################################################
## Link rules
## ###################################################################

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Test)
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} QLeapGui)

## ###################################################################
## Test rules
## ###################################################################

add_test(QLeapMapperTest ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/QLeapGuiTest QLeapMapperTest)
