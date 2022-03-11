#pragma once
#include "repository.h"
#include "Validators.h"
#include "fileRepo.h"
#include "AdoptionList.h"
#include <vector>

class Service {
private:
    Repository& Repo_;
    FileRepo* AdoptionList;
    DogValidator validator;
public:

    explicit Service(Repository&, FileRepo*, DogValidator);

    /// An ADD function which takes parameters form the user input, creates a dog with that characteristics
    /// and passes it to the Repo function for ADD.
    void AddDog(const std::string& breed, const std::string& name, int age, const std::string& photograph);

    /// The DELETE function passes the dog's breed and name which is meant to be removed from the database.
    void DeleteDog(const std::string& breed, const std::string& name);

    /// The UPDATE function passes the new age and new photo in order to update the dog with a certain breed and name.
    void UpdateDog(const std::string& breed, const std::string& name, int newAge, const std::string& newPhotograph);

    /// This function gets all the dogs from the repo (database) to use it further for listing all the dogs.
    std::vector<Dog> GetAll();

    /// This function gets dogs of a certain breed and with an age smaller than a given number.
    int FilterDogs(std::vector<Dog> *List, const std::string& whatBreed, int whatAge);

    /// How many dogs are in the shelter. (size of the vector)
    int GetLength();

    /// This function adds a selected dog to the adoption list of the current user. (adopted dog)
    void AdoptDog(const Dog&);

    /// Get all the adopted dogs by the current user.
    std::vector<Dog> GetAdoptionList();

    /// How many dogs has the user adopted.
    int GetLengthAdoptionList();

    /// Save the adoption list in a given format.
    void SaveList(const std::string&);

    /// Open the adoption list with the correct application.
    void OpenList() const;
};
