#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplication2.h"

class QtWidgetsApplication2 : public QMainWindow
{
    Q_OBJECT


public:
    QtWidgetsApplication2(QWidget *parent = nullptr);
    ~QtWidgetsApplication2();

private:
    Ui::QtWidgetsApplication2Class ui;
};
