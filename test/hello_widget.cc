#include "hello_widget.h"

window_test::window_test(QWidget *parent = 0) : QWidget(parent)
{
    this->setMinimumSize(1000, 800);      // 主窗口初始化
    label = std::make_shared<QLabel>();
    label->setText("<h1>hello widget</h1>!");
    label->setParent(this);                // 父窗口
    label->setGeometry(100, 100, 200, 40); // 位置和大小
}

window_test::~window_test() {}

// model-view-control, design mode
int main(int argc, char *argv[])
{

    printf("hello qt \n");
    QApplication app(argc, argv);

    window_test wd;
    QWidget *parent_widget;
    parent_widget = wd.label->parentWidget();

    std::cout<<"window addr "<<&wd<<std::endl;
    std::cout<<"label addr "<<&wd.label<<std::endl;
    std::cout<<"label parent addr "<<parent_widget<<std::endl;

    wd.show();

    app.exec();
    return 0;
}