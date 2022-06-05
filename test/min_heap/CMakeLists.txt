add_executable(test_decrease_key decrease_key.cpp)
add_test(decrease_key_test test_decrease_key)

add_executable(test_pop pop.cpp)
add_test(pop_test test_pop)


add_executable(test_push push.cpp ../utility/IntegerKey.hpp)
add_test(push_test test_push)

add_executable(test_top top.cpp ../utility/IntegerKey.hpp)
add_test(top_test test_top)

set_tests_properties(decrease_key_test pop_test push_test top_test PROPERTIES WILL_FAIL FALSE)