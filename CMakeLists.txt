cmake_minimum_required(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	unit_test.cpp
	vector_container.cpp
	selection_sort.cpp
	add.cpp
	sub.cpp
	mult.cpp
	div.cpp
	op.cpp
	pow.cpp
	rand.cpp
)

TARGET_LINK_LIBRARIES(test  gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
