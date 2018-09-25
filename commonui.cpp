#include "commonui.h"

CommonUI::CommonUI()
{
    this->LoginUI = new Login(this);
}

//界面入口
void CommonUI::run()
{
    this->LoginUI->run();
}


void CommonUI::clickLoginButton()
{

}

void CommonUI::clickCancelButton()
{

}
bool CommonUI::checkUser(QString id, QString passwd)
{
    return true;
}
void CommonUI::setIdPasswd(QString id, QString passwd)
{

}
