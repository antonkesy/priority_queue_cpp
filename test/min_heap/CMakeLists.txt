include(GoogleTest)

set(suit_name min_binary_heap)

set(tests
        decrease_key.cpp
        get.cpp
        index_of.cpp
        pop.cpp
        push.cpp
        top.cpp
        )

foreach (file ${tests})
    set(test_name ${file}_test_${suit_name})
    add_executable(${test_name} ${file})
    target_link_libraries(${test_name} gtest_main)
    gtest_discover_tests(${test_name})
endforeach ()