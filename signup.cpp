#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    /* 注册信息
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
    //设置账号和密码的正则
    QRegExp ruleage("[0-9]?[0-9]?");
    this->ui->ageLineEdit->setValidator(new QRegExpValidator(ruleage, this));
    this->ui->ageLineEdit->setPlaceholderText(QString("1-99岁..."));

    QRegExp ruleid("[0-9]{8}");
    this->ui->idLineEdit->setValidator(new QRegExpValidator(ruleid, this));
    this->ui->idLineEdit->setPlaceholderText(QString("学号8位纯数字"));

    QRegExp ruleqq("^[1-9][0-9]{5,11}");
    this->ui->qqLineEdit->setValidator(new QRegExpValidator(ruleqq, this));
    this->ui->qqLineEdit->setPlaceholderText(QString("6-12位纯数字"));

    QRegExp rulephone("^[1-9][0-9]{10}");
    this->ui->phoneLineEdit->setValidator(new QRegExpValidator(rulephone, this));
    this->ui->phoneLineEdit->setPlaceholderText(QString("11位纯数字"));

    QRegExp rulepasswd("[0-9a-zA-Z]{6,12}");
    this->ui->passwdLineEdit->setValidator(new QRegExpValidator(rulepasswd, this));
    this->ui->passwdLineEdit->setPlaceholderText(QString("密码6-12位"));
    this->ui->repasswdLineEdit->setValidator(new QRegExpValidator(rulepasswd, this));
    this->ui->repasswdLineEdit->setPlaceholderText(QString("密码6-12位"));
}

Signup::~Signup()
{
    delete ui;
}

//界面入口
void Signup::run()
{
    this->show();
}

//注册按钮
void Signup::on_registButton_clicked()
{
    //this->ui->idLineEdit->isVisible();
    //是否有相同的id
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
     while(!fd.atEnd())
    {
        data = fd.readLine();
        list = data.split(" ");
        if(list.length() != 7)
            continue;
        if(     this->ui->nameLineEdit->text().length() < 1 || \
                this->ui->ageLineEdit->text().length() < 1 || \
                this->ui->idLineEdit->text().length() != 8 || \
                this->ui->qqLineEdit->text().length() < 6 || \
                this->ui->phoneLineEdit->text().length() != 11 || \
                this->ui->passwdLineEdit->text().length() < 6 || \
                this->ui->repasswdLineEdit->text() != this->ui->passwdLineEdit->text()
                )
        {
            QMessageBox::warning(this, "Warning Message", "检查注册信息格式是否有误", QMessageBox::Ok);
            return;
        }
        if(QString(list.at(3)) == this->ui->idLineEdit->text() || \
                list.at(4) == this->ui->qqLineEdit->text() || \
                list.at(5) == this->ui->phoneLineEdit->text())
        {
            QMessageBox::warning(this, "Warning Message", "id、qq号、phone有重复", QMessageBox::Ok);
            return;
        }
    }
     fd.close();
     fd.open(QFile::Append);
     fd.write(this->ui->nameLineEdit->text().toUtf8() + " ");
     fd.write(QString::number(this->ui->sexComboBox->currentIndex()).toUtf8() + " ");
     fd.write(this->ui->ageLineEdit->text().toUtf8() + " ");
     fd.write(this->ui->idLineEdit->text().toUtf8() + " ");
     fd.write(this->ui->qqLineEdit->text().toUtf8() + " ");
     fd.write(this->ui->phoneLineEdit->text().toUtf8() + " ");
     fd.write(this->ui->passwdLineEdit->text().toUtf8() + "\n");
     QMessageBox::information(this, "Success", "注册成功", QMessageBox::Ok);
     fd.close();
     return;
}

// 取消按钮
void Signup::on_canclePushButton_clicked()
{
    if(this->ui->nameLineEdit->isModified() || \
            this->ui->ageLineEdit->isModified() || \
            this->ui->idLineEdit->isModified() || \
            this->ui->qqLineEdit->isModified() || \
            this->ui->phoneLineEdit->isModified() || \
            this->ui->passwdLineEdit->isModified() || \
            this->ui->repasswdLineEdit->isModified())
    {
        int ret = QMessageBox::information(this, "warning", "退出后信息不会保存，是否确认退出？", QMessageBox::Ok, QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:
            this->hide();
            emit Signal_showMainWindow();
            break;
        case QMessageBox::Cancel:
            break;
        }
    }
    else
    {
        this->hide();
        emit Signal_showMainWindow();
    }

}
