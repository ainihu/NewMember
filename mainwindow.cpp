#include "mainwindow.h"
#include "baseclass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// 普通用户登录
void MainWindow::on_LoginButton_clicked()
{
    this->hide();
    this->userlogin = new userui;
    if(this->userlogin == nullptr)
        exit(EXIT_FAILURE);
    this->userlogin->run();
}

// 普通用户注册
void MainWindow::on_SignupButton_clicked()
{
    this->hide();
    this->signup = new Signup;
    if(this->signup == nullptr)
        exit(EXIT_FAILURE);
    this->signup->run();
}

// 管理员登录
void MainWindow::on_RootLoginButton_clicked()
{
    this->hide();
    this->rootLogin = new RootUI;
    if(this->rootLogin == nullptr)
        exit(EXIT_FAILURE);
    this->rootLogin->run();
}

//退出
void MainWindow::on_ExitButton_clicked()
{

    int ret = QMessageBox::warning(nullptr, "Warning", "是否确定退出", QMessageBox::Ok | QMessageBox::Cancel);
    switch(ret)
    {
    case QMessageBox::Ok:
    {
        exit(EXIT_SUCCESS);
    }break;
    case QMessageBox::Cancel:
    {
        return ;
    }break;
    default:break;
    }
}

void MainWindow::on_CancleButton_clicked()
{
    this->show();
    //cancel->hide();
}

