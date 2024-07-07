#include "FileSystemObject.h"

FileSystemObject::FileSystemObject(const std::string& name)
    : name(name), creationDate(std::time(nullptr)), modificationDate(std::time(nullptr)) {}

std::string FileSystemObject::getName() const {
    return name;
}

std::time_t FileSystemObject::getCreationDate() const {
    return creationDate;
}

std::time_t FileSystemObject::getModificationDate() const {
    return modificationDate;
}

void FileSystemObject::setModificationDate() {
    modificationDate = std::time(nullptr);
}
