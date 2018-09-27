#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QDebug>
#include "signup.h"
#include "login.h"
#include "rootui.h"
#include "userui.h"
#include "baseclass.h"
#include "QMessageBox"
#include "signup.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();
    void on_SignupButton_clicked();
    void on_RootLoginButton_clicked();
    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
private:
    userui * userlogin; // 登录
    Signup * signup; // 注册
    RootUI * rootLogin; //管理员
};

#endif // MAINWINDOW_H
