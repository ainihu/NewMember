#include "rootui.h"
#include "ui_rootui.h"

RootUI::RootUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RootUI)
{
    ui->setupUi(this);
}

RootUI::~RootUI()
{
    delete ui;
}

//界面入口
void RootUI::run()
{
    Login * tmp = new Login;
    tmp->run();
}
