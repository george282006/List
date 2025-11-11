add_executable(test_main
        test_main.cpp
        test_list.cpp
)

target_include_directories(test_main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/LIst/include
        ${CMAKE_SOURCE_DIR}/LIst/gtest
)
target_link_libraries(test_main gtest list_includes)

add_test(NAME test_main COMMAND test_main)