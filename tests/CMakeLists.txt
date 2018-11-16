project(running_median_tests)

# Add the Catch header-only library
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE catch_2.4.2)

# Tests with manualy generated input and reference output
set(SOURCES_MANUAL
	tests_manual.cpp
)
add_executable(running_median_manual_tests ${SOURCES_MANUAL})
target_link_libraries(running_median_manual_tests Catch)
target_link_libraries(running_median_manual_tests running_median)

# Tests with randomly generated input and reference output generated using sort
set(SOURCES_RANDOMIZED
	tests_randomized.cpp
)
add_executable(running_median_randomized_tests  ${SOURCES_RANDOMIZED})
target_link_libraries(running_median_randomized_tests Catch)
target_link_libraries(running_median_randomized_tests running_median)

# Add the tests to the build
add_test(NAME running_median_manual_tests COMMAND running_median_manual_tests)
add_test(NAME running_median_randomized_tests COMMAND running_median_randomized_tests)
