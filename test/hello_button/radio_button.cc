#include "radio_button.h"
#include <qt5/QtCore/QDebug>
#include <qt5/QtWidgets/QApplication>
#include <qt5/QtWidgets/QButtonGroup>
#include <qt5/QtWidgets/QGroupBox>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtWidgets/QMessageBox>
#include <qt5/QtWidgets/QRadioButton>
#include <qt5/QtWidgets/QWidget>

// model-view-control, design mode
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGroupBox box;
    box.setTitle("plan method");
    box.resize(600, 300);

    QRadioButton *radio1;
    QRadioButton *radio2;

    QRadioButton *radio3;
    QRadioButton *radio4;
    QButtonGroup *m_pGenderGroup;  //性别单选按钮分组
    m_pGenderGroup = new QButtonGroup(&box);

    radio1 = new QRadioButton("method 1", &box);
    radio1->setGeometry(QRect(10, 10, 100, 40));

    radio2 = new QRadioButton("method 2", &box);
    radio2->setGeometry(QRect(200, 10, 100, 40));

    //新建性别虚拟分组，并添加按钮和id
    m_pGenderGroup->addButton(radio1, 0);
    m_pGenderGroup->addButton(radio2, 1);

    //显示主界面
    box.show();

    return a.exec();
}