#ifndef FILE_H
#define FILE_H

#include "FileSystemObject.h"
#include <string>

class File : public FileSystemObject {
private:
    std::string data;
    int size;

public:
    File(const std::string& name);
    std::string read() const;
    void write(const std::string& data);
    int getSize() const;
};

#endif // FILE_H
