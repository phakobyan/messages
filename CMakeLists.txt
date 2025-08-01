cmake_minimum_required(VERSION 3.16)

project(Messages VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        messages.cpp
        messages.h
        messages.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Messages
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Messages APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Messages SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        find_package(Qt5 REQUIRED COMPONENTS Widgets)

        add_executable(Messages
            ${PROJECT_SOURCES}
            viewanswersdialogue.h viewanswersdialogue.cpp viewanswersdialogue.ui
            payment_arca.h
            payment_arca.cpp payment_arca.ui
            resources.qrc
            login.h
            login.cpp login.ui
            firstwindow.h
            firstwindow.cpp firstwindow.ui
            reserve.h
            reserve.cpp reserve.ui
            creditcard.h
            creditcard.cpp
            room.h
            room.cpp
            standardroom.h
            standardroom.cpp
            premiumroom.h
            premiumroom.cpp
            luxuryroom.h
            luxuryroom.cpp
            selectdate.h
            selectdate.cpp selectdate.ui
            dbmanager.h
            dbmanager.cpp








        )
    endif()
endif()

target_link_libraries(Messages PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Messages PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(Messages PRIVATE Qt5::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Messages)
endif()
set_target_properties(Messages PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Messages
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Messages)
endif()

