#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

using std::cout;

size_t countLinesInFile(const std::string& path)
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

size_t traversingDirectory(const fs::path& directoryPath)
{
    size_t totalNumber = 0;
    for (const auto& entry : fs::recursive_directory_iterator(directoryPath))
    {
        if (entry.is_regular_file() && !entry.is_symlink())
        {
            totalNumber += countLinesInFile(entry.path());
        }
    }
    return totalNumber;
}

int main()
{
    cout << traversingDirectory("./tests/test1") << '\n';

    return 0;
}
