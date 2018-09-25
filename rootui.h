#ifndef ROOTUI_H
#define ROOTUI_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class RootUI;
}

class RootUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit RootUI(QWidget *parent = 0);
    ~RootUI();
    void run();

private:
    Ui::RootUI *ui;
};

#endif // ROOTUI_H
