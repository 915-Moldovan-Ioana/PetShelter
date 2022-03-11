//#include "tests.h"
//#include "domain.h"
//#include "service.h"
//#include <assert.h>
//using namespace std;
//
//void TestDomain() {
//    string breed = "a", name = "b", photo = "c";
//    int age = 10;
//    Dog dog(breed, name, age, photo);
//    assert(dog.getAge() == 10);
//    assert(dog.getBreed() == "a");
//    assert(dog.getName() == "b");
//    assert(dog.getPhotograph() == "c");
//
//    Dog dog2;
//    assert(dog2.getBreed().empty());
//    assert(dog2.getName().empty());
//    assert(dog2.getPhotograph().empty());
//    assert(dog2.getAge() == 0);
//
//    Dog dog3(breed, name, age, photo);
//    assert(dog.CheckIfDogsAreEqual(dog3) == true);
//    assert(dog.CheckIfDogsAreEqual(dog2) == false);
//}
//
//void TestRepo() {
//    std::vector<Dog> Repo;
//    Repository Sth{""};
//    Dog dog;
//    Dog dog2("a", "b", 2, "c");
//    Sth.AddDog(dog);
//    int i = Sth.GetIndex(dog);
//    assert(i == 0);
//    int j = Sth.GetIndex(dog2);
//    assert(j == -1);
//    assert(Sth.GetLength() == 1);
//    assert(dog.CheckIfDogsAreEqual(Sth.GetDogByIndex(0)));
//    assert(Sth.CheckIfDogExists(dog));
//    assert(!Sth.CheckIfDogExists(dog2));
//    Dog dog3("a", "b", 3, "d");
//    Sth.UpdateDog(0, dog3);
//    assert(dog3.CheckIfDogsAreEqual(Sth.GetDogByIndex(0)));
//    Sth.DeleteDog(0);
//    assert(Sth.GetLength() == 0);
//    Sth.AddDog(dog3);
//    Dog dog4("x", "y", 1, "z");
//    Sth.AddDog(dog4);
//    UserRepository UserRepo;
//    UserRepo.UserAdoptDog(dog4);
//    assert(UserRepo.GetLength() == 1);
//    Dog adopted_dog;
//    adopted_dog = UserRepo.GetDog(0);
//    int index = UserRepo.GetIndex(dog4);
//    int index2 = UserRepo.GetIndex(dog);
//    assert(index == 0);
//}
//
//void TestService() {
//    Repository repo{""};
//    Service S{repo, DogValidator{}};
//    Dog dog("a", "b", 1, "c");
//    std::vector<Dog> List;
//    assert(S.GetLength() == 0);
//    S.AddDog("a", "b", 1, "c");
//    assert(S.GetLength() == 1);
//    S.GetAll(&List);
//    assert(List.size() == 1);
//    assert(List.at(0).CheckIfDogsAreEqual(dog));
//    Dog dog2("a", "b", 2, "d");
//    S.UpdateDog("a", "b", 2, "d");
//    S.GetAll(&List);
//    assert(dog2.CheckIfDogsAreEqual(List.at(0)));
//    S.DeleteDog("a", "b");
//    assert(S.GetLength() == 0);
//    S.AddDog("dal", "ioa", 4, "w");
//    S.AddDog("dal", "ana", 6, "v");
//    std::vector<Dog> Doggos;
//    std::vector<Dog> D;
//    S.FilterDogs(&D, "no", 8);
//    assert(D.size() == 2);
//    S.FilterDogs(&Doggos, "dal", 5);
//    assert(Doggos.size() == 1);
//    UserRepository uRepo;
//    UserService US{uRepo};
//    assert(US.GetLength() == 0);
//    Dog doggo("i", "k", 3, "l");
//    US.AdoptDog(doggo);
//    assert(US.GetLength() == 1);
//    std::vector<Dog> Dogs;
//    US.GetAdoptionList(&Dogs);
//    assert(Dogs.size() == 1);
//    assert(Dogs.at(0).CheckIfDogsAreEqual(doggo));
//}
//
//void TestAll() {
//    TestDomain();
//    TestRepo();
//    TestService();
//}