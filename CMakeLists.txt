# HelloWorld is a minimal sample creating, stepping and deleting a Bullet dynamics world

cmake_minimum_required(VERSION 2.8)

project(simulator_project)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

SET(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs")
SET(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs")
SET(GLFW_BUILD_DOCS OFF CACHE BOOL "Build the GLFW documentation")
SET(GLFW_INSTALL OFF CACHE BOOL "Generate installation target")
add_subdirectory(${PROJECT_SOURCE_DIR}/glfw)

add_subdirectory(${PROJECT_SOURCE_DIR}/assimp-3.1.1)

include_directories(${PROJECT_SOURCE_DIR}/glfw/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/bullet/src)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} src/sim.cpp)

add_library(BulletDynamics SHARED IMPORTED)
set_property(TARGET BulletDynamics PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/bullet/src/BulletDynamics/libBulletDynamics.a)

add_library(BulletCollision SHARED IMPORTED)
set_property(TARGET BulletCollision PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/bullet/src/BulletCollision/libBulletCollision.a)

add_library(LinearMath SHARED IMPORTED)
set_property(TARGET LinearMath PROPERTY IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/bullet/src/LinearMath/libLinearMath.a)

ADD_EXECUTABLE(simple src/simple.cpp)
add_executable(simple1 src/main.cpp)

target_link_libraries(simple ${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} BulletDynamics BulletCollision LinearMath)
target_link_libraries(simple1 glfw ${GLFW_LIBRARIES})
