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
    void clickLogin();
    void clickCancel();
private:
    Ui::Login *ui;
    baseClass *  UIthis;
};

#endif // LOGIN_H
