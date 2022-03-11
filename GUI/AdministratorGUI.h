#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qformlayout.h>
#include "service.h"

class AdministratorGUI: public QWidget {
private:
    Service& serv;

    // graphical elements
    QPushButton* backButton, * listDesignButton, * addDesignButton, * deleteDesignButton, * updateDesignButton, * addButton, * deleteButton, * updateButton;
    QListWidget* dogsListWidget;
    QLineEdit* nameLineEdit, * breedLineEdit, * ageLineEdit, * photographLineEdit, * modeLineEdit, * addName, * addBreed, * addAge, * addPhotograph, * deleteName, * deleteBreed,
    * updateName, * updateBreed, * updateAge, * updatePhotograph;
    QFormLayout* addFormLayout, * removeFormLayout, * updateFormLayout;
    QVBoxLayout* administratorLayout;

    void initAdmGUI();
    void populateList();
    void connectSignalsAndSlots();
    void addDogDesign();
    void addDog();
    void removeDogDesign();
    void removeDog();
    void updateDogDesign();
    void updateDog();
    int getSelectedIndex() const;
public:
    AdministratorGUI(Service&);
};
