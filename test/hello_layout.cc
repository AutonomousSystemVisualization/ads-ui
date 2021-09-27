#include <qt5/QtWidgets/qaction.h>
#include <stdio.h>
#include <QApplication>
#include <QMainWindow>
#include <qt5/QtWidgets/QBoxLayout>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QLineEdit>
#include <qt5/QtWidgets/QPushButton>

// model-view-control, design mode
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget w;

    QPushButton button; /*按钮是窗口*/
    button.setText("Button");
    button.setParent(&w);  //窗口对象的父子关系:设置父窗口是button
                           // button.setGeometry(30, 30, 100, 30);
    // //坐标原点在窗口的左上角[不包括工具栏]

    QLineEdit edit;
    edit.setParent(&w);

    QHBoxLayout Layout;
    Layout.addStretch(1);
    Layout.addWidget(&button, 1);
    Layout.addSpacing(50);
    Layout.addWidget(&edit, 1);
    Layout.addStretch(1);
    w.setLayout(&Layout);

    w.setWindowTitle("hello");
    w.show();

    app.exec();
    return 0;
}