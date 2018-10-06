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
    connect(this->LoginUI, SIGNAL(cancelLogin()), this, SLOT(showMainWindow()));
    connect(this->ui->canclePushButton, SIGNAL(clicked()), this, SLOT(clickCancelButton()));
    connect(this->ui->SaveAsInfo, SIGNAL(clicked()), this, SLOT(clickLoadoutButton()));
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
        data.trimmed();
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
    //qDebug() << QStandardPaths::writableLocation(QStandardPaths::DesktopLocation).toUtf8();
    bool iswrite = true;


    QString savepathname = QFileDialog::getSaveFileName(this, "Save Info", \
                           QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), \
                           "*.txt");

    //qDebug() << savepathname;
    if(QFile::exists(savepathname))
    {
        int ret = QMessageBox::warning(this, "Warning", "请再次确认是否覆盖?", QMessageBox::Ok | QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:
            iswrite = true;
            break;
        case QMessageBox::Cancel:
            iswrite = false;
            break;
        }
    }
    if(iswrite && !savepathname.isEmpty())
    {
        QFile save(savepathname);
        save.open(QFile::WriteOnly);
        save.write("name:" + this->currentUser.name.toUtf8() + "\n");
        save.write("sex:" + QString(this->currentUser.sex ? "男":"女").toUtf8() + "\n");
        save.write("age:" + QString("%1").arg(QString::number(this->currentUser.age)).toUtf8() + "\n");
        save.write("id:" + QString("%1").arg(QString::number(this->currentUser.id)).toUtf8() + "\n");
        save.write("qq:" + this->currentUser.qq.toUtf8() + "\n");
        save.write("phone:" + this->currentUser.phone.toUtf8() + "\n");
        save.close();
        QMessageBox::information(this, "Success", "保存成功", QMessageBox::Ok);
    }
    return ;
}
void userui::clickCancelButton()
{
    int ret = QMessageBox::warning(this, "Warning", "是否退出登录", QMessageBox::Ok | QMessageBox::Cancel);
     switch (ret) {
     case QMessageBox::Ok:
         this->hide();
         this->LoginUI->run(this);
         break;
     case QMessageBox::Cancel:
         break;
     }
}

void userui::showMainWindow()
{
    this->hide();
    emit this->Signal_showMainWindow();
}

void userui::checkUser(QString id, QString passwd)
{
    foreach (info it, this->Userinfo)
    {
        if(it.id == id.toInt() && it.passwd.trimmed() == passwd)
        {
            this->ui->idLineEdit->clear();
            this->ui->passwdLineEdit->clear();
            this->currentUser.name = it.name;
            this->currentUser.sex = it.sex;
            this->currentUser.age = it.age;
            this->currentUser.id = it.id;
            this->currentUser.qq = it.qq;
            this->currentUser.phone = it.phone;
            this->currentUser.passwd = it.passwd;

            this->LoginUI->hide();
            this->WriteUserinfo();
            this->show();
            return ;

        }
    }
    QMessageBox::warning(nullptr, "Warning Message", "密码或者用户名错误", QMessageBox::Ok);
}

userui::~userui()
{
    delete ui;
}


void userui::WriteUserinfo()
{
    this->ui->nameLineEdit->setReadOnly(true);
    this->ui->sexLineEdit->setReadOnly(true);
    this->ui->ageLineEdit->setReadOnly(true);
    this->ui->idLineEdit->setReadOnly(true);
    this->ui->qqLineEdit->setReadOnly(true);
    this->ui->phoneLineEdit->setReadOnly(true);
    this->ui->passwdLineEdit->setReadOnly(true);

    this->ui->nameLineEdit->setText(this->currentUser.name);
    this->ui->sexLineEdit->setText(this->currentUser.sex ? "男":"女");
    this->ui->ageLineEdit->setText(QString::number(this->currentUser.age));
    this->ui->idLineEdit->setText(QString::number(this->currentUser.id));
    this->ui->qqLineEdit->setText(this->currentUser.qq);
    this->ui->phoneLineEdit->setText(this->currentUser.phone);
    this->ui->passwdLineEdit->setText(this->currentUser.passwd);
}
