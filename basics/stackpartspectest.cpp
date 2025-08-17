#include "stackpartspec.hpp"
#include <iostream>

using namespace std;

int
main()
{
    Stack<int *> intPtrStack;  // stack of int pointers.
    intPtrStack.push(new int(42));
    cout << "Top element of intPtrStack: " << *intPtrStack.top() << endl;
    delete intPtrStack.pop();
    return 0;
}