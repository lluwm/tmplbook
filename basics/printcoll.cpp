#include <iostream>
#include <vector>

template <typename T>
void printcoll (const T& coll)
{
    typename T::const_iterator pos; // iterator to iterate over coll
    typename T::const_iterator end(coll.end()); // end position

    for (pos = coll.begin(); pos != end; ++pos)
    {
        std::cout << *pos << " ";
    }
    std::cout << std::endl;
}

int
main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printcoll<std::vector<int>>(vec);

    return 0;
}