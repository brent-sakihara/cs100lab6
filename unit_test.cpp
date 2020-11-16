#include "gtest/gtest.h"
#include "vector_container_test.hpp"
#include "list_container_test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

