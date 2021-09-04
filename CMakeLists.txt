cmake_minimum_required(VERSION 3.16)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

project(SudokuValidator VERSION 1.0)

add_library(SudokuValidatorLib headers/SudokuValidator/SudokuValidator.h sources/SudokuValidator.cpp)
target_compile_features(SudokuValidatorLib PRIVATE cxx_std_17)
target_compile_options(SudokuValidatorLib PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_include_directories(SudokuValidatorLib PUBLIC headers)

add_executable(SudokuValidator main.cpp)
target_compile_features(SudokuValidator PRIVATE cxx_std_17)
target_compile_options(SudokuValidator PRIVATE
  $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
  $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)
target_link_libraries(SudokuValidator PRIVATE
  SudokuValidatorLib
)


enable_testing()
add_executable(
  SudokuValidatorTest
  test/Test.cpp
)
target_link_libraries(SudokuValidatorTest PRIVATE
  gtest_main
  SudokuValidatorLib
)
include(GoogleTest)
gtest_discover_tests(SudokuValidatorTest)
