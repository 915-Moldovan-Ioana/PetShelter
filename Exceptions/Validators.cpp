#include "Validators.h"

DogException::DogException(std::vector<std::string> _errors) : errors{_errors} {

}

std::vector<std::string> DogException::getErrors() const {
    return this->errors;
}

void DogValidator::validate(const Dog &d) {
    std::vector<std::string> errors;
    if (d.getAge() < 0)
        errors.push_back("The age cannot be smaller than 0!\n");
    if (!isupper(d.getName()[0]))
        errors.push_back("The name of the dog must start with a capital letter!\n");
    size_t posHttp = d.getPhotograph().find("http");
    if (posHttp != 0)
        errors.push_back("This is not a valid link towards a photograph!\n");
    if (errors.size() > 0)
        throw DogException(errors);
}
