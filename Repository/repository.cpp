#include <fstream>
#include "repository.h"
#include "RepoExceptions.h"
using namespace std;

Repository::Repository(std::string file) : file_(file) {
    ReadFile();
}

void Repository::AddDog(const Dog &Dog) {
    if (CheckIfDogExists(Dog)) {
        throw DuplicateDogException{};
    }
    this->Repo.push_back(Dog);
    this->WriteFile();
}

void Repository::DeleteDog(int Index) {
    Dog dog = this->GetDogByIndex(Index);
    this->Repo.erase(this->Repo.begin() + Index);
    WriteFile();
}

void Repository::UpdateDog(int Index, Dog &NewDog) {
    Dog dog = this->GetDogByIndex(Index);
    this->Repo.at(Index) = NewDog;
    WriteFile();
}

std::vector<Dog> Repository::GetData() {
    std::vector<Dog> data;
    data.reserve(this->GetLength());
    for (auto & Repo : this->Repo)
        data.push_back(Repo);
    return data;
}

bool Repository::CheckIfDogExists(const Dog &Dog) {
    int i;
    for (i=0; i<this->Repo.size(); i++) {
        if (this->Repo.at(i).CheckIfDogsAreEqual(Dog))
            return true;
    }
    return false;
}

int Repository::GetIndex(const Dog &Dog) {
    int i;
    for (i=0; i<this->Repo.size(); i++) {
        if (this->Repo.at(i).CheckIfDogsAreEqual(Dog))
            return i;
    }
    return -1;
}

Dog Repository::GetDogByIndex(int Index) {
    return this->Repo.at(Index);
}

int Repository::GetLength() {
    return this->Repo.size();
}

std::vector<Dog> Repository::GetElements() {
    return this->Repo;
}

void Repository::ReadFile() {
    ifstream f(this->file_);
    Dog dog;
    if (!f.is_open()) {
        throw FileException("The file could not be opened!");
    }
    while (f >> dog) {
        this->Repo.push_back(dog);
    }
    f.close();
}

void Repository::WriteFile() {
    ofstream f(this->file_);
    if (!f.is_open()) {
        return;
    }
    vector<Dog> dogs = GetElements();
    for (const auto& dog : dogs) {
        f << dog;
    }
    f.close();
}
