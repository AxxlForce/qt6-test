cmake_minimum_required(VERSION 3.18...3.18)

project(qt6-app CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 REQUIRED COMPONENTS Core Qml Quick QuickControls2 QmlImportScanner)

qt_add_resources(QT_RESOURCES qml.qrc)

qt_add_executable(qt6-app src/main.cpp ${QT_RESOURCES}
    src/singleton.hpp)

target_include_directories(
    qt6-app PRIVATE src)

target_link_libraries(qt6-app
  PRIVATE
    Qt6::Qml
    Qt6::Quick
    qt6-lib
    qt6-plugin
    qt6-plugin_init
  )

set_target_properties(qt6-app PROPERTIES
    QT_QML_MODULE_VERSION 1.0
    QT_QML_MODULE_URI Qt6App)

qt6_qml_type_registration(qt6-app)
