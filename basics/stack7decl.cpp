#include <deque>
#include <stdexcept>
#include <iostream>

template <typename T, typename Cont = std::deque<T>>
class Stack {
private:
    Cont elems;    // elements.

public:
    void push(const T& item);
    T pop();

    bool isEmpty() const {
        return elems.empty();
    }

    // assign stack of elements of type T2
    template <typename T2, typename Cont2>
    Stack& operator=(const Stack<T2, Cont2>& other);

    // to get access to private members of Stack<T2, Cont2> for any type T2, Cont2
    template<typename T2, typename Cont2> friend class Stack;
};

template <typename T, typename Cont>
void
Stack<T, Cont>::push(const T& item)
{
    elems.push_back(item);
}

template <typename T, typename Cont>
T Stack<T, Cont>::pop()
{
    if (elems.empty()) throw std::out_of_range("Stack<>::pop(): empty stack");
    T elem = elems.back();
    elems.pop_back();
    return elem;
}

template <typename T, typename Cont>
template <typename T2, typename Cont2>
Stack<T, Cont>& Stack<T, Cont>::operator=(const Stack<T2, Cont2>& other)
{
    elems.clear();
    elems.insert(elems.begin(), other.elems.begin(), other.elems.end());
    return *this;
}

int
main()
{
    Stack<int, std::vector<int>> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    Stack<double, std::vector<double>> doubleStack;
    doubleStack = intStack;
    while (!doubleStack.isEmpty()) {
        std::cout << doubleStack.pop() << std::endl;
    }

    return 0;
}