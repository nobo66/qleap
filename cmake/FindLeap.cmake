### FindLeap.cmake --- 
## 
## Author: Julien Wintz
## Created: Thu Feb 21 11:15:27 2013 (+0100)
## Version: 
## Last-Updated: Thu Feb 21 11:15:32 2013 (+0100)
##           By: Julien Wintz
##     Update #: 3
######################################################################
## 
### Change Log:
## 
######################################################################

#  LEAP_FOUND - System has Leap library.
#  LEAP_INCLUDE_DIRS - The Leap include directories
#  LEAP_LIBRARIES - The libraries needed to use Leap

find_path(LEAP_INCLUDE_DIR Leap.h /usr/include/
C:/Users/Murakami/LeapDeveloperKit/LeapSDK/include)
find_library(LEAP_LIBRARY Leap PATHS /usr/lib
C:/Users/Murakami/LeapDeveloperKit/LeapSDK/lib/x86)

set(LEAP_INCLUDE_DIRS ${LEAP_INCLUDE_DIR})
set(LEAP_LIBRARIES ${LEAP_LIBRARY})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Leap DEFAULT_MSG LEAP_LIBRARY LEAP_INCLUDE_DIR)
