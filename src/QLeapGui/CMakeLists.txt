### CMakeLists.txt --- 
## 
## Author: Julien Wintz
## Created: Thu Feb 21 11:18:25 2013 (+0100)
## Version: 
## Last-Updated: Thu Feb 21 11:50:26 2013 (+0100)
##           By: Julien Wintz
##     Update #: 3
######################################################################
## 
### Change Log:
## 
######################################################################

project(QLeapGui)

## #################################################################
## Sources
## #################################################################

set(${PROJECT_NAME}_HEADERS
  QLeap
  QLeap.h
  QLeapController
  QLeapController.h
  QLeapGuiExport
  QLeapGuiExport.h
  QLeapListener
  QLeapListener.h
  QLeapMapper
  QLeapMapper.h)

set(${PROJECT_NAME}_SOURCES
  QLeap.cpp
  QLeapController.cpp
  QLeapListener.cpp
  QLeapMapper.cpp)

if(APPLE)
  set(${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES} QLeap.mm)
endif(APPLE)

## #################################################################
## Build rules
## #################################################################

add_library(${PROJECT_NAME} SHARED
  ${${PROJECT_NAME}_SOURCES}
  ${${PROJECT_NAME}_HEADERS})

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} ${LEAP_LIBRARIES})

if(APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
endif(APPLE)
