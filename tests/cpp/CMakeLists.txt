find_package(GTest QUIET)

if(GTest_FOUND)
    enable_testing()

    file(GLOB_RECURSE BLOCKTORCH_TEST_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
    )

    add_executable(blocktorch_tests ${BLOCKTORCH_TEST_SOURCES})

    target_link_libraries(blocktorch_tests PRIVATE
        blocktorch_core
        GTest::gtest_main
    )

    include(GoogleTest)
    gtest_discover_tests(blocktorch_tests)
endif()
