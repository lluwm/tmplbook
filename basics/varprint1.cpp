#include <iostream>

void
print()
{
    // empty.
}

template <typename T, typename... Types>
void print(T firstArg, Types... args)
{
    std::cout << firstArg << std::endl;     // print the first argument
    print(args...);                         // call print() for the remaining arguments.
}

int
main()
{
    std::string s("world");
    print(7.5, "Hello", s);
    print<double, const char*, std::string>(3.14, "C++", s);
    return 0;
}