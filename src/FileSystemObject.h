#ifndef FILESYSTEMOBJECT_H
#define FILESYSTEMOBJECT_H

#include <string>
#include <ctime>

class FileSystemObject {
protected:
    std::string name;
    std::time_t creationDate;
    std::time_t modificationDate;

public:
    FileSystemObject(const std::string& name);
    std::string getName() const;
    std::time_t getCreationDate() const;
    std::time_t getModificationDate() const;
    void setModificationDate();
};

#endif // FILESYSTEMOBJECT_H
