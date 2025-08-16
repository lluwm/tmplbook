#include <array>
#include <string>

template<typename T1, typename T2>
constexpr auto max(T1 a, T2 b)
{
    return a < b ? b : a;
}

int
main()
{
    int a[::max(sizeof(int), 1000u)];
    std::array<std::string, ::max(sizeof(char), 1000u)> arr;
}