cmake_minimum_required (VERSION 3.23)

project (oop1_ex03)
set (MY_AUTHORS "your_name_here")

include (cmake/CompilerSettings.cmake)

add_executable (${CMAKE_PROJECT_NAME})
add_library (obj STATIC)
target_link_libraries (${CMAKE_PROJECT_NAME} PRIVATE obj)

target_compile_options(obj PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)
target_link_options(obj PRIVATE $<$<CONFIG:DEBUG>:-fsanitize=address>)

add_subdirectory (include)
add_subdirectory (src)

include (cmake/Zip.cmake)

add_subdirectory (external/catch2)

add_executable (tests)
add_subdirectory (test)

include (CTest)
include (Catch)
catch_discover_tests(tests)
