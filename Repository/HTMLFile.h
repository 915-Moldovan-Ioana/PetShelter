#pragma once
#include "fileRepo.h"
#include <string>

class HTMLRepo: public FileRepo {
public:
    void writeToFile() override;
    void displayDogs() const override;
};