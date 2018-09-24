#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    //ui->setupUi(this);
    this->setWindowTitle("注册");
    //ui->setAutoFillBackground(true);
}

Signup::~Signup()
{
    delete ui;
}
