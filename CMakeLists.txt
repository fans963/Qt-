cmake_minimum_required(VERSION 3.16)

project(doudizhu VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "D:/Qt/6.7.2/mingw_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp



        include/ElaWidgetTools.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(doudizhu
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        cards.h cards.cpp
        card.h card.cpp
        cardpanel.h cardpanel.cpp
        player.h player.cpp
        gamecontrol.h gamecontrol.cpp
        robot.h robot.cpp
        userplayer.h userplayer.cpp
        playhand.h playhand.cpp
        strategy.h strategy.cpp
        robotgraplord.h robotgraplord.cpp
        robotplayhand.h robotplayhand.cpp
        animationwindow.h animationwindow.cpp
        countdown.h countdown.cpp
        gamepanel.h gamepanel.cpp gamepanel.ui
        loading.h loading.cpp
        buttongroup.h buttongroup.cpp buttongroup.ui
        scorepanel.h scorepanel.cpp scorepanel.ui
        endingpanel.h endingpanel.cpp
        mybutton.h mybutton.cpp
        resource.rcc
        res.qrc



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET doudizhu APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(doudizhu SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(doudizhu
            ${PROJECT_SOURCES}
        )
    endif()
endif()

include_directories(
    include
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(doudizhu PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    # ${CMAKE_CURRENT_SOURCE_DIR}/lib/elawidgettools.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/libelawidgettools.a
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.doudizhu)
endif()
set_target_properties(doudizhu PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS doudizhu
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(doudizhu)
endif()
