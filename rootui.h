#ifndef ROOTUI_H
#define ROOTUI_H

#include <QMainWindow>
#include "login.h"
#include "baseclass.h"

namespace Ui {
class RootUI;
}

class RootUI : public QMainWindow, public baseClass
{
    Q_OBJECT

public:
    explicit RootUI(QWidget *parent = 0);
    ~RootUI();
    void run();
    virtual void clickLoginButton();
    virtual void clickCancelButton();
    virtual void checkUser(QString, QString);
private:
    Ui::RootUI *ui;
    QString Path;
    QVector<info> Userinfo;
};

#endif // ROOTUI_H
