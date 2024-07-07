#include "File.h"

File::File(const std::string& name) : FileSystemObject(name), size(0) {}

std::string File::read() const {
    return data;
}

void File::write(const std::string& data) {
    this->data = data;
    size = data.size();
    setModificationDate();
}

int File::getSize() const {
    return size;
}
