#include "AdoptionList.h"
#include "fileRepo.h"


FileRepo::FileRepo() : UserRepository{}, filename{""}{

}

void FileRepo::setFilename(const std::string &f) {
    this->filename = f;
}

