### CMakeLists.txt ---
## 
## Author: Julien Wintz
## Created: Tue Mar 12 16:36:28 2013 (+0100)
## Version: 
## Last-Updated: Tue Mar 12 18:12:46 2013 (+0100)
##           By: Julien Wintz
##     Update #: 11
######################################################################
## 
### Change Log:
## 
######################################################################

project(QtQuickMouseArea)

qt5_add_resources(${PROJECT_NAME}_RCC main.qrc)

add_executable(${PROJECT_NAME} main.cpp ${${PROJECT_NAME}_RCC})

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Quick)

target_link_libraries(${PROJECT_NAME} QLeapGui)
