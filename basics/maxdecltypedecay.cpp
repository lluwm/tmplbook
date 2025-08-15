#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <string>

template<typename T1, typename T2>
auto max (T1 a, T2 b) -> typename std::decay<decltype(true?a:b)>::type
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