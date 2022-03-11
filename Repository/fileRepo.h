#pragma once
#include "AdoptionList.h"

class FileRepo : public UserRepository {
protected:
    std::string filename;

public:
    FileRepo();
    virtual ~FileRepo() = default;

    void setFilename(const std::string&);
    virtual void writeToFile() = 0;
    virtual void displayDogs() const = 0;
};