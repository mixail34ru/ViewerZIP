# Install script for directory: C:/Users/Michael/Documents/QtProjects/ViewerZIP/libs/minizip-ng/libs/zlib-ng

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/ViewerZIP")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Qt/Tools/mingw1120_64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/libz-ng.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE RENAME "zlib-ng.h" FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/zlib-ng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE RENAME "zlib_name_mangling-ng.h" FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/zlib_name_mangling-ng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE RENAME "zconf-ng.h" FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/zconf-ng.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/zlib-ng.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng/zlib-ng.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng/zlib-ng.cmake"
         "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/CMakeFiles/Export/74a773ded784692c5e5de9162942044e/zlib-ng.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng/zlib-ng-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng/zlib-ng.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng" TYPE FILE FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/CMakeFiles/Export/74a773ded784692c5e5de9162942044e/zlib-ng.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng" TYPE FILE FILES "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/CMakeFiles/Export/74a773ded784692c5e5de9162942044e/zlib-ng-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/zlib-ng" TYPE FILE FILES
    "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/zlib-ng-config.cmake"
    "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/zlib-ng-config-version.cmake"
    )
endif()

