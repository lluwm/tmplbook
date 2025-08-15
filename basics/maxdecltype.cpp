#include <iostream>
#include <string>
#include <typeinfo>

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> decltype(b<a?a:b)
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