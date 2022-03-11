#pragma once
#include "domain.h"
#include <vector>

class UserRepository {
protected:
    std::vector<Dog> AdoptedDogs;
public:
    /// Constructor
    UserRepository();

    /// Adopt a dog; add it to the user's adoption list.
    void UserAdoptDog(const Dog& Dog);

    /// Return the number of dogs adopted by the user.
    int GetLength();

    /// Get an element's (dog's) index form the vector.
    int GetIndex(const Dog& Dog);

    /// Check if a certain dog has already been adopted.
    bool CheckIfDogIsAdopted(const Dog& Dog);

    /// Get a certain dog by the index.
    Dog GetDog(int Index);

    std::vector<Dog> GetData();

    /// Destructor
    virtual ~UserRepository() {}
};
