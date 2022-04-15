#include "line_counter.hpp"

#include <atomic>
#include <fstream>

namespace io = boost::asio;

namespace
{
    size_t count_lines_in_file(const fs::path& path)
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
} // namespace

size_t traversing_directory(const fs::path& directory_path)
{
    io::thread_pool thread_pool(std::thread::hardware_concurrency());

    std::atomic_size_t total_number = 0;
    for (const auto& entry : fs::recursive_directory_iterator(directory_path))
    {
        if (entry.is_regular_file() && !entry.is_symlink())
        {
            io::post(thread_pool,
                [&total_number, file_path = entry.path()]()
                {
                    total_number += count_lines_in_file(file_path);
                });
        }
    }
    thread_pool.join();

    return total_number;
}