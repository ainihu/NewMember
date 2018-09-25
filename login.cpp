#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    connect(ui->LoginButton, SIGNAL(clicked()), this,SLOT(clickLogin()));
    //设置账号和密码的正则
    QRegExp rule("[0-9a-zA-Z]{6,12}");
    ui->id->setValidator(new QRegExpValidator(rule, this));
    ui->passwd->setValidator(new QRegExpValidator(rule, this));
}

Login::~Login()
{
    delete ui;
}

//界面入口
void Login::run()
{
    this->show();
}

//private slots
void Login::clickLogin()
{
    this->id = ui->id->text();
    this->passwd = ui->passwd->text();
}
