#include <QApplication>
#include <QTextBrowser>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString strText = QObject::tr("1234打印汉字");
    QTextBrowser tb;
    tb.setText(strText);
    tb.setGeometry(40, 40, 400, 300);
    tb.show();
    
    return a.exec();
}