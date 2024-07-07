#include "FileSystem.h"
#include "File.h"

FileSystem::FileSystem() {
    root = std::make_shared<Directory>("root");
    currentDirectory = root;
}

void FileSystem::createFile(const std::string& name) {
    auto file = std::make_shared<File>(name);
    currentDirectory->addFile(file);
}

void FileSystem::deleteFile(const std::string& name) {
    currentDirectory->removeFile(name);
}

void FileSystem::createDirectory(const std::string& name) {
    auto directory = std::make_shared<Directory>(name);
    currentDirectory->addDirectory(directory);
}

void FileSystem::deleteDirectory(const std::string& name) {
    currentDirectory->removeDirectory(name);
}

void FileSystem::changeDirectory(const std::string& path) {
    // Simplified: Only supports changing to root or current subdirectories
    if (path == "/") {
        currentDirectory = root;
    } else {
        for (const auto& obj : currentDirectory->listContents()) {
            if (obj == path) {
                for (const auto& content : currentDirectory->listContents()) {
                    auto dir = dynamic_cast<Directory*>(content.get());
                    if (dir && dir->getName() == path) {
                        currentDirectory = std::make_shared<Directory>(*dir);
                        return;
                    }
                }
            }
        }
    }
}

std::vector<std::string> FileSystem::listDirectoryContents() const {
    return currentDirectory->listContents();
}

std::string FileSystem::readFile(const std::string& name) const {
    for (const auto& obj : currentDirectory->listContents()) {
        auto file = dynamic_cast<File*>(obj.get());
        if (file && file->getName() == name) {
            return file->read();
        }
    }
    return "";
}

void FileSystem::writeFile(const std::string& name, const std::string& data) {
    for (const auto& obj : currentDirectory->listContents()) {
        auto file = dynamic_cast<File*>(obj.get());
        if (file && file->getName() == name) {
            file->write(data);
            return;
        }
    }
    createFile(name);
    writeFile(name, data);
}
