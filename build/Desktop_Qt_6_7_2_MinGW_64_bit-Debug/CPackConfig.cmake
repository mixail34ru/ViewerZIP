# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "C:/Users/Michael/Documents/QtProjects/ViewerZIP;C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Qt/Tools/CMake_64/share/cmake-3.29/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "ViewerZIP built using CMake")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INNOSETUP_ARCHITECTURE "x64")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug;ViewerZIP;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/ViewerZIP")
set(CPACK_MODULE_PATH "C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6;C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6/3rdparty/kwin;C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6;C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6/3rdparty/extra-cmake-modules/find-modules;C:/Qt/6.7.2/mingw_64/lib/cmake/Qt6/3rdparty/kwin;C:/Users/Michael/Documents/QtProjects/ViewerZIP/libs/minizip-ng/cmake")
set(CPACK_NSIS_DISPLAY_NAME "zlib-ng 2.2.2")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES64")
set(CPACK_NSIS_PACKAGE_NAME "zlib-ng 2.2.2")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OBJCOPY_EXECUTABLE "C:/Qt/Tools/mingw1120_64/bin/objcopy.exe")
set(CPACK_OBJDUMP_EXECUTABLE "C:/Qt/Tools/mingw1120_64/bin/objdump.exe")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Qt/Tools/CMake_64/share/cmake-3.29/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "ViewerZIP built using CMake")
set(CPACK_PACKAGE_DIRECTORY "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/package")
set(CPACK_PACKAGE_FILE_NAME "zlib-ng-2.2.2-win64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "zlib-ng 2.2.2")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "zlib-ng 2.2.2")
set(CPACK_PACKAGE_NAME "zlib-ng")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "2.2.2")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PRODUCTBUILD_DOMAINS "ON")
set(CPACK_READELF_EXECUTABLE "C:/Qt/Tools/mingw1120_64/bin/readelf.exe")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Qt/Tools/CMake_64/share/cmake-3.29/Templates/CPack.GenericLicense.txt")
set(CPACK_RESOURCE_FILE_README "C:/Qt/Tools/CMake_64/share/cmake-3.29/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Qt/Tools/CMake_64/share/cmake-3.29/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES ".git/;_CPack_Packages/;C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/libs/minizip-ng/libs/zlib-ng/")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/CPackSourceConfig.cmake")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_THREADS "1")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Users/Michael/Documents/QtProjects/ViewerZIP/build/Desktop_Qt_6_7_2_MinGW_64_bit-Debug/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
