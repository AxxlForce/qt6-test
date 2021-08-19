cmake_minimum_required(VERSION 3.18...3.18)

project(qt6-test CXX)

# Directories where Qt Creator can find QML files.
# (Not needed for builds, but makes Qt Creator code completion happy.)
 list(APPEND QML_IMPORT_PATH "cmake-build-debug/lib")

# Prevent adding duplicate values at each run of CMake.
 list(REMOVE_DUPLICATES QML_IMPORT_PATH)

# The variable is cached in ${BUILD_DIR}/CMakeCache.txt. We need FORCE to
# change it there immediately. Also, add a comment to the cache file.
set(QML_IMPORT_PATH ${QML_IMPORT_PATH}
    CACHE STRING "additional qml import paths"
    FORCE)

add_subdirectory(lib)
add_subdirectory(app)
