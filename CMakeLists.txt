cmake_minimum_required(VERSION 3.16)

project(ViewerZIP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB CORE_SOURCE source/*.cpp source/view/*.cpp source/model/*.cpp)
file(GLOB CORE_HEADERS include/*.h include/view/*.h include/model/*.h)

include_directories(include include/view include/model)

set(LIBS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/libs")
add_subdirectory(${LIBS_DIRECTORY}/minizip-ng)

set(PROJECT_RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/resources/resources.rc")

set(PROJECT_SOURCES ${CORE_SOURCE} ${CORE_HEADERS} ${PROJECT_RESOURCES})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ViewerZIP MANUAL_FINALIZATION ${PROJECT_SOURCES})

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

#target_link_libraries(ViewerZIP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets minizip-ng)

target_link_libraries(ViewerZIP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets minizip)

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
