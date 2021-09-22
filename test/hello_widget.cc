#include "hello_widget.h"

window_test::window_test(QWidget *parent = 0) : QWidget(parent)
{
    this->setMinimumSize(1000, 800);
    label = std::make_shared<QLabel>();
    label->setText("<h1>hello widget</h1>!");
    label->setParent(this);
    label->setGeometry(10, 10, 200, 40);
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