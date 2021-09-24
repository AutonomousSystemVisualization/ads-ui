#include <qt5/QtWidgets/qaction.h>
#include <stdio.h>
#include <QApplication>
#include <QMainWindow>
#include <qt5/QtWidgets/QLabel>
#include "hello_signal.h"

// model-view-control, design mode
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;   //①主窗体对象，内部会发送 SendMsg 信号
    ShowMsg s;  //②接收端对象，有槽函数 RecvMsg
    //③关联，信号里的字符串参数会自动传递给槽函数
    QObject::connect(&w, SIGNAL(SendMsg(QString)), &s, SLOT(RecvMsg(QString)));

    //显示主界面
    w.show();

    return a.exec();
}