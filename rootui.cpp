#include "rootui.h"
#include "ui_rootui.h"
#include "login.h"
#include <QStringList>

RootUI::RootUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RootUI)
{
    ui->setupUi(this);
    this->LoginUI = new Login();
    connect(this->LoginUI, SIGNAL(cancelLogin()), this, SLOT(showMainWindow()));
}

RootUI::~RootUI()
{
    delete ui;
}

//界面入口
void RootUI::run()
{
    const QString path = "../NewMember/info/root.txt";
    QString data;
    QFile fd(path);
    fd.open(QIODevice::ReadOnly);

    data = fd.readLine();
    QStringList rootinfo = data.split(" ");
    if(rootinfo.length() != 2)
        exit(EXIT_FAILURE);
    this->rootid = rootinfo.at(0);
    this->rootpasswd = rootinfo.at(1);
    this->LoginUI->run(this);
}

void RootUI::clickLoginButton()
{

} 

void RootUI::clickCancelButton()
{

}

void RootUI::showMainWindow()
{
    this->LoginUI->hide();
    emit this->Signal_showMainWindow();
}

void RootUI::checkUser(QString id, QString passwd)
{
    if(id == this->rootid && passwd == this->rootpasswd)
    {
        this->LoginUI->hide();
        this->show();
    }
    else
    {
        QMessageBox::warning(this, "Warning", "账号或密码错误");
    }
    return ;
}
