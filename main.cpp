#include <iostream>
using namespace std;
#include "base.hpp"
#include "op.hpp"
#include "pow.hpp"
#include "arithmetic_operations.hpp"
#include "sort.hpp"
#include "bubblesort.hpp"
#include "selection_sort.hpp"
#include "listcontainer.hpp"
#include "vector_container.hpp"

int main() {
    // This is a very basic main, and being able to correctly execute this main
    // does not constitute a completed lab. Make sure you write unit tests for
    // all the classes that you create (and can be instantiated) in this lab
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* one = new Op(1);
    Base* six = new Op(6);
    Base* negone = new Op(-1);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);
    
    Base* div = new Div(four,two);
    Base* pow = new Pow(div, three);
    Base* addtwo = new Add(pow, one);

    Base* multtwo = new Mult(seven, one);
    Base* minustwo = new Sub(six, three);
    Base* powtwo = new Pow(multtwo, minustwo);

    Base* divtwo = new Div(seven, one);
    Base* addthree = new Add(four, divtwo);
    Base* mthree = new Sub(addthree, three);

    selectionSort* s = new selectionSort();
    ListContainer* l = new ListContainer(s);
    BubbleSort* b = new BubbleSort();
    vectorContainer* v = new vectorContainer();
    v->set_sort_function(b);
    l->add_element(minus);
    l->add_element(addtwo);
    l->add_element(negone);
    v->add_element(powtwo);
    v->add_element(mthree);
    v->add_element(six);
    
    cout << "first tree: " << endl;
    l->print();
    for (int i = 0; i < l->size(); i++){
        cout << l->at(i)->evaluate() << " ";
    }
    cout << endl << endl;

    cout << "second tree: " << endl;
    v->print();
    for (int i = 0; i < v->size(); i++){
        cout << v->at(i)->evaluate() << " ";
    }
    cout << endl << endl;


    l->sort();
    v->sort();

    cout << "first tree sorted: " << endl;
    l->print();
    for (int i = 0; i < l->size(); i++){
        cout << l->at(i)->evaluate() << " ";
    }
    cout << endl << endl;

    cout << "second tree sorted: " << endl;
    v->print();
    for (int i = 0; i < v->size(); i++){
        cout << v->at(i)->evaluate() << " ";
    }
    cout << endl << endl;

//    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    return 0;
}
