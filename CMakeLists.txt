cmake_minimum_required(VERSION 3.28)
project(Test_CPP_Boost)

set(CMAKE_CXX_STANDARD 17)

# Specify the path to the Boost installation
set(BOOST_ROOT "/usr/local")

# Find the Boost libraries
find_package(Boost 1.82.0 REQUIRED)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(Test_CPP_Boost Test_Link_HeadOnly.cpp)

# Link Boost libraries (if needed, you can specify which libraries you need)
target_link_libraries(Test_CPP_Boost ${Boost_LIBRARIES})

add_executable(Test_Link_LibBinary Test_Link_LibBinary.cpp)

target_link_libraries(Test_Link_LibBinary ${Boost_LIBRARIES})

add_executable(Timer1 Timer1.cpp Timer1.h)

target_link_libraries(Timer1 ${Boost_LIBRARIES})

add_executable(Timer2 Timer2.cpp Timer2.h)

target_link_libraries(Timer2 ${Boost_LIBRARIES})


add_executable(Timer3 Timer3.cpp Timer3.h)
