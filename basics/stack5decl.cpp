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
    // other has a different type, so cannot access elems directly
    Stack<T2> temp = other; // use copy constructor

    elems.clear();
    while (!temp.isEmpty()) {
        elems.push_front(temp.pop());
    }
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

    return 0;
}
