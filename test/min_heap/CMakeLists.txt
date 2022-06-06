add_executable(test_decrease_key decrease_key.cpp)
add_test(decrease_key_test test_decrease_key)

add_executable(test_pop pop.cpp)
add_test(pop_test test_pop)

add_executable(test_push push.cpp)
add_test(push_test test_push)

add_executable(test_top top.cpp)
add_test(top_test test_top)

add_executable(test_get get.cpp)
add_test(get_test test_get)

add_executable(test_indexof indexof.cpp)
add_test(indexof_test test_indexof)


set_tests_properties(decrease_key_test pop_test push_test top_test get_test indexof_test PROPERTIES WILL_FAIL FALSE)