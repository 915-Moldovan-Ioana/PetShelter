#include "AdministratorGUI.h"
#include "RepoExceptions.h"
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qmessagebox.h>
#include <vector>
#include <sstream>
using namespace std;

using namespace std;

AdministratorGUI::AdministratorGUI(Service& s) : serv{s} {
    this->initAdmGUI();
    this->populateList();
    this->connectSignalsAndSlots();
}

void AdministratorGUI::initAdmGUI() {
    this->nameLineEdit = new QLineEdit{};
    this->breedLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photographLineEdit = new QLineEdit{};
    this->backButton = new QPushButton{"Back"};
    this->addDesignButton = new QPushButton{"Add a new dog"};
    this->deleteDesignButton = new QPushButton{"Remove an adopted dog"};
    this->updateDesignButton = new QPushButton{"Update a dog"};
    this->dogsListWidget = new QListWidget{};

    this->administratorLayout = new QVBoxLayout{this};

    this->administratorLayout->addWidget(this->dogsListWidget);

    //add
    administratorLayout->addWidget(this->addDesignButton);
    this->addName = new QLineEdit{};
    this->addBreed = new QLineEdit{};
    this->addAge = new QLineEdit{};
    this->addPhotograph = new QLineEdit{};
    this->addButton = new QPushButton{"Add"};
    this->administratorLayout->addWidget(this->addName);
    this->addName->setText("Enter the name");
    this->addName->setVisible(false);
    this->administratorLayout->addWidget(this->addBreed);
    this->addBreed->setText("Enter the breed");
    this->addBreed->setVisible(false);
    this->administratorLayout->addWidget(this->addAge);
    this->addAge->setText("Enter the age");
    this->addAge->setVisible(false);
    this->administratorLayout->addWidget(this->addPhotograph);
    this->addPhotograph->setText("Enter the photograph");
    this->addPhotograph->setVisible(false);
    this->administratorLayout->addWidget(this->addButton);
    this->addButton->setVisible(false);

    //remove
    administratorLayout->addWidget(this->deleteDesignButton);
    this->deleteBreed = new QLineEdit{};
    this->deleteName = new QLineEdit{};
    this->deleteButton = new QPushButton{"Remove"};
    this->administratorLayout->addWidget(this->deleteName);
    this->deleteName->setText("Enter the name");
    this->deleteName->setVisible(false);
    this->administratorLayout->addWidget(this->deleteBreed);
    this->deleteBreed->setText("Enter the breed");
    this->deleteBreed->setVisible(false);
    this->administratorLayout->addWidget(this->deleteButton);
    this->deleteButton->setVisible(false);

    //update
    administratorLayout->addWidget(this->updateDesignButton);
    this->updateName = new QLineEdit{};
    this->updateBreed = new QLineEdit{};
    this->updateAge = new QLineEdit{};
    this->updatePhotograph = new QLineEdit{};
    this->updateButton = new QPushButton{"Update"};
    this->administratorLayout->addWidget(this->updateName);
    this->updateName->setText("Enter the name");
    this->updateName->setVisible(false);
    this->administratorLayout->addWidget(this->updateBreed);
    this->updateBreed->setText("Enter the breed");
    this->updateBreed->setVisible(false);
    this->administratorLayout->addWidget(this->updateAge);
    this->updateAge->setText("Enter the age");
    this->updateAge->setVisible(false);
    this->administratorLayout->addWidget(this->updatePhotograph);
    this->updatePhotograph->setText("Enter the photograph");
    this->updatePhotograph->setVisible(false);
    this->administratorLayout->addWidget(this->updateButton);
    this->updateButton->setVisible(false);

    administratorLayout->addWidget(this->backButton);
}

void AdministratorGUI::populateList() {
    this->dogsListWidget->clear();
    vector<Dog> allDogs = this->serv.GetAll();
    for(Dog& d : allDogs)
        this->dogsListWidget->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + to_string(d.getAge()) + " years old - " + d.getPhotograph()));
}

int AdministratorGUI::getSelectedIndex() const {
    QModelIndexList selectedIndexes = this->dogsListWidget->selectionModel()->selectedIndexes();
    if (selectedIndexes.size() == 0) {
        this->nameLineEdit->clear();
        this->breedLineEdit->clear();
        this->ageLineEdit->clear();
        this->photographLineEdit->clear();
        return -1;
    }
    int selectedIndex = selectedIndexes.at(0).row();
    return selectedIndex;
}

void AdministratorGUI::connectSignalsAndSlots() {
    QObject::connect(this->addDesignButton, &QPushButton::clicked, this, &AdministratorGUI::addDogDesign);
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdministratorGUI::addDog);
    QObject::connect(this->deleteDesignButton, &QPushButton::clicked, this, &AdministratorGUI::removeDogDesign);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdministratorGUI::removeDog);
    QObject::connect(this->updateDesignButton, &QPushButton::clicked, this, &AdministratorGUI::updateDogDesign);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdministratorGUI::updateDog);
}

void AdministratorGUI::addDogDesign() {
    this->deleteName->setVisible(false);
    this->deleteBreed->setVisible(false);
    this->deleteButton->setVisible(false);

    this->updateName->setVisible(false);
    this->updateBreed->setVisible(false);
    this->updateAge->setVisible(false);
    this->updatePhotograph->setVisible(false);
    this->updateButton->setVisible(false);

    this->addName->setVisible(true);
    this->addBreed->setVisible(true);
    this->addAge->setVisible(true);
    this->addPhotograph->setVisible(true);
    this->addButton->setVisible(true);
}

void AdministratorGUI::addDog() {
    string name = this->addName->text().toStdString();
    string breed = this->addBreed->text().toStdString();
    string age_s = this->addAge->text().toStdString();
    stringstream nb(age_s);
    int age = 0;
    nb >> age;
    string photograph = this->addPhotograph->text().toStdString();
    try {
        this->serv.AddDog(breed, name, age, photograph);
        QMessageBox::information(this, "Success", "The dog was added to the shelter successfully!");
    }  catch (RepoException& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
//    catch (DogException& v) {
//            for (auto s : v.getErrors())
//                QMessageBox::information(this, "Error", s);
//    }

    this->populateList();
    int lastDog = this->serv.GetAll().size() - 1;
    this->dogsListWidget->setCurrentRow(lastDog);

    this->addName->setText("Enter the name");
    this->addBreed->setText("Enter the breed");
    this->addAge->setText("Enter the age");
    this->addPhotograph->setText("Enter the photograph");

    this->addName->setVisible(false);
    this->addBreed->setVisible(false);
    this->addAge->setVisible(false);
    this->addPhotograph->setVisible(false);
    this->addButton->setVisible(false);
}

void AdministratorGUI::removeDogDesign() {
    this->addName->setVisible(false);
    this->addBreed->setVisible(false);
    this->addAge->setVisible(false);
    this->addPhotograph->setVisible(false);
    this->addButton->setVisible(false);

    this->updateName->setVisible(false);
    this->updateBreed->setVisible(false);
    this->updateAge->setVisible(false);
    this->updatePhotograph->setVisible(false);
    this->updateButton->setVisible(false);

    this->deleteName->setVisible(true);
    this->deleteBreed->setVisible(true);
    this->deleteButton->setVisible(true);
}

void AdministratorGUI::removeDog() {
    string name = this->deleteName->text().toStdString();
    string breed = this->deleteBreed->text().toStdString();
    try {
        this->serv.DeleteDog(breed, name);
        QMessageBox::information(this, "Success", "The dog was successfully removed from the shelter!");
    }  catch (RepoException& re) {
        QMessageBox::critical(this, "Error", re.what());
    }
    this->populateList();

    this->deleteName->setText("Enter the name");
    this->deleteBreed->setText("Enter the breed");

    this->deleteName->setVisible(false);
    this->deleteBreed->setVisible(false);
    this->deleteButton->setVisible(false);
}

void AdministratorGUI::updateDogDesign() {
    this->addName->setVisible(false);
    this->addBreed->setVisible(false);
    this->addAge->setVisible(false);
    this->addPhotograph->setVisible(false);
    this->addButton->setVisible(false);

    this->deleteName->setVisible(false);
    this->deleteBreed->setVisible(false);
    this->deleteButton->setVisible(false);

    this->updateName->setVisible(true);
    this->updateBreed->setVisible(true);
    this->updateAge->setVisible(true);
    this->updatePhotograph->setVisible(true);
    this->updateButton->setVisible(true);
}

void AdministratorGUI::updateDog() {
    string name = this->updateName->text().toStdString();
    string breed = this->updateBreed->text().toStdString();
    string age_s = this->updateAge->text().toStdString();
    stringstream nb(age_s);
    int age = 0;
    nb >> age;
    string photograph = this->updatePhotograph->text().toStdString();
    try {
        this->serv.UpdateDog(breed, name, age, photograph);
        QMessageBox::information(this, "Success", "The dog was successfully updated!");
    }  catch (RepoException& re) {
        QMessageBox::critical(this, "Error", re.what());
    }
    this->populateList();

    this->updateBreed->setText("Enter the breed");
    this->updateName->setText("Enter the name");
    this->updateAge->setText("Enter the age");
    this->updatePhotograph->setText("Enter the photograph");

    this->updateName->setVisible(false);
    this->updateBreed->setVisible(false);
    this->updateAge->setVisible(false);
    this->updatePhotograph->setVisible(false);
    this->updateButton->setVisible(false);
}
