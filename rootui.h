#ifndef ROOTUI_H
#define ROOTUI_H

#include <QMainWindow>
#include "login.h"
#include "baseclass.h"
#include <QMessageBox>

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
    QString rootid;
    QString rootpasswd;
    Ui::RootUI *ui;
    Login * LoginUI;
    QVector<info> Userinfo;
public slots:
    void showMainWindow();
signals:
    void Signal_showMainWindow();
};

#endif // ROOTUI_H
