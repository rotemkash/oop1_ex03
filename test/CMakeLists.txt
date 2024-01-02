file (GLOB MY_SOURCE_FILES CONFIGURE_DEPENDS LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
target_sources (tests PRIVATE ${MY_SOURCE_FILES})

target_link_libraries (tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries (tests PRIVATE obj)
