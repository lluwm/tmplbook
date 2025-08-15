#include <type_traits>
#include <iostream>
#include <typeinfo>

template<typename T1, typename T2,
         typename RT = std::decay_t<decltype(true ? T1() : T2())>>
RT max (T1 a, T2 b)
{
  return  b < a ? a : b;
}

int
main()
{
    double i = 5.6;
    std::cout << "max(7, i): " << ::max(7, i)
              << ", type: " << typeid(::max(7, i)).name()  << '\n';

    i = 50.6;
    std::cout << "max(7, i): " << ::max(7, i)
              << ", type: " << typeid(::max(7, i)).name()  << '\n';
}