include(GoogleTest)

set(suit_name min_priority_queue)

set(tests
        min_prio_q_decrease_key.cpp
        min_prio_q_get.cpp
        min_prio_q_pop.cpp
        min_prio_q_push.cpp
        min_prio_q_top.cpp
        )

foreach (file ${tests})
    set(test_name ${file}_test_${suit_name})
    add_executable(${test_name} ${file})
    target_link_libraries(${test_name} gtest_main)
    gtest_discover_tests(${test_name})
endforeach ()