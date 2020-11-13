
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
	unit_test.cpp
	op.cpp
	rand.cpp
	pow.cpp
	mult.cpp
	div.cpp
	add.cpp
	sub.cpp
	listcontainer.cpp
	bubblesort.cpp
)

TARGET_LINK_LIBRARIES(test  gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
