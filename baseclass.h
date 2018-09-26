#ifndef BASECLASS_H
#define BASECLASS_H

#include "QString"
#include "QDebug"

class baseClass
{
public:
    baseClass();
    virtual void clickLoginButton() = 0;
    virtual void clickCancelButton() = 0;
    virtual void setIdPasswd(QString, QString) = 0;
    virtual bool checkUser(QString, QString) = 0;
};

struct info
{
    QString name;
    bool sex;
    int age;
    int id;
    QString qq;
    QString phone;
};
#endif // BASECLASS_H
