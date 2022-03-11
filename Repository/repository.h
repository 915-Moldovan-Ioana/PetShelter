#pragma once

#include <vector>
#include "domain.h"

class Repository {
private:
    std::vector<Dog> Repo;
    std::string file_;
public:
    /// Constructor
    explicit Repository(std::string);

    /// Add a new element (dog) to the database.
    void AddDog(const Dog& Dog);

    /// Update an existing element (dog) from the database.
    void UpdateDog(int Index, Dog& NewDog);

    /// Delete an existing element (dog) from the database.
    void DeleteDog(int Index);

    std::vector<Dog> GetData();

    /// Get a certain element (dog) by an index form the vector. (database)
    Dog GetDogByIndex(int Index);

    /// Check if a certain element (dog) exists in the database.
    bool CheckIfDogExists(const Dog& Dog);

    /// Get an element's (dog's) index form the vector.
    int GetIndex(const Dog& Dog);

    /// Get the size of the vector. (how many dogs)
    int GetLength();

    /// Get the list of elements.
    std::vector<Dog> GetElements();

    void ReadFile();
    void WriteFile();
};
