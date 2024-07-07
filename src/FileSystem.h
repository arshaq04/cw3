#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Directory.h"
#include <memory>
#include <string>

class FileSystem {
private:
    std::shared_ptr<Directory> root;
    std::shared_ptr<Directory> currentDirectory;

public:
    FileSystem();
    void createFile(const std::string& name);
    void deleteFile(const std::string& name);
    void createDirectory(const std::string& name);
    void deleteDirectory(const std::string& name);
    void changeDirectory(const std::string& path);
    std::vector<std::string> listDirectoryContents() const;
    std::string readFile(const std::string& name) const;
    void writeFile(const std::string& name, const std::string& data);
};

#endif // FILESYSTEM_H
