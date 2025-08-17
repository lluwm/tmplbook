#include "stack3.hpp"
#include <iostream>
#include <deque>

using namespace std;

int
main()
{
    // stack of ints.
    Stack<int> intStack;

    // stack of doubles using a std::deque<> to manage the elements.
    Stack<double, deque<double>> doubleStack;

    // manipulate int stack.
    intStack.push(7);
    cout << intStack.top() << endl;  // should print 7
    intStack.pop();

    // manipulate double stack.
    doubleStack.push(3.14);
    cout << doubleStack.top() << endl;  // should print 3.14
    doubleStack.pop();
}