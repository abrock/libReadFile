#include <fstream>
#include <string>
#include <cerrno>
#include "readfile.h"

std::string read_file(const char *filename)
{
    std::ifstream file_stream(filename, std::ios::in | std::ios::binary);
    if (!file_stream) {
        throw std::runtime_error(std::string("File ") + filename + " couldn't be read, errno: "
                                 + std::to_string(errno) + " in file "
                                 + __FILE__ + ", line " + std::to_string(__LINE__));
    }
    std::string file_contents;
    file_stream.seekg(0, std::ios::end);
    file_contents.resize(static_cast<size_t>(file_stream.tellg()));
    file_stream.seekg(0, std::ios::beg);
    file_stream.read(&file_contents[0], static_cast<long>(file_contents.size()));
    file_stream.close();
    return(file_contents);
}
