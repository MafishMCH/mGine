cmake_minimum_required (VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

# Below line is for using C++14 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Our project name
project (framework)

file(GLOB src "src/*.cpp")
file(GLOB engine_src ${PROJECT_SOURCE_DIR}/engine/framework.cpp ${PROJECT_SOURCE_DIR}/engine/basic/*.cpp)
add_executable(${PROJECT_NAME} ${src} ${engine_src})

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/content"
    DESTINATION ${PROJECT_BINARY_DIR}
)
# # For finding our SDL2 package!
# INCLUDE(FindPkgConfig)

# # Searching SDL2 package.
# PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# # Including our external library's directory for header files!
# INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})

# # Linking SDL2 library with our project.
# target_link_libraries(framework ${SDL2_LIBRARIES})