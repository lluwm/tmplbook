#include <string>
#include <iostream>

class BoolString {
private:
    std::string value;

public:
    BoolString(const std::string& s) : value(s) {}

    template <typename T = std::string>
    T get() const {         // get value (converted to T)
        return value;
    }
};

template <>
inline bool BoolString::get<bool>() const { // get value as bool
    return value == "true" || value == "1" || value == "on";
}

int
main()
{
    std::cout << std::boolalpha;
    BoolString s1("hello");
    std::cout << s1.get() << std::endl; // prints hello.
    std::cout << s1.get<bool>() << std::endl; // prints false.

    BoolString s2("on");
    std::cout << s2.get<bool>() << std::endl; // prints true.
}