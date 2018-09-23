#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    //ui->setAutoFillBackground(true);
}

signup::~signup()
{
    delete ui;
}
