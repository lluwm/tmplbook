#include <iostream>
#include <deque>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::deque<T> elems;    // elements.

public:
    void push(const T& item);
    T pop();

    bool isEmpty() const {
        return elems.empty();
    }

    // assign stack of elements of type T2
    template <typename T2>
    Stack& operator=(const Stack<T2>& other);

    // to get access to private members of Stack<T2> for any type T2
    template<typename> friend class Stack;
};

template <typename T>
void Stack<T>::push(const T& item) {
    elems.push_back(item);
}

template <typename T>
T Stack<T>::pop() {
    if (elems.empty()) throw std::out_of_range("Stack<>::pop(): empty stack");
    T elem = elems.back();
    elems.pop_back();
    return elem;
}

template <typename T>
template <typename T2>
Stack<T>& Stack<T>::operator=(const Stack<T2>& other) {
    elems.clear();
    elems.insert(elems.end(), other.elems.begin(), other.elems.end());
    return *this;
}

int main()
{
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    Stack<double> doubleStack;
    doubleStack = intStack;
    while (!doubleStack.isEmpty()) {
        std::cout << doubleStack.pop() << std::endl;
    }

    // Type checking is still performed
    // The following code can't be compiled.
    // Stack<std::string> stringStack;
    // stringStack.push("Hello");
    // stringStack.push("World");
    // doubleStack = stringStack; // error: no match for 'operator='
    return 0;
}