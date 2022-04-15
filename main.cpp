#include "src/line_counter.hpp"

#include <iostream>

using std::cout;
using std::cerr;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "Incorrect number of arguments!\n"
            << "Template: ./linecounter <path-to-a-directory>\n";
        return 1;
    }

    std::string directory_path = argv[1];
    try
    {
        size_t total_number = traversing_directory(directory_path);
        std::cout << "The total number of lines in all files in a directory "
            << directory_path << " is " << total_number << '\n';
    }
    catch (const fs::filesystem_error& exp)
    {
        std::cerr << exp.code().message() << '\n';
        return 1;
    }
    catch (const std::exception& exp)
    {
        std::cerr << exp.what() << '\n';
        return 1;
    }
    catch (...)
    {
        std::cerr << "Something really bad happened :(" << '\n';
        return 1;
    }

    return 0;
}
