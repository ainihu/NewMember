#ifndef Signup_H
#define Signup_H

#include <QWidget>

namespace Ui {
class signup;
}

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = 0);
    ~Signup();

private:
    Ui::signup *ui;
};

#endif // Signup_H
