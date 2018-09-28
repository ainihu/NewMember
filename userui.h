#ifndef USERUI_H
#define USERUI_H

#include "baseclass.h"
#include "login.h"
#include <QWidget>
#include <QMainWindow>

namespace Ui {
class userui;
}

class userui : public QMainWindow, public baseClass
{
    Q_OBJECT

public:
    explicit userui(QWidget *parent = 0);
    ~userui();
    void run();
    virtual void clickLoginButton(){} //点击登录按钮
    virtual void clickCancelButton(); //点击取消按钮
    virtual void checkUser(QString, QString); // 校验用户是否合法
    void clickLoadoutButton();
    void setInfo();
private slots:
    void on_canclePushButton_clicked();

private:
    info currentUser;
    Ui::userui *ui;
    Login * LoginUI;
    QVector<info> Userinfo;
};

#endif // USERUI_H
