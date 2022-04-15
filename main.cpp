#include <atomic>
#include <iostream>
#include <filesystem>
#include <fstream>

#include <boost/asio.hpp>

namespace fs = std::filesystem;

size_t count_lines_in_file(const std::string& path)
{
    size_t count = 0;

    std::string line;
    std::ifstream fin(path);
    while (std::getline(fin, line))
    {
        ++count;
    }
    
    return count;
}

size_t traversing_directory(const fs::path& directory_path)
{
    boost::asio::thread_pool thread_pool(std::thread::hardware_concurrency());

    std::atomic_size_t total_number = 0;
    for (const auto& entry : fs::recursive_directory_iterator(directory_path))
    {
        if (entry.is_regular_file() && !entry.is_symlink())
        {
            boost::asio::post(thread_pool,
                [&total_number, path_to_file = entry.path()]()
                {
                    total_number += count_lines_in_file(path_to_file);
                });
        }
    }
    thread_pool.join();

    return total_number;
}

int main()
{
    std::cout << traversing_directory("./tests/test1") << '\n';
    std::cout << traversing_directory("./tests/test2") << '\n';
    std::cout << traversing_directory("./tests/test3") << '\n';
    std::cout << traversing_directory("./tests/test4") << '\n';

    return 0;
}
