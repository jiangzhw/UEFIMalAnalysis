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

    //ָ���ַ����룬��ֹ��������
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTranslator qtTranslator;

    /**
     *����QT��������Ļ��ļ�
     */
    qtTranslator.load(":/qm/qt_zh_CN.qm");
    a.installTranslator(&qtTranslator);
    MainWindow w;
    w.show();
    return a.exec();
}
