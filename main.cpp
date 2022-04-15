#include "src/line_counter.hpp"

#include <iostream>

int main()
{
    std::cout << traversing_directory("./tests/test0") << '\n';
    std::cout << traversing_directory("./tests/test1") << '\n';
    std::cout << traversing_directory("./tests/test2") << '\n';

    return 0;
}
