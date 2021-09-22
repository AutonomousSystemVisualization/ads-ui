#include "hello_ui.h"
#include <memory>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>


// model-view-control, design mode
int main(int argc, char *argv[])
{
    printf("hello qt \n");
    QApplication app(argc, argv);

    QWidget *hw = new QWidget();    //main GUI window
    Ui::Form createUi;      //createUi is not a real window
    createUi.setupUi(hw);   //createUi is a tool for creating the GUI
    hw->setStyleSheet("color: white; background-color: rgb(40, 44, 52)");
    hw->show();   

    app.exec();
    delete hw;
    return 0;
}