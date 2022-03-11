#pragma once
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qlistwidget.h>
#include <qboxlayout.h>
#include <qformlayout.h>
#include "service.h"

class UserGUI: public QWidget {
private:
    Service& serv;

    QVBoxLayout* userLayout;
    QPushButton* adoptButton, * saveButton, * listButton, * adoptDogButton, * saveListButton, * doneAdoptButton, * nextButton, * filterButton, * okButton;
    QLineEdit* nameLineEdit, * breedLineEdit, * ageLineEdit, * photographLineEdit, * saveLineEdit, * filterbreedLineEdit, * filterageLineEdit;
    QListWidget* dogsListWidget, * adoptionListWidget;
    QFormLayout* adoptLayout;

    void initUserGUI();
    void populateList();
    void populateAdoptionList();
    void connectSignalsAndSlots();
    void adopt();
    void saveList();
    void showList();
    int getSelectedIndex() const;

public:
    UserGUI(Service&);
};
