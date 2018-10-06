#ifndef USERUI_H
#define USERUI_H

#include "baseclass.h"
#include "login.h"
#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardPaths>

namespace Ui {
class userui;
}

class userui : public QMainWindow, public baseClass
{
    Q_OBJECT

public:
    explicit userui(QWidget *parent = 0);
    ~userui();
    void run();
    virtual void checkUser(QString, QString); // 校验用户是否合法
    void setInfo();
public slots:
    void showMainWindow();
    virtual void clickLoginButton(){} //点击登录按钮
    virtual void clickCancelButton(); //点击取消按钮
    void clickLoadoutButton();//导出信息
private:
    void WriteUserinfo();
    info currentUser;
    Ui::userui *ui;
    Login * LoginUI;
    QVector<info> Userinfo;
signals:
    void Signal_showMainWindow();
};

#endif // USERUI_H
