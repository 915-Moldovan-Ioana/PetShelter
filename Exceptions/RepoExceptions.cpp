#include "RepoExceptions.h"

FileException::FileException(const std::string &msg) : message(msg){

}

const char *FileException::what() {
    return message.c_str();
}

RepoException::RepoException() : exception{}, message{""}{

}

RepoException::RepoException(const std::string &msg) : message{msg}{

}

const char *RepoException::what() {
    return this->message.c_str();
}


const char *DuplicateDogException::what() {
    return "There is another dog with the same breed and name!";
}

const char *InexistentDogException::what() {
    return "This dog does not exist!";
}

const char *AlreadyAdoptedException::what() {
    return "You have already adopted this dog!";
}
