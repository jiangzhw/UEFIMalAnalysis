/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun Jul 17 16:01:14 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_8;
    QWidget *mainWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *uefiFileslineEdit;
    QPushButton *browseBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *userClassComboBox;
    QPushButton *startAnalysisBtn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QProgressBar *analysisProgressBar;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_7;
    QTextBrowser *resultTextBrowser;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QTextBrowser *allRuelsTextBrowser;
    QCheckBox *DBManCheckBox;
    QWidget *logWidget;
    QGridLayout *gridLayout_3;
    QGroupBox *logGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *adminLineEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *pwdLineEdit;
    QPushButton *logInBtn;
    QWidget *rulesManWidget;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *adminRuleGroupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QCheckBox *StrcpyCheckBox;
    QCheckBox *IpIoAddIpCheckBox;
    QCheckBox *IpIoRemoveIpCheckBox;
    QCheckBox *NetBufCopyCheckBox;
    QCheckBox *AsciiStrCopyCheckBox;
    QCheckBox *NetStringToIpCheckBox;
    QCheckBox *SockCloneCheckBox;
    QCheckBox *Writeunaligned64CheckBox;
    QScrollArea *adminRulesScrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_6;
    QListWidget *adminRulesListWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addAdminRuleBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearAdminRuleBtn;
    QGroupBox *userRuleGroupBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QCheckBox *StrcpyCheckBox_2;
    QCheckBox *IpIoAddIpCheckBox_2;
    QCheckBox *IpIoRemoveIpCheckBox_2;
    QCheckBox *NetBufCopyCheckBox_2;
    QCheckBox *AsciiStrCopyCheckBox_2;
    QCheckBox *NetStringToIpCheckBox_2;
    QCheckBox *SockCloneCheckBox_2;
    QCheckBox *Writeunaligned64CheckBox_2;
    QScrollArea *userRulesScrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QGridLayout *gridLayout_8;
    QListWidget *userRulesListWidget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *addUserRuleBtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *clearUserRuleBtn;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *saveRulesBtn;
    QSpacerItem *horizontalSpacer_5;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(717, 654);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/UEFIlogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_8 = new QHBoxLayout(centralWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        mainWidget = new QWidget(centralWidget);
        mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        verticalLayout_3 = new QVBoxLayout(mainWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(mainWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        uefiFileslineEdit = new QLineEdit(mainWidget);
        uefiFileslineEdit->setObjectName(QString::fromUtf8("uefiFileslineEdit"));

        horizontalLayout->addWidget(uefiFileslineEdit);

        browseBtn = new QPushButton(mainWidget);
        browseBtn->setObjectName(QString::fromUtf8("browseBtn"));

        horizontalLayout->addWidget(browseBtn);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(mainWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        userClassComboBox = new QComboBox(mainWidget);
        userClassComboBox->setObjectName(QString::fromUtf8("userClassComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(userClassComboBox->sizePolicy().hasHeightForWidth());
        userClassComboBox->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(userClassComboBox);

        startAnalysisBtn = new QPushButton(mainWidget);
        startAnalysisBtn->setObjectName(QString::fromUtf8("startAnalysisBtn"));

        horizontalLayout_2->addWidget(startAnalysisBtn);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(mainWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        analysisProgressBar = new QProgressBar(mainWidget);
        analysisProgressBar->setObjectName(QString::fromUtf8("analysisProgressBar"));
        analysisProgressBar->setValue(0);
        analysisProgressBar->setTextVisible(false);

        horizontalLayout_5->addWidget(analysisProgressBar);


        verticalLayout_3->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(mainWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_7 = new QGridLayout(groupBox);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        resultTextBrowser = new QTextBrowser(groupBox);
        resultTextBrowser->setObjectName(QString::fromUtf8("resultTextBrowser"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(resultTextBrowser->sizePolicy().hasHeightForWidth());
        resultTextBrowser->setSizePolicy(sizePolicy1);

        gridLayout_7->addWidget(resultTextBrowser, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(mainWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        allRuelsTextBrowser = new QTextBrowser(groupBox_2);
        allRuelsTextBrowser->setObjectName(QString::fromUtf8("allRuelsTextBrowser"));
        sizePolicy.setHeightForWidth(allRuelsTextBrowser->sizePolicy().hasHeightForWidth());
        allRuelsTextBrowser->setSizePolicy(sizePolicy);
        allRuelsTextBrowser->setFont(font);

        gridLayout_5->addWidget(allRuelsTextBrowser, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        DBManCheckBox = new QCheckBox(mainWidget);
        DBManCheckBox->setObjectName(QString::fromUtf8("DBManCheckBox"));

        verticalLayout_3->addWidget(DBManCheckBox);

        logWidget = new QWidget(mainWidget);
        logWidget->setObjectName(QString::fromUtf8("logWidget"));
        gridLayout_3 = new QGridLayout(logWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        logGroupBox = new QGroupBox(logWidget);
        logGroupBox->setObjectName(QString::fromUtf8("logGroupBox"));
        gridLayout = new QGridLayout(logGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(logGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        adminLineEdit = new QLineEdit(logGroupBox);
        adminLineEdit->setObjectName(QString::fromUtf8("adminLineEdit"));

        horizontalLayout_3->addWidget(adminLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(logGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        pwdLineEdit = new QLineEdit(logGroupBox);
        pwdLineEdit->setObjectName(QString::fromUtf8("pwdLineEdit"));
        pwdLineEdit->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(pwdLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_6->addLayout(verticalLayout);

        logInBtn = new QPushButton(logGroupBox);
        logInBtn->setObjectName(QString::fromUtf8("logInBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(logInBtn->sizePolicy().hasHeightForWidth());
        logInBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_6->addWidget(logInBtn);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        gridLayout_3->addWidget(logGroupBox, 0, 0, 1, 1);


        verticalLayout_3->addWidget(logWidget);


        horizontalLayout_8->addWidget(mainWidget);

        rulesManWidget = new QWidget(centralWidget);
        rulesManWidget->setObjectName(QString::fromUtf8("rulesManWidget"));
        verticalLayout_5 = new QVBoxLayout(rulesManWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        adminRuleGroupBox = new QGroupBox(rulesManWidget);
        adminRuleGroupBox->setObjectName(QString::fromUtf8("adminRuleGroupBox"));
        verticalLayout_2 = new QVBoxLayout(adminRuleGroupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        StrcpyCheckBox = new QCheckBox(adminRuleGroupBox);
        StrcpyCheckBox->setObjectName(QString::fromUtf8("StrcpyCheckBox"));

        gridLayout_2->addWidget(StrcpyCheckBox, 0, 0, 1, 1);

        IpIoAddIpCheckBox = new QCheckBox(adminRuleGroupBox);
        IpIoAddIpCheckBox->setObjectName(QString::fromUtf8("IpIoAddIpCheckBox"));

        gridLayout_2->addWidget(IpIoAddIpCheckBox, 0, 1, 1, 1);

        IpIoRemoveIpCheckBox = new QCheckBox(adminRuleGroupBox);
        IpIoRemoveIpCheckBox->setObjectName(QString::fromUtf8("IpIoRemoveIpCheckBox"));

        gridLayout_2->addWidget(IpIoRemoveIpCheckBox, 1, 0, 1, 1);

        NetBufCopyCheckBox = new QCheckBox(adminRuleGroupBox);
        NetBufCopyCheckBox->setObjectName(QString::fromUtf8("NetBufCopyCheckBox"));

        gridLayout_2->addWidget(NetBufCopyCheckBox, 1, 1, 1, 1);

        AsciiStrCopyCheckBox = new QCheckBox(adminRuleGroupBox);
        AsciiStrCopyCheckBox->setObjectName(QString::fromUtf8("AsciiStrCopyCheckBox"));

        gridLayout_2->addWidget(AsciiStrCopyCheckBox, 2, 0, 1, 1);

        NetStringToIpCheckBox = new QCheckBox(adminRuleGroupBox);
        NetStringToIpCheckBox->setObjectName(QString::fromUtf8("NetStringToIpCheckBox"));

        gridLayout_2->addWidget(NetStringToIpCheckBox, 2, 1, 1, 1);

        SockCloneCheckBox = new QCheckBox(adminRuleGroupBox);
        SockCloneCheckBox->setObjectName(QString::fromUtf8("SockCloneCheckBox"));

        gridLayout_2->addWidget(SockCloneCheckBox, 3, 0, 1, 1);

        Writeunaligned64CheckBox = new QCheckBox(adminRuleGroupBox);
        Writeunaligned64CheckBox->setObjectName(QString::fromUtf8("Writeunaligned64CheckBox"));

        gridLayout_2->addWidget(Writeunaligned64CheckBox, 3, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        adminRulesScrollArea = new QScrollArea(adminRuleGroupBox);
        adminRulesScrollArea->setObjectName(QString::fromUtf8("adminRulesScrollArea"));
        adminRulesScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 318, 82));
        gridLayout_6 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        adminRulesListWidget = new QListWidget(scrollAreaWidgetContents);
        adminRulesListWidget->setObjectName(QString::fromUtf8("adminRulesListWidget"));

        gridLayout_6->addWidget(adminRulesListWidget, 0, 0, 1, 1);

        adminRulesScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(adminRulesScrollArea);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        addAdminRuleBtn = new QPushButton(adminRuleGroupBox);
        addAdminRuleBtn->setObjectName(QString::fromUtf8("addAdminRuleBtn"));
        sizePolicy2.setHeightForWidth(addAdminRuleBtn->sizePolicy().hasHeightForWidth());
        addAdminRuleBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(addAdminRuleBtn);

        horizontalSpacer = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        clearAdminRuleBtn = new QPushButton(adminRuleGroupBox);
        clearAdminRuleBtn->setObjectName(QString::fromUtf8("clearAdminRuleBtn"));
        sizePolicy2.setHeightForWidth(clearAdminRuleBtn->sizePolicy().hasHeightForWidth());
        clearAdminRuleBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(clearAdminRuleBtn);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_5->addWidget(adminRuleGroupBox);

        userRuleGroupBox = new QGroupBox(rulesManWidget);
        userRuleGroupBox->setObjectName(QString::fromUtf8("userRuleGroupBox"));
        verticalLayout_4 = new QVBoxLayout(userRuleGroupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        StrcpyCheckBox_2 = new QCheckBox(userRuleGroupBox);
        StrcpyCheckBox_2->setObjectName(QString::fromUtf8("StrcpyCheckBox_2"));

        gridLayout_4->addWidget(StrcpyCheckBox_2, 0, 0, 1, 1);

        IpIoAddIpCheckBox_2 = new QCheckBox(userRuleGroupBox);
        IpIoAddIpCheckBox_2->setObjectName(QString::fromUtf8("IpIoAddIpCheckBox_2"));

        gridLayout_4->addWidget(IpIoAddIpCheckBox_2, 0, 1, 1, 1);

        IpIoRemoveIpCheckBox_2 = new QCheckBox(userRuleGroupBox);
        IpIoRemoveIpCheckBox_2->setObjectName(QString::fromUtf8("IpIoRemoveIpCheckBox_2"));

        gridLayout_4->addWidget(IpIoRemoveIpCheckBox_2, 1, 0, 1, 1);

        NetBufCopyCheckBox_2 = new QCheckBox(userRuleGroupBox);
        NetBufCopyCheckBox_2->setObjectName(QString::fromUtf8("NetBufCopyCheckBox_2"));

        gridLayout_4->addWidget(NetBufCopyCheckBox_2, 1, 1, 1, 1);

        AsciiStrCopyCheckBox_2 = new QCheckBox(userRuleGroupBox);
        AsciiStrCopyCheckBox_2->setObjectName(QString::fromUtf8("AsciiStrCopyCheckBox_2"));

        gridLayout_4->addWidget(AsciiStrCopyCheckBox_2, 2, 0, 1, 1);

        NetStringToIpCheckBox_2 = new QCheckBox(userRuleGroupBox);
        NetStringToIpCheckBox_2->setObjectName(QString::fromUtf8("NetStringToIpCheckBox_2"));

        gridLayout_4->addWidget(NetStringToIpCheckBox_2, 2, 1, 1, 1);

        SockCloneCheckBox_2 = new QCheckBox(userRuleGroupBox);
        SockCloneCheckBox_2->setObjectName(QString::fromUtf8("SockCloneCheckBox_2"));

        gridLayout_4->addWidget(SockCloneCheckBox_2, 3, 0, 1, 1);

        Writeunaligned64CheckBox_2 = new QCheckBox(userRuleGroupBox);
        Writeunaligned64CheckBox_2->setObjectName(QString::fromUtf8("Writeunaligned64CheckBox_2"));

        gridLayout_4->addWidget(Writeunaligned64CheckBox_2, 3, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        userRulesScrollArea = new QScrollArea(userRuleGroupBox);
        userRulesScrollArea->setObjectName(QString::fromUtf8("userRulesScrollArea"));
        userRulesScrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 318, 83));
        gridLayout_8 = new QGridLayout(scrollAreaWidgetContents_3);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        userRulesListWidget = new QListWidget(scrollAreaWidgetContents_3);
        userRulesListWidget->setObjectName(QString::fromUtf8("userRulesListWidget"));

        gridLayout_8->addWidget(userRulesListWidget, 0, 0, 1, 1);

        userRulesScrollArea->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_4->addWidget(userRulesScrollArea);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        addUserRuleBtn = new QPushButton(userRuleGroupBox);
        addUserRuleBtn->setObjectName(QString::fromUtf8("addUserRuleBtn"));
        sizePolicy2.setHeightForWidth(addUserRuleBtn->sizePolicy().hasHeightForWidth());
        addUserRuleBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(addUserRuleBtn);

        horizontalSpacer_3 = new QSpacerItem(138, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        clearUserRuleBtn = new QPushButton(userRuleGroupBox);
        clearUserRuleBtn->setObjectName(QString::fromUtf8("clearUserRuleBtn"));
        sizePolicy2.setHeightForWidth(clearUserRuleBtn->sizePolicy().hasHeightForWidth());
        clearUserRuleBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(clearUserRuleBtn);


        verticalLayout_4->addLayout(horizontalLayout_9);


        verticalLayout_5->addWidget(userRuleGroupBox);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(141, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        saveRulesBtn = new QPushButton(rulesManWidget);
        saveRulesBtn->setObjectName(QString::fromUtf8("saveRulesBtn"));
        sizePolicy2.setHeightForWidth(saveRulesBtn->sizePolicy().hasHeightForWidth());
        saveRulesBtn->setSizePolicy(sizePolicy2);

        horizontalLayout_10->addWidget(saveRulesBtn);

        horizontalSpacer_5 = new QSpacerItem(141, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_10);


        horizontalLayout_8->addWidget(rulesManWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UEFI\346\201\266\346\204\217\344\273\243\347\240\201\345\210\206\346\236\220\345\267\245\345\205\267", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\345\276\205\345\210\206\346\236\220\347\232\204UEFI\346\226\207\344\273\266:", 0, QApplication::UnicodeUTF8));
        browseBtn->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\346\235\203\351\231\220\347\272\247\345\210\253:", 0, QApplication::UnicodeUTF8));
        userClassComboBox->clear();
        userClassComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "\346\231\256\351\200\232\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8)
        );
        startAnalysisBtn->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213\345\210\206\346\236\220", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\346\200\273\344\275\223\345\210\206\346\236\220\350\277\233\345\272\246:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "UEFI\346\226\207\344\273\266\345\210\206\346\236\220\346\217\220\347\244\272\346\241\206", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\215\261\351\231\251UEFI\346\226\207\344\273\266\350\247\204\345\210\231\346\261\207\346\200\273", 0, QApplication::UnicodeUTF8));
        DBManCheckBox->setText(QApplication::translate("MainWindow", "\345\256\232\344\271\211\345\215\261\351\231\251UEFI\346\226\207\344\273\266\350\247\204\345\210\231", 0, QApplication::UnicodeUTF8));
        logGroupBox->setTitle(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\350\264\246\345\217\267\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\345\257\206\347\240\201\357\274\232", 0, QApplication::UnicodeUTF8));
        logInBtn->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0, QApplication::UnicodeUTF8));
        adminRuleGroupBox->setTitle(QApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        StrcpyCheckBox->setText(QApplication::translate("MainWindow", "Strcpy", 0, QApplication::UnicodeUTF8));
        IpIoAddIpCheckBox->setText(QApplication::translate("MainWindow", "IpIoAddIp", 0, QApplication::UnicodeUTF8));
        IpIoRemoveIpCheckBox->setText(QApplication::translate("MainWindow", "IpIoRemoveIp", 0, QApplication::UnicodeUTF8));
        NetBufCopyCheckBox->setText(QApplication::translate("MainWindow", "NetBufCopy", 0, QApplication::UnicodeUTF8));
        AsciiStrCopyCheckBox->setText(QApplication::translate("MainWindow", "AsciiStrCopy", 0, QApplication::UnicodeUTF8));
        NetStringToIpCheckBox->setText(QApplication::translate("MainWindow", "NetStringToIp", 0, QApplication::UnicodeUTF8));
        SockCloneCheckBox->setText(QApplication::translate("MainWindow", "SockClone", 0, QApplication::UnicodeUTF8));
        Writeunaligned64CheckBox->setText(QApplication::translate("MainWindow", "Writeunaligned64", 0, QApplication::UnicodeUTF8));
        addAdminRuleBtn->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        clearAdminRuleBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        userRuleGroupBox->setTitle(QApplication::translate("MainWindow", "\346\231\256\351\200\232\347\224\250\346\210\267\347\261\273\345\210\253", 0, QApplication::UnicodeUTF8));
        StrcpyCheckBox_2->setText(QApplication::translate("MainWindow", "Strcpy", 0, QApplication::UnicodeUTF8));
        IpIoAddIpCheckBox_2->setText(QApplication::translate("MainWindow", "IpIoAddIp", 0, QApplication::UnicodeUTF8));
        IpIoRemoveIpCheckBox_2->setText(QApplication::translate("MainWindow", "IpIoRemoveIp", 0, QApplication::UnicodeUTF8));
        NetBufCopyCheckBox_2->setText(QApplication::translate("MainWindow", "NetBufCopy", 0, QApplication::UnicodeUTF8));
        AsciiStrCopyCheckBox_2->setText(QApplication::translate("MainWindow", "AsciiStrCopy", 0, QApplication::UnicodeUTF8));
        NetStringToIpCheckBox_2->setText(QApplication::translate("MainWindow", "NetStringToIp", 0, QApplication::UnicodeUTF8));
        SockCloneCheckBox_2->setText(QApplication::translate("MainWindow", "SockClone", 0, QApplication::UnicodeUTF8));
        Writeunaligned64CheckBox_2->setText(QApplication::translate("MainWindow", "Writeunaligned64", 0, QApplication::UnicodeUTF8));
        addUserRuleBtn->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        clearUserRuleBtn->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272", 0, QApplication::UnicodeUTF8));
        saveRulesBtn->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\350\247\204\345\210\231", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
