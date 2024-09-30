cmake_minimum_required(VERSION 3.16)

project(ViewerZIP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

##$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng>
##$<INSTALL_INTERFACE:/libs/minizip-ng>

#add_library(minizip STATIC ${MINIZIP_SRC} ${MINIZIP_HDR})
##(minizip PUBLIC minizip)


#set(ZLIB_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")
#set( "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")

#add_library(minizip STATIC "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")
#include_directories(minizip PUBLIC"${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")

#set(ZLIB_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")
#set(ZLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")

# Initial source files
#set(MINIZIP_SRC
#    /libs/minizip-ng/mz_crypt.c
#    /libs/minizip-ng/mz_os.c
#    /libs/minizip-ng/mz_crypt.c
#    /libs/minizip-ng/mz_strm.c
#    /libs/minizip-ng/mz_strm_buf.c
#    /libs/minizip-ng/mz_strm_mem.c
#    /libs/minizip-ng/mz_strm_split.c
#    /libs/minizip-ng/mz_zip.c
#    /libs/minizip-ng/mz_zip_rw.c)

set(MINIZIP_SRC "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")

## Initial header files
#set(MINIZIP_HDR
#    /libs/minizip-ng/mz.h
#    /libs/minizip-ng/mz_os.h
#    /libs/minizip-ng/mz_crypt.h
#    /libs/minizip-ng/mz_strm.h
#    /libs/minizip-ng/mz_strm_buf.h
#    /libs/minizip-ng/mz_strm_mem.h
#    /libs/minizip-ng/mz_strm_split.h
#    /libs/minizip-ng/mz_strm_os.h
#    /libs/minizip-ng/mz_zip.h
#    /libs/minizip-ng/mz_zip_rw.h)

set(MINIZIP_HDR "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")

set(MINIZIP_TARGET minizip-ng)
add_library(${MINIZIP_TARGET} ${MINIZIP_SRC} ${MINIZIP_HDR})

target_include_directories(${MINIZIP_TARGET} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")
target_link_directories(${MINIZIP_TARGET} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng")
target_link_libraries(${MINIZIP_TARGET} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/libs/minizip-ng/third_party")

set(PROJECT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.rc")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ViewerZIP
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

        source/main.cpp
        include/model/ZipInfoStorage.h include/model/ZipInfoStorageViewInterface.h include/view/CentralWidget.h include/view/MainWindow.h include/view/TableModel.h include/view/TableView.h
        source/model/ZipInfoStorage.cpp source/model/ZipInfoStorageViewInterface.cpp source/view/CentralWidget.cpp source/view/MainWindow.cpp source/view/TableModel.cpp source/view/TableView.cpp
        include/model/ZipFilesViewer.h
        source/model/ZipFilesViewer.cpp
        include/view/MenuBar.h
        source/view/MenuBar.cpp
        libs/minizip-ng/minigzip.c libs/minizip-ng/minizip.c libs/minizip-ng/mz.h libs/minizip-ng/mz_compat.c libs/minizip-ng/mz_compat.h libs/minizip-ng/mz_crypt.c libs/minizip-ng/mz_crypt.h libs/minizip-ng/mz_crypt_apple.c libs/minizip-ng/mz_crypt_openssl.c libs/minizip-ng/mz_crypt_winvista.c libs/minizip-ng/mz_crypt_winxp.c libs/minizip-ng/mz_os.c libs/minizip-ng/mz_os.h libs/minizip-ng/mz_os_posix.c libs/minizip-ng/mz_os_win32.c libs/minizip-ng/mz_strm.c libs/minizip-ng/mz_strm.h libs/minizip-ng/mz_strm_buf.c libs/minizip-ng/mz_strm_buf.h libs/minizip-ng/mz_strm_bzip.c libs/minizip-ng/mz_strm_bzip.h libs/minizip-ng/mz_strm_libcomp.c libs/minizip-ng/mz_strm_libcomp.h libs/minizip-ng/mz_strm_lzma.c libs/minizip-ng/mz_strm_lzma.h libs/minizip-ng/mz_strm_mem.c libs/minizip-ng/mz_strm_mem.h libs/minizip-ng/mz_strm_os.h libs/minizip-ng/mz_strm_os_posix.c libs/minizip-ng/mz_strm_os_win32.c libs/minizip-ng/mz_strm_pkcrypt.c libs/minizip-ng/mz_strm_pkcrypt.h libs/minizip-ng/mz_strm_split.c libs/minizip-ng/mz_strm_split.h libs/minizip-ng/mz_strm_wzaes.c libs/minizip-ng/mz_strm_wzaes.h libs/minizip-ng/mz_strm_zlib.c libs/minizip-ng/mz_strm_zlib.h libs/minizip-ng/mz_strm_zstd.c libs/minizip-ng/mz_strm_zstd.h libs/minizip-ng/mz_zip.c libs/minizip-ng/mz_zip.h libs/minizip-ng/mz_zip_rw.c libs/minizip-ng/mz_zip_rw.h
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ViewerZIP APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ViewerZIP SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ViewerZIP
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ViewerZIP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ViewerZIP)
endif()
set_target_properties(ViewerZIP PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ViewerZIP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ViewerZIP)
endif()
