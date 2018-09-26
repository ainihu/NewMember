#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>
#include <QRegExp>
#include "baseclass.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(baseClass * , QWidget *parent = 0);
    ~Login();
    void run();
private slots:
    void clickLogin(); //点击登录按钮
    void clickCancel(); //点击取消按钮

private:
    Ui::Login *ui;
    baseClass *  UIthis;
};

#endif // LOGIN_H
