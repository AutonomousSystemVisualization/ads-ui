#pragma once


#include <qt5/QtWidgets/QWidget>
#include <qt5/QtWidgets/QPushButton>

// namespace Ui {
class Widget;
// }

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void setupUi(QWidget *Form);

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle("hello");
        push_button->setText("please push me");
    } // retranslateUi

signals:    //添加自定义的信号
    void SendMsg(QString str);  //信号只需要声明，不要给信号写实体代码

public slots:   //接收按钮信号的槽函数
    void ButtonClicked();

private:
    QPushButton *push_button;
};

class ShowMsg : public QObject
{
    Q_OBJECT
public:
    explicit ShowMsg(QObject *parent = 0);
    ~ShowMsg();

signals:

public slots:
    //接收 SendMsg 信号的槽函数
    void RecvMsg(QString str);
};


