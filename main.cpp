#include <QtGui/QApplication>
#include <QTextCodec>
#include <QDebug>
#include<QTranslator>
#include<QMessageBox>
#include<QtPlugin>
#include<QLibrary>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->addLibraryPath("./plugins");

    //指定字符编码，防止中文乱码
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTranslator qtTranslator;

    /**
     *加载QT程序的中文化文件
     */
    qtTranslator.load(":/qm/qt_zh_CN.qm");
    a.installTranslator(&qtTranslator);
    MainWindow w;
    w.show();
    return a.exec();
}
