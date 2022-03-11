#pragma once
#include "fileRepo.h"
#include <string>

class CSVRepo: public FileRepo {
public:
    void writeToFile() override;
    void displayDogs() const override;
};