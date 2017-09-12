cmake_minimum_required(VERSION 3.0)

project(mugre)


set(binary_SOURCES
    src/mugre.cpp
)

link_directories(${PROJECT_SOURCE_DIR}/libraries/miniexp/build)

add_executable(mugre ${binary_SOURCES})

target_include_directories(mugre
    PUBLIC ${PROJECT_SOURCE_DIR}/libraries/miniexp/include
)

target_link_libraries(mugre
    PRIVATE miniexp
)

INSTALL(
    TARGETS mugre
    RUNTIME DESTINATION bin)