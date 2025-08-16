#include <iostream>
using namespace std;

// maximum of two values of any type.
template<typename T>
T const&
max(T const& a, T const& b)
{
    cout << "max<T>() \n";
    return b < a ? a : b;
}

// maximum of three values of any type.
template<typename T>
T
max(T a, T b, T c)
{
    return ::max(::max(a, b), c);
    // uses the template version even for ints.
    // because the following declaration comes too late.
}

int
max(int a, int b)
{
    cout << "max(int,int) \n";
    return b < a ? a : b;
}

int
main()
{
    ::max(47, 11, 33); // OOPS: uses max<T>() instead of max(int,int).
}
