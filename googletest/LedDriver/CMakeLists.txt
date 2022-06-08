cmake_minimum_required(VERSION 3.14)
project(LedDriver)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/0320f517fd920866d918e564105d68fd4362040a.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  LedDriver
  LedDriverTest.cpp
)
target_link_libraries(
  LedDriver
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(LedDriver)
