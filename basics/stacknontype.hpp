#include <array>
#include <cassert>

template <typename T, std::size_t Maxsize>
class Stack {
public:
    Stack();                        // constructor.
    void push(const T& value);      // push element.
    void pop();                     // pop element.
    const T& top() const;           // get top element. 
    bool empty() const {            // return whether the stack is empty.
        return numElems == 0;
    }
    std::size_t size() const {     // return the number of elements.
        return numElems;
    }

private:
    std::array<T, Maxsize> elems;
    std::size_t numElems;
};

template <typename T, std::size_t Maxsize>
Stack<T, Maxsize>::Stack()
    : numElems(0)               // start with no elements.
{
    // nothing else to do.
}

template <typename T, std::size_t Maxsize>
void
Stack<T, Maxsize>::push(const T& value)
{
    assert(numElems < Maxsize); // ensure stack is not full.
    elems[numElems++] = value;  // append element.
}

template <typename T, std::size_t Maxsize>
void
Stack<T, Maxsize>::pop()
{
    assert(!empty());           // ensure stack is not empty.
    --numElems;                 // decrement number of elements.
}

template <typename T, std::size_t Maxsize>
const T&
Stack<T, Maxsize>::top() const
{
    assert(!empty());
    return elems[numElems - 1]; // return last element.
}