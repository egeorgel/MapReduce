cmake_minimum_required(VERSION 3.6)
project(MapReduce)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
add_executable(mapReduce_run ${SOURCE_FILES})

find_package(Boost 1.57.0 COMPONENTS system filesystem REQUIRED)
if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(BoostTest main.cpp)
if(Boost_FOUND)
    target_link_libraries(BoostTest ${Boost_LIBRARIES})
endif()

include_directories(mapReduce_src)

add_subdirectory(mapReduce_src)
add_subdirectory(mapReduce_test)

target_link_libraries(mapReduce_run mapReduce_src)