#include "GUI.h"
#include <QVBoxLayout>
#include <qlayout.h>
#include <qformlayout.h>
#include <qgridlayout.h>
#include <qlabel.h>
#include <vector>

using namespace std;

GUI::GUI(AdministratorGUI& a, UserGUI& u) : adm{a}, user{u} {this->initGUI();
                                                            this->connectSignalsAndSlots();}

void GUI::initGUI() {
    this->userButton = new QPushButton{"USER"};
    this->administratorButton = new QPushButton{"ADMINISTRATOR"};
    this->modeLabel = new QLabel{};

    QVBoxLayout* modeLayout = new QVBoxLayout{this};
    this->modeLabel->setText("Choose your mode:");
    this->modeLabel->setAlignment(Qt::AlignCenter);
    modeLayout->addWidget(modeLabel);
    QGridLayout* modebuttonsLayout = new QGridLayout{};
    modebuttonsLayout->addWidget(this->administratorButton, 0, 0);
    modebuttonsLayout->addWidget(this->userButton, 0, 1);
    modeLayout->addLayout(modebuttonsLayout);
}

void GUI::connectSignalsAndSlots() {
    QObject::connect(this->administratorButton, &QPushButton::clicked, this, [this]() {
        this->adm.show();
    });
    QObject::connect(this->userButton, &QPushButton::clicked, this, [this]() {
        this->user.show();
    });
}
