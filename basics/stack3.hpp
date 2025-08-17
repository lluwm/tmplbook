#include <vector>
#include <cassert>

template <typename T, typename Cont = std::vector<T>>
class Stack {
public:
    void push(const T& value);  // push element.
    void pop();                 // pop element.
    const T& top() const;       // return top element.
    bool empty() const {
        return elems.empty();
    }

private:
    Cont elems;                 // elements.
};

template <typename T, typename Cont>
void
Stack<T, Cont>::push(const T& value) {
    elems.push_back(value);     // append copy of passed element.
}

template <typename T, typename Cont>
void
Stack<T, Cont>::pop() {
    assert(!elems.empty());
    elems.pop_back();           // remove last element.
}

template <typename T, typename Cont>
const T&
Stack<T, Cont>::top() const {
    assert(!elems.empty());
    return elems.back();        // return copy of last element.
}