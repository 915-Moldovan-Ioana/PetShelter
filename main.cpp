#include "CSVRepo.h"
#include "HTMLFile.h"
#include "repository.h"
#include "service.h"
#include <iostream>
#include <QtWidgets/QApplication>
#include "GUI.h"
#include "AdministratorGUI.h"
#include "UserGUI.h"

using namespace std;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    std::string file = "D:\\ioana\\Github\\a67-915-Moldovan-Ioana\\dogs.txt";
    Repository repo{file};
    FileRepo* r;
    r = new CSVRepo{};
//    std::string option;
//    std::cout << "Choose the type of the file (csv or html): ";
//    std::cin >> option;
//    if (option == "csv") {
//        r = new CSVRepo{};
//    } else if (option == "html") {
//        r = new HTMLRepo{};
//    }
    Service serv{repo, r, DogValidator{}};
    AdministratorGUI adm{serv};
    UserGUI u{serv};
    GUI gui{adm, u};
    gui.show();
    return a.exec();
}
