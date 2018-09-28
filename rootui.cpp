#include "rootui.h"
#include "ui_rootui.h"

RootUI::RootUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RootUI)
{
    ui->setupUi(this);
    this->Path = "E:\Git\NewMember\NewMember\info\root.txt";
}

RootUI::~RootUI()
{
    delete ui;
}

//界面入口
void RootUI::run()
{
    QString id, passwd;
    Login * tmp = new Login();

    tmp->run(this);
}

void RootUI::clickLoginButton()
{

} 
void RootUI::clickCancelButton()
{

}
void RootUI::checkUser(QString id, QString passwd)
{
    return ;
}
