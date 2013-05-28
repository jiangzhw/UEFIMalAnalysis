#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qhexedit.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);
    QStringList uefiFiles;
    QString textContent;


private:
    Ui::MainWindow *ui;
      QFont font;
    void uefiMalCodeAnalysis(QString fileName);
    QString info;
    bool malCodeContains;
    QHexEdit *hexEdit;
    int adminMalCnt;
    int userMalCnt;
    QList < QStringList > adminRules;
    QList < QStringList > userRules;
    QMenu *adminRulesMenu;
    QMenu *userRulesMenu;
    //QString rulesInfo;
    QString adminRulesInfo;
    QString userRulesInfo;
    //œµÕ≥≥Ã–ÚÕ–≈Ã
    QSystemTrayIcon *trayIcon;

private slots:

    void on_DBManCheckBox_stateChanged(int );
    void on_userRulesListWidget_itemActivated(QListWidgetItem* item);
    void on_adminRulesListWidget_itemActivated(QListWidgetItem* item);
    void show_adminListContextMenu(const QPoint &/*pos*/);
    void show_userListContextMenu(const QPoint &/*pos*/);
    void on_delAdminRules();
    void on_delUserRules();
    void onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason);

    void on_saveRulesBtn_clicked();
    void on_pwdLineEdit_returnPressed();
    void on_addUserRuleBtn_clicked();
    void on_clearUserRuleBtn_clicked();
    void on_clearAdminRuleBtn_clicked();
    void on_addAdminRuleBtn_clicked();

    QString showAdminRules();
    QString showUserRules();

    void showAllRules();
    int  ABContainsRelation(QString A,QString B);


    void on_logInBtn_clicked();
    void on_DBManCheckBox_toggled(bool checked);

    void on_startAnalysisBtn_clicked();
    void on_browseBtn_clicked();
    void readInRules(QString fileName);



};

#endif // MAINWINDOW_H
