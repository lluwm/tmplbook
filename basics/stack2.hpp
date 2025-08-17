#include "stack1.hpp"
#include <deque>
#include <string>
#include <cassert>
#include <iostream>

/*
 * Specialization of Stack for std::string
 * allows you to optimize implementations for certain types or to fix a
 * misbehavior of certain types for an instantiation of the class template.
 * This specialization uses std::deque for better performance with strings.
 */
template<>
class Stack<std::string> {
public:
    void push(const std::string& value);    // push element.
    void pop();                             // pop element.
    const std::string& top() const;         // return top element.

    bool empty() const {                    // return whether the stack is empty.
        return elems.empty();
    }

private:
    std::deque<std::string> elems;  // elements
};

void
Stack<std::string>::push(const std::string& value) {
    std::cout << "Pushing string onto stack with specialization: " << value << std::endl;
    elems.push_back(value);     // append copy of passed elem.
}

void
Stack<std::string>::pop() {     // remove last element.
    assert(!elems.empty());
    elems.pop_back();
}

const std::string&
Stack<std::string>::top() const {   // return copy of last element.
    assert(!elems.empty());
    return elems.back();
}