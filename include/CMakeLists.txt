add_library(list_includes INTERFACE list.h)
target_include_directories(list_includes INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})