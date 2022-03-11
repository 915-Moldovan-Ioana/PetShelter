#include "UserGUI.h"
#include "RepoExceptions.h"
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <vector>
#include <sstream>
#include <qmessagebox.h>
using namespace std;

UserGUI::UserGUI(Service& s) : serv{s} {this->initUserGUI();
                                       this->populateList();
                                       this->connectSignalsAndSlots();}

void UserGUI::initUserGUI() {
    this->adoptButton = new QPushButton{"Adopt a dog"};
    this->listButton = new QPushButton{"See my adoption list"};
    this->saveButton = new QPushButton{"Save my adoption list"};
    this->adoptDogButton = new QPushButton{"Adopt"};
    this->filterButton = new QPushButton{"Filter"};
    this->okButton = new QPushButton{"OK"};
    this->nextButton = new QPushButton{"Next"};
    this->saveListButton = new QPushButton{"Save"};
    this->doneAdoptButton = new QPushButton{"Done"};
    this->nameLineEdit = new QLineEdit{};
    this->breedLineEdit = new QLineEdit{};
    this->ageLineEdit = new QLineEdit{};
    this->photographLineEdit = new QLineEdit{};
    this->filterbreedLineEdit = new QLineEdit{};
    this->filterageLineEdit = new QLineEdit{};
    this->saveLineEdit = new QLineEdit{};
    this->dogsListWidget = new QListWidget{};
    this->adoptionListWidget = new QListWidget{};

    this->userLayout = new QVBoxLayout{this};

    // adopt
    userLayout->addWidget(this->adoptButton);
    this->userLayout->addWidget(this->dogsListWidget);
    this->dogsListWidget->setVisible(false);
//    this->userLayout->addWidget(this->nameLineEdit);
//    this->nameLineEdit->setText("Enter the name");
//    this->nameLineEdit->setVisible(false);
//    this->userLayout->addWidget(this->breedLineEdit);
//    this->breedLineEdit->setText("Enter the breed");
//    this->breedLineEdit->setVisible(false);
//    this->userLayout->addWidget(this->ageLineEdit);
//    this->ageLineEdit->setText("Enter the age");
//    this->ageLineEdit->setVisible(false);
//    this->userLayout->addWidget(this->photographLineEdit);
//    this->photographLineEdit->setText("Enter the photograph");
//    this->photographLineEdit->setVisible(false);
    this->userLayout->addWidget(this->adoptDogButton, 1);
    this->adoptDogButton->setVisible(false);
//    this->userLayout->addWidget(this->nextButton);
//    this->nextButton->setVisible(false);
    this->userLayout->addWidget(this->filterButton);
    this->filterButton->setVisible(false);
    this->userLayout->addWidget(this->filterbreedLineEdit);
    this->filterbreedLineEdit->setText("Breed");
    this->filterbreedLineEdit->setVisible(false);
    this->userLayout->addWidget(this->filterageLineEdit);
    this->filterageLineEdit->setText("Maximum age");
    this->filterageLineEdit->setVisible(false);
    this->userLayout->addWidget(this->okButton);
    this->okButton->setVisible(false);
    this->userLayout->addWidget(this->doneAdoptButton);
    this->doneAdoptButton->setVisible(false);

    // save
    userLayout->addWidget(this->saveButton);
    this->userLayout->addWidget(this->saveLineEdit);
    this->saveLineEdit->setText("Enter the file path");
    this->saveLineEdit->setVisible(false);
    this->userLayout->addWidget(this->saveListButton);
    this->saveListButton->setVisible(false);

    // see
    userLayout->addWidget(this->listButton);
}

void UserGUI::connectSignalsAndSlots() {
    QObject::connect(this->adoptDogButton, &QPushButton::clicked, this, &UserGUI::adopt);
    QObject::connect(this->adoptButton, &QPushButton::clicked, this, [this]() {
        this->saveLineEdit->setVisible(false);
        this->saveListButton->setVisible(false);

        this->dogsListWidget->setVisible(true);
        this->adoptDogButton->setVisible(true);
//        this->nextButton->setVisible(true);
        this->filterButton->setVisible(true);
        this->doneAdoptButton->setVisible(true);
    });
    QObject::connect(this->saveListButton, &QPushButton::clicked, this, &UserGUI::saveList);
    QObject::connect(this->doneAdoptButton, &QPushButton::clicked, this, [this]() {
        this->dogsListWidget->setVisible(false);
        this->adoptDogButton->setVisible(false);
//        this->nextButton->setVisible(false);
        this->filterButton->setVisible(false);
        this->doneAdoptButton->setVisible(false);
        this->filterbreedLineEdit->setVisible(false);
        this->filterageLineEdit->setVisible(false);
        this->okButton->setVisible(false);
    });
    QObject::connect(this->saveButton, &QPushButton::clicked, this, [this]() {
        this->dogsListWidget->setVisible(false);
        this->adoptDogButton->setVisible(false);
//        this->nextButton->setVisible(false);
        this->filterButton->setVisible(false);
        this->doneAdoptButton->setVisible(false);
        this->filterbreedLineEdit->setVisible(false);
        this->filterageLineEdit->setVisible(false);
        this->okButton->setVisible(false);

        this->saveLineEdit->setVisible(true);
        this->saveListButton->setVisible(true);
    });
    QObject::connect(this->listButton, &QPushButton::clicked, this, [this]() {
        this->saveLineEdit->setVisible(false);
        this->saveListButton->setVisible(false);

        this->dogsListWidget->setVisible(false);
        this->adoptDogButton->setVisible(false);
//        this->nextButton->setVisible(false);
        this->filterButton->setVisible(false);
        this->doneAdoptButton->setVisible(false);
        this->filterbreedLineEdit->setVisible(false);
        this->filterageLineEdit->setVisible(false);
        this->okButton->setVisible(false);

        this->serv.OpenList();
    });
    QObject::connect(this->filterButton, &QPushButton::clicked, this, [this]() {
        this->filterbreedLineEdit->setVisible(true);
        this->filterageLineEdit->setVisible(true);
        this->okButton->setVisible(true);
    });
    QObject::connect(this->okButton, &QPushButton::clicked, this, [this]() {
        string breed = this->filterbreedLineEdit->text().toStdString();
        string age_s = this->filterageLineEdit->text().toStdString();
        stringstream nb(age_s);
        int age = 0;
        nb >> age;
        this->dogsListWidget->clear();
        vector<Dog> allDogs;
        this->serv.FilterDogs(&allDogs, breed, age);
        for(Dog& d : allDogs)
            this->dogsListWidget->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + to_string(d.getAge()) + " years old - " + d.getPhotograph()));

        this->filterbreedLineEdit->setText("Breed");
        this->filterageLineEdit->setText("Maximum age");
        this->filterbreedLineEdit->setVisible(false);
        this->filterageLineEdit->setVisible(false);
        this->okButton->setVisible(false);
    });
    QObject::connect(this->dogsListWidget, &QListWidget::itemSelectionChanged, this, [this]() {
        int i = this->getSelectedIndex();
        if (i < 0)
            return;
        Dog d = this->serv.GetAll()[i];
        this->nameLineEdit->setText(QString::fromStdString(d.getName()));
        this->breedLineEdit->setText(QString::fromStdString(d.getBreed()));
        this->photographLineEdit->setText(QString::fromStdString(d.getPhotograph()));
        this->ageLineEdit->setText(QString::fromStdString(to_string(d.getAge())));
    });
}

void UserGUI::populateList() {
    this->dogsListWidget->clear();
    vector<Dog> allDogs = this->serv.GetAll();
    for(Dog& d : allDogs)
        this->dogsListWidget->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + to_string(d.getAge()) + " years old - " + d.getPhotograph()));
}

void UserGUI::populateAdoptionList() {
    this->adoptionListWidget->clear();
    vector<Dog> allDogs = this->serv.GetAdoptionList();
    for(Dog& d : allDogs)
        this->adoptionListWidget->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + to_string(d.getAge()) + " years old - " + d.getPhotograph()));
}

int UserGUI::getSelectedIndex() const {
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

void UserGUI::adopt() {
    int i = this->getSelectedIndex();
    if (i < 0)
        return;
    Dog d = this->serv.GetAll()[i];
    try {
        this->serv.AdoptDog(d);
        QMessageBox::information(this, "Success", "Congratulations!");
    }  catch (RepoException &re) {
        QMessageBox::critical(this, "Error", re.what());
    }
}

void UserGUI::saveList() {    
    string name = this->saveLineEdit->text().toStdString();
    try {
        this->serv.SaveList(name);
        QMessageBox::information(this, "Success", "The adoption list was successfully saved!");
    }  catch (FileException& fe) {
        QMessageBox::critical(this, "Error", fe.what());
    }

    this->saveLineEdit->setVisible(false);
    this->saveListButton->setVisible(false);
    this->saveLineEdit->setText("Enter the file path");
}
