#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "signup.h"
#include "login.h"
#include "rootui.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // QObject::connect(this)
    //signup * tmp = new signup;
    //Login * tmp = new Login;
    //tmp->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 普通用户登录
void MainWindow::on_LoginButton_clicked()
{
    Login * tmp = new Login;
    tmp->show();
    this->hide();
}

// 普通用户注册
void MainWindow::on_SignUpButton_clicked()
{
    signup * tmp = new signup();
    tmp->show();
    this->hide();
}

// 管理员登录
void MainWindow::on_RootLoginButton_clicked()
{
    RootUI * tmp = new RootUI();
    tmp->show();
    this->hide();
}

void MainWindow::on_ExitButton_clicked()
{
    exit(EXIT_SUCCESS);
}
