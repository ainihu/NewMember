#ifndef Signup_H
#define Signup_H

#include <QWidget>
#include "baseclass.h"

namespace Ui {
class signup;
}

class Signup : public QWidget, public baseClass
{
    Q_OBJECT

public:
    virtual void clickLoginButton(){}
    virtual void clickCancelButton(){}
    virtual void setIdPasswd(QString, QString){}
    virtual bool checkUser(QString, QString){return false;}
    explicit Signup(QWidget *parent = 0);
    ~Signup();
public:
    void run();
private slots:
    void on_registButton_clicked();

private:
    Ui::signup *ui;
};

#endif // Signup_H
