#ifndef COMMONUI_H
#define COMMONUI_H

#include "baseclass.h"
#include "login.h"

class CommonUI: public baseClass
{
public:
    CommonUI();
    void run();
    virtual void clickLoginButton();
    virtual void clickCancelButton();
    virtual void setIdPasswd(QString, QString);
    virtual bool checkUser(QString, QString);
private:
    Login * LoginUI;
    QString Path;
};

#endif // COMMONUI_H
