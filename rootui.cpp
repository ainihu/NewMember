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
