#include <type_traits>
#include <typeinfo>
#include <iostream>
#include <string>

template<typename T1, typename T2>
std::common_type_t<T1,T2> max (T1 a, T2 b)
{
  return  b < a ? a : b;
}

int
main()
{
    long i = 5;
    std::cout << "max(7, i): " << ::max(7, i)
              << ", type: " << typeid(::max(7, i)).name()  << '\n';

    i = 50;
    std::cout << "max(7, i): " << ::max(7, i)
              << ", type: " << typeid(::max(7, i)).name()  << '\n';
}