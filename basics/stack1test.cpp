#include "stack1.hpp"
#include <iostream>
#include <string>

using namespace std;

// Solution 2: Define the operator<< for Stack<T> as a non-member function in the cpp file.
template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s)
{
    s.printOn(os);
    return os;
}

int
main()
{
    Stack<int> intStack;  // stack of ints.
    Stack<string> stringStack;  // stack of strings.

    intStack.push(7);
    intStack.push(42);
    cout << "Top element of intStack: " << intStack.top() << endl;

    stringStack.push("Hello");
    cout << "Top element of stringStack: " << stringStack.top() << endl;

    stringStack.pop();
    cout << "Print intStack using operator<<: " << intStack << endl;  // Print intStack by using operator<<.

    Stack<pair<int, int>> pairStack; // note: std::pair is has no operator<< defined.
    pairStack.push({1, 2});             // OK
    pairStack.push({3, 4});             // OK
    cout << "Top element of pairStack: " << pairStack.top().first << ", " << pairStack.top().second << endl; // OK
    //pairStack.printOn(cout);            // ERROR: operator<< not supported for element type.
    return 0;
}

void
foo(const Stack<int>& s) // parameter s is int stack.
{
    using IntStack = Stack<int>;  // IntStack is another name for Stack<int>.
    Stack<int> istack[10];  // istack is array of 10 int stacks.
    IntStack istack2[10];  // istack2 is also array of 10 int stacks (same type).
    Stack<Stack<int>> intStackStack;  // ERROR before c++11.
}