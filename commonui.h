#ifndef COMMONUI_H
#define COMMONUI_H

#include "baseclass.h"
#include "login.h"

class CommonUI: public baseClass
{
public:
    CommonUI();
    void run();
    virtual void clickLoginButton(); //点击登录按钮
    virtual void clickCancelButton(); //点击取消按钮
    virtual void setIdPasswd(QString, QString); //设置学号和密码
    virtual bool checkUser(QString, QString); // 校验用户是否合法
private:
    Login * LoginUI;
    QString Path;
    QVector<info> Userinfo;
};

#endif // COMMONUI_H
