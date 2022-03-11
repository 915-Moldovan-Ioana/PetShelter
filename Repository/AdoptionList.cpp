#include "AdoptionList.h"
#include "RepoExceptions.h"

UserRepository::UserRepository() = default;;

void UserRepository::UserAdoptDog(const Dog& Dog) {
    if (CheckIfDogIsAdopted(Dog)) {
        throw AlreadyAdoptedException{};
    }
    this->AdoptedDogs.push_back(Dog);
}

int UserRepository::GetLength() {
    return this->AdoptedDogs.size();
}

int UserRepository::GetIndex(const Dog& Dog) {
    int i;
    for (i=0; i<=this->AdoptedDogs.size(); i++) {
        if (this->AdoptedDogs.at(i).CheckIfDogsAreEqual(Dog)) {
            return i;
        }
    }
    return -1;
}

Dog UserRepository::GetDog(int Index) {
    return this->AdoptedDogs.at(Index);
}

bool UserRepository::CheckIfDogIsAdopted(const Dog &Dog) {
    int i;
    for (i=0; i<this->AdoptedDogs.size(); i++) {
        if (this->AdoptedDogs.at(i).CheckIfDogsAreEqual(Dog))
            return true;
    }
    return false;
}

std::vector<Dog> UserRepository::GetData() {
    std::vector<Dog> data;
    data.reserve(this->GetLength());
    for (auto & Dogs : this->AdoptedDogs)
        data.push_back(Dogs);
    return data;
}
