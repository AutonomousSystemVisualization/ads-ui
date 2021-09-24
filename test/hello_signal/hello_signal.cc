#include "hello_signal.h"
#include <qt5/QtWidgets/QMessageBox>
#include <stdio.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QTextBrowser>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);

    //关联
    connect(push_button, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
}

Widget::~Widget()
{
    delete push_button;
}

void Widget::setupUi(QWidget *Form)
{
    if (Form->objectName().isEmpty())
    {
        Form->setObjectName(QStringLiteral("Form"));
    }
    Form->resize(400, 300);
    push_button = new QPushButton(Form);
    push_button->setObjectName(QStringLiteral("label"));
    push_button->setGeometry(QRect(10, 10, 300, 40));

    retranslateUi(Form);

    QMetaObject::connectSlotsByName(Form);
}  // setupUi

//槽函数
void Widget::ButtonClicked()
{
    //用 emit 发信号
    emit SendMsg(tr("This is the message!"));
}


ShowMsg::ShowMsg(QObject *parent) : QObject(parent)
{

}

ShowMsg::~ShowMsg()
{

}

//str 就是从信号里发过来的字符串
void ShowMsg::RecvMsg(QString str)
{
    QMessageBox::information(NULL, tr("Show"), str);
}
