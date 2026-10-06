cmake_minimum_required(VERSION 3.24)
project(mahjong)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        mahjong_tests
        tests/ShantenCalculatorTest.cpp
        src/Hand.cpp
        src/Tile.cpp
        src/ShantenCalculator.cpp
)

target_link_libraries(
        mahjong_tests
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(mahjong_tests)