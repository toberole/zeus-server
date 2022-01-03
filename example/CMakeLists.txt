cmake_minimum_required(VERSION 3.10.2)

project("example")

include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src EXAMPLE_SRC_FILES)

add_executable(example ${EXAMPLE_SRC_FILES})

target_link_libraries(example
        pthread
)