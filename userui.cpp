#include "userui.h"
#include "ui_userui.h"
#include <qdebug.h>
#include <qiodevice.h>
#include <QStringList>
#include "login.h"

userui::userui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userui)
{
    ui->setupUi(this);
    this->LoginUI = new Login();
    const QString path = "../NewMember/info/common.txt";
    QString data;
    QFile fd(path);
    QStringList list;
    info tmp;

    bool ret = fd.open(QIODevice::ReadOnly);
    if(ret == false)
    {
        exit(EXIT_FAILURE);
    }
    /*
struct info
{
    QString name;
    bool sex;
    int age;
    int id;
    QString qq;
    QString phone;
    QString passwd;
};
    */
     while(!fd.atEnd())
    {
        data = fd.readLine();
        list = data.split(" ");
        if(list.length() != 7)
            continue;
        tmp.name = list.at(0);
        tmp.sex = bool(list.at(1)[0] == '1');
        tmp.age = QString(list.at(2)).toInt();
        tmp.id = QString(list.at(3)).toInt();
        tmp.qq = list.at(4);
        tmp.phone = list.at(5);
        tmp.passwd = list.at(6);
        this->Userinfo.append(tmp);
    }
}
//界面入口
void userui::run()
{
    if(this->LoginUI == nullptr)
        this->LoginUI = new Login();
    this->LoginUI->run(this);
}


void userui::clickLoginButton()
{

    delete this->LoginUI;
    this->LoginUI = nullptr;

}

void userui::clickCancelButton()
{

}

bool userui::checkUser(QString id, QString passwd)
{
    foreach (info it, this->Userinfo) {
        if(it.id == id.toInt() && it.passwd == passwd)
            return true;
    }
    return false;
}

void userui::setIdPasswd(QString id, QString passwd)
{

    delete this->LoginUI;
    this->LoginUI = nullptr;
}

userui::~userui()
{
    delete ui;
}
