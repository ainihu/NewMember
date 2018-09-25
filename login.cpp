#include "login.h"
#include "ui_login.h"

Login::Login(baseClass * UIthis,  QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login), UIthis(UIthis)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    //设置账号和密码的正则
    QRegExp rule("[0-9a-zA-Z]{6,12}");
    ui->id->setValidator(new QRegExpValidator(rule, this));
    ui->passwd->setValidator(new QRegExpValidator(rule, this));


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
void Login::run()
{
    this->show();
}

// 登录按钮
void Login::clickLogin()
{
    QString id = ui->id->text();
    QString passwd = ui->passwd->text();

    if(this->UIthis->checkUser(id, passwd))
    {
        this->UIthis->setIdPasswd(id, passwd);
    }
    qDebug() << "login";
}

// 取消按钮
void Login::clickCancel()
{
    qDebug() << "cancel";
}
