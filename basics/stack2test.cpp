#include "stack2.hpp"
#include <iostream>
#include <string>

using namespace std;


int
main()
{
    Stack<string> stringStack;  // stack of strings.

    stringStack.push("Hello");
    cout << "Top element of stringStack: " << stringStack.top() << endl;

    return 0;
}