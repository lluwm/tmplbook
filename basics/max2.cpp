// maximun of two int values
int
max(int a, int b)
{
    return b < a ? a : b;
}

// maximum of two values of any type
template <typename T>
T
max(T a, T b)
{
    return b < a ? a : b;
}

int
main()
{
    ::max(7, 12); // calls the non-template version.
    ::max(7.0, 12.0); // calls max<double> by argument deduction.
    ::max('a', 'b');  // calls max<char> by argument deduction.
    ::max<>(7, 12);   // calls max<int> by argument deduction.
    ::max<double>(7, 12); // calls max<double> no argument deduction.
    ::max('a', 42.7); // calls non-template version for two ints.
    return 0;
}