#include <stdio.h>
#include <QApplication>
#include <QMainWindow>
#include <iostream>
#include <memory>
#include <qt5/QtWidgets/QLabel>
#include <qt5/QtWidgets/QWidget>

class window_test : public QWidget
{
    Q_OBJECT  // window包含基本的api， moc工具会生成真正的实现代码
private :
    /* data */
public :
    explicit window_test(QWidget *parent);  // 父窗口为空
    ~window_test();

    std::shared_ptr<QLabel> label;
};