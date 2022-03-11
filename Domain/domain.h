#pragma once
#include <string>

class Dog {
private:
    std:: string breed;
    std:: string name;
    int age;
    std:: string photograph;

public:

    /// Constructor with parameters
    Dog(const std:: string& breed, const std:: string& name, int age, const std:: string& photograph);

    /// Default constructor
    Dog();

    /// Copy constructor
    Dog(const Dog &d);

    /// Destructor
    ~Dog();

    /// Checks if a given dog is the same with the current one
    bool CheckIfDogsAreEqual(Dog Dog);

    /// Getters
    std:: string getBreed() const;
    std:: string getName() const;
    int getAge() const;
    std:: string getPhotograph() const;
    std:: string toString() const;
    bool operator==(const Dog& anotherDog) const;
    friend std::istream &operator>>(std::istream &is, Dog &dog);
    friend std::ostream &operator<<(std::ostream &os, const Dog &dog);
};