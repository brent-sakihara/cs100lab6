#ifndef __CONTAINER_TEST_HPP__
#define __CONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"
#include "container.hpp"
#include "listcontainer.hpp"
#include "sort.hpp"
#include "bubblesort.hpp"

TEST(ListContainerTest, constructor) {
    ListContainer* test = new ListContainer();
    EXPECT_EQ(test->get_sort_function(), nullptr);
}

TEST(ListContainerTest, Paramconstructor) {
    Sort* sorter = new BubbleSort();
    ListContainer* test = new ListContainer(sorter);
    EXPECT_EQ(test->get_sort_function(), sorter);
}

TEST(ListContainerTest, setSort) {
    Sort* sorter = new BubbleSort();
    ListContainer* test = new ListContainer();
    test->set_sort_function(sorter);
    EXPECT_EQ(test->get_sort_function(), sorter);
}

TEST(ListContainerTest, setSortnull) {
    Sort* sorter = nullptr;
    ListContainer* test = new ListContainer();
    test->set_sort_function(sorter);
    EXPECT_EQ(test->get_sort_function(), nullptr);
}

TEST(ListContainerTest, addElementsize) {
    Sort* sorter = new BubbleSort();
    Op* twenty = new Op(20);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(twenty);
    EXPECT_EQ(test->size(), 1);
}

TEST(ListContainerTest, addElementat) {
    Sort* sorter = new BubbleSort();
    Op* two = new Op (2);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(two);
    EXPECT_EQ(test->at(0)->evaluate(), 2);
}

TEST(ListContainerTest, addElementsizeat) {
    Sort* sorter = new BubbleSort();
    Op* two = new Op (2);
    Op* four = new Op(4);
    Add* sum = new Add(two, four);
    Op* ten = new Op(10);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(sum);
    test->add_element(ten);
    EXPECT_EQ(test->at(0)->evaluate(), 6);
    EXPECT_EQ(test->at(1)->evaluate(), 10);
    EXPECT_EQ(test->size(), 2);
}

TEST(ListContainerTest, swapping) {
    Sort* sorter = new BubbleSort();
    Op* nine = new Op (9);
    Op* six = new Op(6);
    Add* sum = new Add(nine, six);
    Op* ten = new Op(10);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(sum);
    test->add_element(ten);
    EXPECT_EQ(test->at(0)->stringify(), "(9.000000 + 6.000000)");
    test->swap(0,1);
    EXPECT_EQ(test->size(), 2);
    EXPECT_EQ(test->at(0)->stringify(), "10.000000");
}

TEST(ListContainerTest, swapping2) {
    Sort* sorter = new BubbleSort();
    Op* nine = new Op (9);
    Op* six = new Op(6);
    Add* sum = new Add(nine, six);
    Op* ten = new Op(10);
    Op* one = new Op(1);
    Mult* m = new Mult(ten,one);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(sum);
    test->add_element(m);
    EXPECT_EQ(test->at(1)->stringify(), "(10.000000 * 1.000000)");
    test->swap(0,1);
    EXPECT_EQ(test->size(), 2);
    EXPECT_EQ(test->at(0)->stringify(), "(10.000000 * 1.000000)");
}

TEST(ListContainerTest, atEvaluate) {
    Sort* sorter = new BubbleSort();
    Op* five = new Op (5);
    Op* six = new Op(6);
    Add* sum = new Add(five, six);
    Op* fourteen = new Op(14);
    Op* two = new Op(2);
    Mult* m = new Mult(fourteen,two);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(sum);
    test->add_element(m);
    EXPECT_EQ(test->at(1)->evaluate(), 28);
    test->swap(0,1);
    EXPECT_EQ(test->at(1)->evaluate(), 11);
}

TEST(ListContainerTest, atStringify) {
    Sort* sorter = new BubbleSort();
    Op* nine = new Op (9);
    Op* five = new Op(5);
    Sub* dif = new Sub(nine, five);
    Op* sixteen = new Op(16);
    Op* four = new Op(4);
    Div* divv = new Div(sixteen,four);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(dif);
    test->add_element(divv);
    EXPECT_EQ(test->at(1)->stringify(), "(16.000000 / 4.000000)");
    test->swap(0,1);
    test->print();
    EXPECT_EQ(test->at(1)->stringify(), "(9.000000 - 5.000000)");
}

TEST(ListContainerTest, sizee) {
    Sort* sorter = new BubbleSort();
    Op* nine = new Op (9);
    Op* five = new Op(5);
    Sub* dif = new Sub(nine, five);
    Op* sixteen = new Op(16);
    Op* four = new Op(4);
    Div* divv = new Div(sixteen,four);
    ListContainer* test = new ListContainer(sorter);
    test->add_element(dif);
    test->add_element(divv);
    EXPECT_EQ(test->size(), 2);
    test->swap(0,1);
    EXPECT_EQ(test->size(), 2);
    Op* num = new Op(90);
    test->add_element(num);
    test->print();
    EXPECT_EQ(test->size(), 3);
}

TEST(ListContainerTest, zerosize) {
    ListContainer* test = new ListContainer();
    EXPECT_EQ(test->size(), 0);
    Op* one = new Op(1);
    test->add_element(one);
    EXPECT_EQ(test->size(), 1);
}

TEST(ListContainerTest, sortruntime) {
    ListContainer* test = new ListContainer();
    EXPECT_EQ(test->size(), 0);
    Op* one = new Op(1);
    test->add_element(one);
    EXPECT_EQ(test->size(), 1);
    EXPECT_EQ(test->at(0)->stringify(), "1.000000");
    EXPECT_THROW(test->sort(), std::runtime_error);
}

TEST(ListContainerTest, sortOne) {
	ListContainer* test = new ListContainer();
	Sort * sorter = new BubbleSort();
	Op* one = new Op(1);
	test->add_element(one);
	test->set_sort_function(sorter);
	test->sort();
	EXPECT_EQ(test->at(0), one);
}

TEST(ListContainerTest, sortTwo) {
        ListContainer* test = new ListContainer();
        Sort * sorter = new BubbleSort();
        Op* one = new Op(1);
	Op* two = new Op(2);
        test->add_element(one);
        test->set_sort_function(sorter);
        test->sort();
	test->add_element(two);
        EXPECT_EQ(test->at(0), one);
	EXPECT_EQ(test->at(1), two);
}

TEST(ListContainerTest, sortThree) {
        ListContainer* test = new ListContainer();
        Sort * sorter = new BubbleSort();
        Op* one = new Op(1);
        Op* two = new Op(2);
	Op* three = new Op(3);
        test->add_element(three);
	test->add_element(one);
        test->set_sort_function(sorter);
        test->sort();
	EXPECT_EQ(test->at(0), one);
	EXPECT_EQ(test->at(1), three);
        test->add_element(two);
	test->sort();
        EXPECT_EQ(test->at(0), one);
        EXPECT_EQ(test->at(2), three);
}

TEST(ListContainerTest, sortTree) {
        ListContainer* test = new ListContainer();
        Sort * sorter = new BubbleSort();
        Op* one = new Op(1);
        Op* two = new Op(2);
	Mult* m = new Mult(one, two);
	Op* onetoo = new Op(1);
        Op* three = new Op(3);
        test->add_element(three);
        test->add_element(onetoo);
	test->add_element(m);
	EXPECT_EQ(test->at(2), m);
        test->set_sort_function(sorter);
        test->sort();
        EXPECT_EQ(test->at(0), onetoo);
        EXPECT_EQ(test->at(1), m);
        EXPECT_EQ(test->at(2), three);
}

TEST(ListContainerTest, sortTrees) {
        ListContainer* test = new ListContainer();
        Sort * sorter = new BubbleSort();
        Op* one = new Op(1);
        Op* three = new Op(3);
        Mult* m = new Mult(one, three);
        Op* eight = new Op(8);
        Op* two = new Op(2);
	Div* d = new Div(eight, two);
        test->add_element(m);
	test->add_element(one);
	EXPECT_EQ(test->at(0), m);
        EXPECT_EQ(test->at(1), one);
        test->set_sort_function(sorter);
	test->add_element(d);
        test->sort();
        EXPECT_EQ(test->at(0), one);
        EXPECT_EQ(test->at(1), m);
        EXPECT_EQ(test->at(2), d);
}

TEST(ListContainerTest, sortTreesTwo) {
        ListContainer* test = new ListContainer();
        Sort * sorter = new BubbleSort();
	test->set_sort_function(sorter);
        Op* five = new Op(5);
        Op* three = new Op(3);
        Mult* m = new Mult(five, three);
        Op* eight = new Op(8);
	Sub* s = new Sub(m,eight);
        Op* two = new Op(2);
        Div* d = new Div(eight, two);
        test->add_element(m);
        test->add_element(s);
        EXPECT_EQ(test->at(0), m);
        EXPECT_EQ(test->at(1), s);
        test->sort();
        EXPECT_EQ(test->at(0), s);
        EXPECT_EQ(test->at(1), m);
	test->add_element(d);
        EXPECT_EQ(test->at(2), d);
	test->sort();
	EXPECT_EQ(test->at(0), d);
}

TEST(ListContainerTest, sortTreesThree) {
        ListContainer* test = new ListContainer();
        Sort * sorter = new BubbleSort();
        test->set_sort_function(sorter);
        Op* one = new Op(1);
        Op* six = new Op(6);
        Add* a = new Add(one, six);
        Op* nine = new Op(9);
        Op* two = new Op(2);
        Div* d = new Div(two, one);
        test->add_element(a);
        test->add_element(d);
        EXPECT_EQ(test->at(0), a);
        EXPECT_EQ(test->at(1), d);
	Pow* p = new Pow(a, d);
	test->add_element(p);
        test->sort();
        EXPECT_EQ(test->at(0), d);
        EXPECT_EQ(test->at(1), a);
        EXPECT_EQ(test->at(2), p);
}

TEST(ListContainerTest, sortTreeRand) {
	ListContainer* test = new ListContainer();
	Sort* sorter = new BubbleSort();
	test->set_sort_function(sorter);
	Rand* r = new Rand();
	test->add_element(r);
	EXPECT_EQ(test->at(0), r);
	Op* hundred = new Op(100);
	test->add_element(hundred);
	test->sort();
	EXPECT_EQ(test->at(1), hundred);
}
/*
TEST(ListContainerTest, sortTreesTwo) {
        vectorContainer* test = new vectorContainer();
        Sort * sorter = new BubbleSort();
        Op* one = new Op(1);
        Op* three = new Op(3);
        Mult* m = new Mult(one, three);
        Op* eight = new Op(8);
        Op* two = new Op(2);
        Div* d = new Div(eight, two);
        test->add_element(m);
        test->add_element(one);
        EXPECT_EQ(test->at(0), m);
        EXPECT_EQ(test->at(1), one);
        test->set_sort_function(sorter);
        test->add_element(d);
        test->sort();
        EXPECT_EQ(test->at(0), one);
        EXPECT_EQ(test->at(1), m);
        EXPECT_EQ(test->at(2), d);
}

TEST(ListContainerTest, sortTreeRandTwo) {
        vectorContainer* test = new vectorContainer();
        Sort* sorter = new BubbleSort();
        test->set_sort_function(sorter);
        Rand* r = new Rand();
        test->add_element(r);
        EXPECT_EQ(test->at(0), r);
        Op* hundred = new Op(100);
        test->add_element(hundred);
        test->sort();
        EXPECT_EQ(test->at(1), hundred);
}

*/

#endif
