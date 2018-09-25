#include "commonui.h"
#include "login.h"

CommonUI::CommonUI()
{

}

//界面入口
void CommonUI::run()
{
    Login * tmp = new Login;
    tmp->run();
}
