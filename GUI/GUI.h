#pragma once
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include "service.h"
#include "AdministratorGUI.h"
#include "UserGUI.h"

class GUI : public QWidget {
private:
    AdministratorGUI& adm;
    UserGUI& user;

    // graphical elements
    QPushButton* userButton, * administratorButton;
    QLabel* modeLabel;
    void initGUI();
    void connectSignalsAndSlots();
public:
    GUI(AdministratorGUI&, UserGUI&);
};
