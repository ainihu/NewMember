#include "mainwindow.h"

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
    this->login->show();
    this->hide();
}

// 普通用户注册
void MainWindow::on_SignupButton_clicked()
{
    this->hide();
}

// 管理员登录
void MainWindow::on_RootLoginButton_clicked()
{
    RootUI * tmp = new RootUI();
    this->hide();
    tmp->run();
}

void MainWindow::on_ExitButton_clicked()
{
    exit(EXIT_SUCCESS);
}
