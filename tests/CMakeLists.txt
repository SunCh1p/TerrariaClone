

file(GLOB_RECURSE TESTSOURCES "${PROJECT_SOURCE_DIR}/tests/*.cc")
add_executable(tests ${TESTSOURCES})
target_link_libraries(tests PRIVATE TerrariaCore Catch2::Catch2WithMain)
catch_discover_tests(tests)

# add_test(TerrariaCloneTests tests)
