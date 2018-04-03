
# Now simply link against gtest or gtest_main as needed. Eg
add_executable(app app.cpp)
target_link_libraries(app gtest_main)
add_test(NAME app_test COMMAND app)
