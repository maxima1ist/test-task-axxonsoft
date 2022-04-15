#include <filesystem>

#include <boost/asio.hpp>

namespace fs = std::filesystem;

size_t traversing_directory(const fs::path& directory_path);