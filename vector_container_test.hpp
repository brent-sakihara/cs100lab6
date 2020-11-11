#ifndef VECTOR_CONTAINER_TEST_HPP
#define VECTOR_CONTAINER_TEST_HPP


#include "gtest/gtest.h"
#include "vector_container.hpp"
#include "container.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"
#include "sort.hpp"
#include "selection_sort.hpp"

TEST(vectorContainerTestSet, constructorTestNoParameters) {
    vectorContainer* test_container = new vectorContainer();
    EXPECT_EQ(test_container->getSortFunction(), nullptr);
};

TEST(vectorContainerTestSet, constructorTestWithParameter) {
    Sort* s = new selectionSort();
    vectorContainer* test_container = new vectorContainer(s);
    EXPECT_NE(test_container->getSortFunction(), nullptr);
}; 

TEST(vectorContainerTestSet, setSortFunctionWithSelectionSort) {
    vectorContainer* test_container = new vectorContainer();
    test_container->set_sort_function(new selectionSort());
    EXPECT_NE(test_container->getSortFunction(), nullptr);
};

TEST(vectorContainerTestSet, setSortFunctionWithNullptr) {
    vectorContainer* test_container = new vectorContainer();
    test_container->set_sort_function(nullptr);
    EXPECT_EQ(test_container->getSortFunction(), nullptr);
};


TEST(vectorContainerTestSet, addSmallElement) {
    // Setup the elements under test
    Op* seven = new Op(7);
    vectorContainer* test_container = new vectorContainer();
    
    //Exercise some functionality of hte test elements
    test_container->add_element(seven);

    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 1);
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
};

TEST(vectorContainerTestSet, addLargeElements) {
    Op* thirty = new Op(30);
    Op* forty = new Op(40);
    vectorContainer* test_container = new vectorContainer();
    test_container->add_element(thirty);
    test_container->add_element(forty);
    ASSERT_EQ(test_container->size(), 2);
    EXPECT_EQ(test_container->at(0)->evaluate(), 30);
};

TEST(vectorContainerTestSet, printOneElement) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);
   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(product);
   test_container->print();
   EXPECT_EQ(test_container->getTotalExpression(), "(8.000000 * 12.000000)");
};

TEST(vectorContainerTestSet, printThreeElements) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);
   
   Op* five = new Op(5);
   Op* negFour = new Op(-4);
   Div* quotient = new Div(five, negFour);

   Op* zero = new Op(0);
   Op* forty = new Op(40);
   Pow* result = new Pow(zero, forty);

   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(product);
   test_container->add_element(quotient);
   test_container->add_element(result);
   test_container->print();
   EXPECT_EQ(test_container->getTotalExpression(), ("(8.000000 * 12.000000)(5.000000 / -4.000000)(0.000000 ** 40.000000)"));
};

TEST(vectorContainerTestSet, validSwap) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);
   Op* five = new Op(5);
   Add* sum1 = new Add(product, five);

   Op* two = new Op(2);
   Op* negThirteen = new Op(-13);
   Add* sum2 = new Add(two, negThirteen);

   Op* four = new Op(4);
   Op* one = new Op(1);
   Div* quotient = new Div(four, one);

   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(sum1);
   test_container->add_element(sum2);
   test_container->add_element(quotient);
   test_container->swap(0, 2);

   EXPECT_EQ(test_container->at(0)->stringify(), "(4.000000 / 1.000000)");
   EXPECT_EQ(test_container->at(2)->stringify(), "((8.000000 * 12.000000) + 5.000000)");
};

TEST(vectorContainerTestSet, invalidSwap) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);

   Op* negFive = new Op(-5);
   Op* one = new Op(1);
   Pow* power = new Pow(negFive, one);

   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(product);
   test_container->add_element(power);
   EXPECT_THROW(test_container->swap(0, 4), out_of_range);
};

TEST(vectorContainerTestSet, validAt) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);

   Op* negFive = new Op(-5);
   Op* one = new Op(1);
   Pow* power = new Pow(negFive, one);

   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(product);
   test_container->add_element(power);
   EXPECT_EQ(test_container->at(1)->evaluate(), -5);
};

TEST(vectorContainerTestSet, invalidAt) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);

   Op* negFive = new Op(-5);
   Op* one = new Op(1);
   Pow* power = new Pow(negFive, one);

   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(product);
   test_container->add_element(power);
   EXPECT_THROW(test_container->at(-1)->evaluate(), out_of_range);
};

TEST(vectorContainerTestSet, sizeThree) {
   Op* eight = new Op(8);
   Op* twelve = new Op(12);
   Mult* product = new Mult(eight, twelve);
   Op* five = new Op(5);
   Add* sum1 = new Add(product, five);

   Op* two = new Op(2);
   Op* negThirteen = new Op(-13);
   Add* sum2 = new Add(two, negThirteen);

   Op* four = new Op(4);
   Op* one = new Op(1);
   Div* quotient = new Div(four, one);

   vectorContainer* test_container = new vectorContainer();
   test_container->add_element(sum1);
   test_container->add_element(sum2);
   test_container->add_element(quotient);

   EXPECT_EQ(test_container->size(), 3);
};

TEST(vectorContainerTestSet, sizeZero) {

   vectorContainer* test_container = new vectorContainer();

   EXPECT_EQ(test_container->size(), 0);
};



#endif
