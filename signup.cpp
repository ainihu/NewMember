#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
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
