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
    virtual void clickLoginButton(); //点击登录按钮
    virtual void clickCancelButton(); //点击取消按钮
    virtual void setIdPasswd(QString, QString); //设置学号和密码
    virtual bool checkUser(QString, QString); // 校验用户是否合法
private:
    Ui::userui *ui;
    Login * LoginUI;
    QVector<info> Userinfo;
};

#endif // USERUI_H
