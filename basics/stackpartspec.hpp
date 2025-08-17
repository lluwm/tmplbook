#include "stack1.hpp"

// partial specialization of class Stack<> for pointers.
template<typename T>
class Stack<T *> {
public:
    void push(T *elem);    // push element.
    T *pop();              // pop element.
    T *top() const;         // return top element.

    bool empty() const {     // return whether the stack is empty.
        return elems.empty();
    }

private:
    std::vector<T *> elems;  // elements
};

template<typename T>
void
Stack<T*>::push(T* elem) {
    elems.push_back(elem);     // append copy of passed elem.
}

template<typename T>
T *
Stack<T *>::pop() {     // remove last element.
    assert(!elems.empty());
    T *p = elems.back();
    elems.pop_back();
    return p;           // and return it.
}

template<typename T>
T *
Stack<T *>::top() const {   // return copy of last element.
    assert(!elems.empty());
    return elems.back();
}