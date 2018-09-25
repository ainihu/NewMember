#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>
#include <QRegExp>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void run();
private slots:
    void clickLogin();
private:
    Ui::Login *ui;
    QString id;
    QString passwd;
};

#endif // LOGIN_H
