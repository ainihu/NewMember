#ifndef Signup_H
#define Signup_H

#include <QWidget>
#include "baseclass.h"

namespace Ui {
class signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    virtual void clickLoginButton(){}
    virtual void clickCancelButton(){}
    virtual bool checkUser(QString, QString){return false;}
    explicit Signup(QWidget *parent = 0);
    ~Signup();
public:
    void run();
private slots:
    void on_registButton_clicked();

    void on_canclePushButton_clicked();

private:
    Ui::signup *ui;
};

#endif // Signup_H
