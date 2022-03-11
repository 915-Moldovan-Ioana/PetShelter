#include "CSVRepo.h"
#include "RepoExceptions.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void CSVRepo::writeToFile() {
    ofstream f(this->filename);

    if (!f.is_open()) {
        throw FileException("The file could not be opened!");
    }

    for (auto s : this->AdoptedDogs) {
        f << s;
    }
    f.close();
}

void CSVRepo::displayDogs() const {
    string aux = "\"" + this->filename + "\"";
    ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\WPS Office\\ksolaunch.exe", aux.c_str(), NULL,
                  SW_SHOWMAXIMIZED);
}
