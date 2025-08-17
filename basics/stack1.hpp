#include <vector>
#include <cassert>
#include <iostream>

// Solution 3: pre-declare the template class itself
template<typename T> class Stack;
template<typename T>
std::ostream& operator<< (std::ostream&, const Stack<T>&);

template <typename T>
class Stack {
public:
    void push(const T& item);   // push element.
    void pop();                 // pop element.
    const T& top() const;       // return top element.
    bool isEmpty() const {      // return whether stack is empty.
        return elements.empty();
    }

    void printOn(std::ostream& os) const; // print elements to output stream.

    // Implement operator << for template class.
    // Solution 1: operator << has to be implemented as nonmember functions
    // (otherwise the first parameter is this pointer).
    // *define* the friend function within the class body at the same moment you *declare* it.
    // friend std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
    //     s.printOn(os);
    //     return os;
    // }

    // If we want to separate the definition from the declaration.
    // Solution 2: declare operator << as a friend function template and use a different template parameter U.
    // template <typename U>
    // friend std::ostream& operator<<(std::ostream& os, const Stack<U>& s);

    // Solution 3: pre-declare the template class itself. (if we want to separate the definition from the declaration)
    friend std::ostream& operator<< <> (std::ostream&, const Stack<T>&);
private:
    std::vector<T> elements;    // elements.
};

template <typename T>
void
Stack<T>::push(const T& item)
{
    elements.push_back(item);   // append copy of passed element.
}

template <typename T>
void
Stack<T>::pop()
{
    assert(!elements.empty());
    elements.pop_back();        // remove last element.
}

template <typename T>
const T&
Stack<T>::top() const {
    assert(!elements.empty());
    return elements.back();     // return copy of last element.
}

template <typename T>
void
Stack<T>::printOn(std::ostream& os) const {
    for (const auto& elem : elements) {
        os << elem << " ";  // call << for each element.
    }
}