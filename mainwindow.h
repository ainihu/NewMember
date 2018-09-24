#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QDebug>
#include "signup.h"
#include "login.h"
#include "rootui.h"

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
    Login * login = new Login;
    Signup * signup = new Signup;
};

#endif // MAINWINDOW_H
