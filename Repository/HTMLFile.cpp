#include "HTMLFile.h"
#include "RepoExceptions.h"
#include <fstream>
#include <Windows.h>

using namespace std;

void HTMLRepo::writeToFile() {
    ofstream f(this->filename);

    if (!f.is_open()) {
        throw FileException("The file could noy be opened!");
    }

    std::string start = "<!DOCTYPE html>\n"
                        "<html>\n"
                        "<head>\n"
                        "   <title>Adoption List</title>\n"
                        "</head>\n"
                        "<body>\n"
                        "<table border=\"1\">\n"
                        "   <tr>\n"
                        "       <td>Breed</td>\n"
                        "       <td>Name</td>\n"
                        "       <td>Age</td>\n"
                        "       <td>Photograph</td>\n"
                        "   </tr>\n";
    std::string end = "</table>\n"
                      "</body>\n"
                      "</html>\n";

    f << start;
    string baseLine = "\t\t<td>";
    string endLine = "</td>\n";

    for (auto s : this->AdoptedDogs) {
        std::string breed = baseLine + s.getBreed() + endLine;
        std::string name = baseLine + s.getName() + endLine;
        std::string age = baseLine + to_string(s.getAge()) + endLine;
        std::string photo = baseLine + "<a href=\"" + s.getPhotograph() + "\">Photograph</a>" + endLine;
        f << "\t<tr>\n" << breed << name << age << photo << "\t</tr>\n";
    }
    f << end;
    f.close();
}

void HTMLRepo::displayDogs() const {
    string aux = "\"" + this->filename + "\"";
    ShellExecuteA(NULL, NULL, "C:\\Program Files\\Mozilla Firefox\\firefox.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
