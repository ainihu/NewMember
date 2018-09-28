#include "userui.h"
#include "ui_userui.h"
#include <qdebug.h>
#include <qiodevice.h>
#include <QStringList>
#include "login.h"
#include "baseclass.h"

userui::userui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::userui)
{
    ui->setupUi(this);
    this->LoginUI = new Login();
}
//界面入口
void userui::run()
{
    const QString path = "../NewMember/info/common.txt";
    QString data;
    QFile fd(path);
    QStringList list;
    info tmp;
/*
    info currentUser;
    Ui::userui *ui;
    Login * LoginUI;
    QVector<info> Userinfo;
*/
    //初始化环境
    this->Userinfo.clear();

    bool ret = fd.open(QIODevice::ReadOnly);
    if(ret == false)
    {
        exit(EXIT_FAILURE);
    }
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
    this->LoginUI->run(this);
}

void userui::clickLoadoutButton()
{

}
void userui::clickCancelButton()
{
    this->hide();
    // emit this->cancle(this);
}

void userui::checkUser(QString id, QString passwd)
{
    foreach (info it, this->Userinfo) {
        if(it.id == id.toInt() && it.passwd == passwd)
        {
            this->ui->idLineEdit->clear();
            this->ui->passwdLineEdit->clear();
            this->currentUser.name += it.name;
            this->currentUser.sex += it.sex;
            this->currentUser.age += it.age;
            this->currentUser.id += it.id;
            this->currentUser.qq += it.qq;
            this->currentUser.phone += it.phone;
            this->currentUser.passwd += it.passwd;

            this->LoginUI->hide();
            this->show();
            break;
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
        }
    }
}

userui::~userui()
{
    delete ui;
}
