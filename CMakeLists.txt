cmake_minimum_required(VERSION 3.18...3.18)

set(CMAKE_AUTOMOC ON)

# Directories where Qt Creator can find QML files.
# (Not needed for builds, but makes Qt Creator code completion happy.)
list(APPEND QML_IMPORT_PATH "${CMAKE_SOURCE_DIR}")

# Prevent adding duplicate values at each run of CMake.
list(REMOVE_DUPLICATES QML_IMPORT_PATH)

# The variable is cached in ${BUILD_DIR}/CMakeCache.txt. We need FORCE to
# change it there immediately. Also, add a comment to the cache file.
set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
    CACHE STRING "additional qml import paths"
    FORCE)

message("${QML_IMPORT_PATH}")

project(qt6-app CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Qml Quick QuickControls2 QmlImportScanner Widgets)

qt_add_resources(QT_RESOURCES main/qml.qrc)

add_executable(qt6-app main/main.cpp ${QT_RESOURCES})

target_include_directories(
    qt6-app PRIVATE src)

target_link_libraries(qt6-app
    PRIVATE
    Qt6::Widgets
    Qt6::Qml
    Qt6::Quick)

set_target_properties(qt6-app PROPERTIES
    QT_QML_MODULE_VERSION 1.0
    QT_QML_MODULE_URI Qt6App)

qt6_qml_type_registration(qt6-app)
