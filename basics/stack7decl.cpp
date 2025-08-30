#include <deque>

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
    template<typename, typename> friend class Stack;
};
