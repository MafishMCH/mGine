cmake_minimum_required (VERSION 3.0)
set(CMAKE_BUILD_TYPE Debug)

# Below line is for using C++14 standard
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Our project name
project (mgine)

file(GLOB src "src/*.cpp")
file(GLOB engine_src ${PROJECT_SOURCE_DIR}/mgine/mgine.cpp ${PROJECT_SOURCE_DIR}/mgine/basic/*.cpp ${PROJECT_SOURCE_DIR}/mgine/debug/*.cpp )
add_executable(${PROJECT_NAME} ${src} ${engine_src})

find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image SDL2_ttf)

install(
    DIRECTORY "${PROJECT_SOURCE_DIR}/content"
    DESTINATION ${PROJECT_BINARY_DIR}
)
