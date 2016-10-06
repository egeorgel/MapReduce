include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runMapReduceTests
        MapperTest.cpp
        ReducerTest.cpp
        StringComputer.cpp
        MapReduceTest.cpp)

target_link_libraries(runMapReduceTests gtest gtest_main)
target_link_libraries(runMapReduceTests mapReduce_src)
