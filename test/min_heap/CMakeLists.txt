include(GoogleTest)

set(suit_name min_binary_heap)

set(tests
        min_heap_decrease_key.cpp
        min_heap_get.cpp
        min_heap_indexof.cpp
        min_heap_pop.cpp
        min_heap_push.cpp
        min_heap_top.cpp
        )

foreach (file ${tests})
    set(test_name ${file}_test_${suit_name})
    add_executable(${test_name} ${file})
    target_link_libraries(${test_name} gtest_main)
    gtest_discover_tests(${test_name})
endforeach ()