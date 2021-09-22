#include <qt5/QtWidgets/qaction.h>
#include <stdio.h>
#include <QApplication>
#include <QMainWindow>
#include <qt5/QtWidgets/QLabel>

// model-view-control, design mode
int main(int argc, char *argv[])
{

    printf("hello qt \n");
    QApplication app(argc, argv);

    QLabel label;
    label.setText("hello qt!");
    label.setStyleSheet("color::white");
    label.setMinimumSize(1000, 800);
    label.setAlignment(Qt::AlignCenter);
    label.show();

    app.exec();
    return 0;
}