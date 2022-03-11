#include "domain.h"
#include <sstream>
#include <vector>

using namespace std;

Dog::Dog(const std::string &breed, const std::string &name, int age, const std::string &photograph) {
    this->breed = breed;
    this->name = name;
    this->age = age;
    this->photograph = photograph;
}

Dog::Dog() {
    this->breed = "";
    this->name = "";
    this->age = 0;
    this->photograph = "";
}

Dog::Dog(const Dog &d) {
    this->breed = d.breed;
    this->name = d.name;
    this->age = d.age;
    this->photograph = d.photograph;
}

Dog::~Dog() = default;

std::string Dog::getBreed() const {
    return this->breed;
}

std::string Dog::getName() const {
    return this->name;
}

int Dog::getAge() const {
    return this->age;
}

std::string Dog::getPhotograph() const {
    return this->photograph;
}

bool Dog::CheckIfDogsAreEqual(Dog Dog) {
    if (this->getBreed() == Dog.getBreed() && this->getName() == Dog.getName())
        return true;
    return false;
}

std::string Dog::toString() const {
    stringstream buffer;
    buffer << "Dog " << this->name << ": \n\t -breed: " << this->breed
         << "\n\t -age: " << this->age
         << "\n\t -photograph: " << this->photograph << endl;
    return buffer.str();
}

bool Dog::operator==(const Dog &anotherDog) const {
    return (this->breed == anotherDog.breed && this->name == anotherDog.name);
}

vector<string> tokenize(string str, char delimiter){
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);
    return result;
}


std::istream &operator>>(istream &is, Dog &dog) {
    string line;
    getline(is, line);
    vector<string> tokens = tokenize(line, ',');
    if(tokens.size() !=4) return is;
    dog.breed = tokens[0];
    dog.name = tokens[1];
    dog.age = stoi(tokens[2]);
    dog.photograph = tokens[3];
    return is;
}

std::ostream &operator<<(ostream &os, const Dog &dog) {
    os << dog.breed << "," << dog.name << "," << dog.age << "," << dog.photograph << "\n";
    return os;
}