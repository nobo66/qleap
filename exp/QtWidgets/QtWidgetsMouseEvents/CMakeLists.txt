### CMakeLists.txt ---
## 
## Author: Julien Wintz
## Created: Tue Mar 12 13:01:33 2013 (+0100)
## Version: 
## Last-Updated: Tue Mar 12 13:02:43 2013 (+0100)
##           By: Julien Wintz
##     Update #: 5
######################################################################
## 
### Change Log:
## 
######################################################################

project(QtWidgetsMouseEvents)

add_executable(${PROJECT_NAME} main.cpp)

qt5_use_modules(${PROJECT_NAME} Core)
qt5_use_modules(${PROJECT_NAME} Gui)
qt5_use_modules(${PROJECT_NAME} Widgets)

target_link_libraries(${PROJECT_NAME} QLeapGui)
