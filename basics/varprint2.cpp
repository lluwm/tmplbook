#include <iostream>

template <typename T>
void
print (T arg)
{
    std::cout << arg << std::endl;
}

template <typename T, typename... Types>
void print (T firstArg, Types... args)
{
    // std::cout << sizeof...(Types) << " remaining arguments." << std::endl;
    // std::cout << sizeof...(args) << " remaining arguments." << std::endl;
    print(firstArg);     // print the first argument
    if (sizeof...(args) > 0) {
        print(args...);      // call print() for the remaining arguments.
    }
}

int
main()
{
    std::string s("world");
    print(7.5, "Hello", s);
    print<double, const char*, std::string>(3.14, "C++", s);
    return 0;
}