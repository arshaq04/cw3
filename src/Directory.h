#include "Directory.h"
#include <algorithm>

Directory::Directory(const std::string& name) : FileSystemObject(name) {}

void Directory::addFile(const std::shared_ptr<File>& file) {
    contents.push_back(file);
    setModificationDate();
}

void Directory::addDirectory(const std::shared_ptr<Directory>& directory) {
    contents.push_back(directory);
    setModificationDate();
}

void Directory::removeFile(const std::string& fileName) {
    contents.erase(std::remove_if(contents.begin(), contents.end(),
        [&fileName](const std::shared_ptr<FileSystemObject>& obj) {
            return obj->getName() == fileName && dynamic_cast<File*>(obj.get()) != nullptr;
        }), contents.end());
    setModificationDate();
}

void Directory::removeDirectory(const std::string& directoryName) {
    contents.erase(std::remove_if(contents.begin(), contents.end(),
        [&directoryName](const std::shared_ptr<FileSystemObject>& obj) {
            return obj->getName() == directoryName && dynamic_cast<Directory*>(obj.get()) != nullptr;
        }), contents.end());
    setModificationDate();
}

std::vector<std::string> Directory::listContents() const {
    std::vector<std::string> names;
    for (const auto& obj : contents) {
        names.push_back(obj->getName());
    }
    return names;
}
