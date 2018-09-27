#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    this->setWindowTitle("登录");

    ui->id->setPlaceholderText(QString("学号8位纯数字"));
    ui->passwd->setPlaceholderText(QString("登录密码"));

    //设置账号和密码的正则
    QRegExp rule("[0-9]{8}");
    ui->id->setValidator(new QRegExpValidator(rule, this));
    QRegExp rule1("[0-9a-zA-Z]{6,12}");
    ui->passwd->setValidator(new QRegExpValidator(rule1, this));


    // 连接登录按钮信号和槽
    connect(this->ui->LoginButton, SIGNAL(clicked()), this, SLOT(clickLogin()));
    // 连接取消按钮信号和槽
    connect(this->ui->CancelButton, SIGNAL(clicked()), this, SLOT(clickCancel()));
}

Login::~Login()
{
    delete ui;
}

//界面入口
void Login::run(baseClass * UIthis = nullptr)
{
    this->UIthis = UIthis;
    if(this->UIthis == nullptr)
        return;
    else
    {
        this->show();
    }
}

// 登录按钮
void Login::clickLogin()
{
    QString id = ui->id->text();
    QString passwd = ui->passwd->text();
    bool tmp = this->UIthis->checkUser(id, passwd);
    if(tmp)
    {
        this->UIthis->setIdPasswd(id, passwd);
    }
}

// 取消按钮
void Login::clickCancel()
{
    // qDebug() << "cancel";
}
