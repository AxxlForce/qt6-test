cmake_minimum_required(VERSION 3.18...3.18)

project(qt6-lib CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Qml Quick QuickControls2 QmlImportScanner)

qt_add_qml_module(qt6-lib
  STATIC
  URI com.mycompany.test
  VERSION 1.0
  PLUGIN_TARGET qt6-plugin
  SOURCES
    thing.cpp
    thing.hpp
  QML_FILES
    FancyComponent.qml
    )

get_target_property(test qt6-lib_qmlcache SOURCES)

message("${test}")

target_compile_features(qt6-lib PUBLIC cxx_std_17)

target_link_libraries(qt6-lib
  PRIVATE
    Qt6::Qml
    Qt6::Quick)

