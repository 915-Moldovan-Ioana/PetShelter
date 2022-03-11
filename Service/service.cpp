#include "service.h"
#include "RepoExceptions.h"
using namespace std;

void Service::AddDog(const std::string& breed, const std::string& name, int age, const std::string& photograph) {
    Dog dog(breed, name, age, photograph);
    this->validator.validate(dog);
    this->Repo_.AddDog(dog);
}

std::vector<Dog> Service::GetAll() {
    return this->Repo_.GetData();
}

void Service::DeleteDog(const std::string& breed, const std::string& name) {
    int age = 0;
    std::string photograph = "http...";
    Dog dog(breed, name, age, photograph);
    this->validator.validate(dog);
    int exists = this->Repo_.GetIndex(dog);
    if (exists == -1) {
        throw InexistentDogException{};
    }
    this->Repo_.DeleteDog(exists);
}

void Service::UpdateDog(const std::string& breed, const std::string& name, int newAge, const std::string& newPhotograph) {
    int age = 0;
    std::string photograph = "http...";
    Dog dog(breed, name, age, photograph);
    int exists = this->Repo_.GetIndex(dog);
    if (exists == -1) {
        throw InexistentDogException{};
    }
    Dog newDog(breed, name, newAge, newPhotograph);
    this->validator.validate(newDog);
    this->Repo_.UpdateDog(exists, newDog);
}

int Service::GetLength() {
    return this->Repo_.GetLength();
}

int Service::FilterDogs(std::vector<Dog> *List, const std::string& whatBreed, int whatAge) {
    int len = this->Repo_.GetLength();
    int returnLen = 0;
    Dog dog;
    for (int i = 0; i < len; i++) {
        dog = this->Repo_.GetDogByIndex(i);
        if (dog.getAge() < whatAge) {
            if (whatBreed == "no") {
                List->push_back(dog);
                returnLen++;
            } else {
                if (dog.getBreed() == whatBreed) {
                    List->push_back(dog);
                    returnLen++;
                }
            }
        }
    }
    return returnLen;
}

Service::Service(Repository& repository, FileRepo* a, DogValidator v): Repo_(repository) , AdoptionList(a), validator(v){}

void Service::AdoptDog(const Dog &D) {
    this->AdoptionList->UserAdoptDog(D);
}

int Service::GetLengthAdoptionList() {
    return this->AdoptionList->GetLength();
}

void Service::SaveList(const string &f) {
    this->AdoptionList->setFilename(f);
    this->AdoptionList->writeToFile();
}

void Service::OpenList() const {
    this->AdoptionList->displayDogs();
}

std::vector<Dog> Service::GetAdoptionList() {
    return this->AdoptionList->GetData();
}
