#ifndef ROOTUI_H
#define ROOTUI_H

#include <QMainWindow>

namespace Ui {
class RootUI;
}

class RootUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit RootUI(QWidget *parent = 0);
    ~RootUI();

private:
    Ui::RootUI *ui;
};

#endif // ROOTUI_H
