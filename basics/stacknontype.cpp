#include "stacknontype.hpp"
#include <iostream>
#include <string>

using namespace std;

int
main()
{
    Stack<int, 20> int20Stack;      // stack of up to 20 ints.
    Stack<int, 40> int40Stack;      // stack of up to 40 ints.
    Stack<string, 40> stringStack;  // stack of up to 40 strings.

    // manipulate stack of up to 20 ints.
    int20Stack.push(7);
    cout << "Top element of int20Stack: " << int20Stack.top() << endl;
    int20Stack.pop();

    // manipulate stack of up to 40 strings.
    stringStack.push("Hello");
    cout << "Top element of stringStack: " << stringStack.top() << endl;
    stringStack.pop();

    return 0;
}