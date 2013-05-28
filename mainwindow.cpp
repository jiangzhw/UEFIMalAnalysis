#include "mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include <QProgressDialog>
#include <QDebug>
#include <QRegExp>
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*!
      *系统托盘设置
      *
      */
    QIcon icon = QIcon(":/images/UEFIlogo.ico");
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setToolTip(tr("UEFI恶意代码分析工具"));
    trayIcon->setIcon(icon);
    trayIcon->show();
    QMenu *trayMenu=new QMenu(this);
    QAction *quitAction=new QAction(tr("退出"),this);
    QAction *showAction = new QAction(tr("显示主窗口"), this);
    QAction *hideAction = new QAction(tr("隐藏主窗口"), this);
    trayMenu->addAction(showAction);
    trayMenu->addAction(hideAction);
    trayMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayMenu);
    connect(trayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,
            SLOT(onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)));
    connect(quitAction,SIGNAL(triggered()),this,SLOT(close()));
    connect(showAction,SIGNAL(triggered()),this,SLOT(show()));
    connect(hideAction,SIGNAL(triggered()),this,SLOT(hide()));


    font.setPointSize(10);
    //rulesInfo=tr("");
    adminRulesInfo=tr("");
    userRulesInfo=tr("");
    ////qWarning()<<__FILE__<<__LINE__;
    //connect(ui->logInBtn,SIGNAL(clicked()),this,SLOT(on_logInBtn_clicked()));
    ////qWarning()<<__FILE__<<__LINE__;
    ui->logWidget->hide();
    ////qWarning()<<__FILE__<<__LINE__;
    ui->rulesManWidget->hide();
    ////qWarning()<<__FILE__<<__LINE__;


    QString fileName=tr("rules.ini");
    ////qWarning()<<__FILE__<<__LINE__;
    this->readInRules(fileName);
    ////qWarning()<<__FILE__<<__LINE__;
    this->showAllRules();
    ////qWarning()<<__FILE__<<__LINE__;

    adminMalCnt=0;
    userMalCnt=0;
    textContent=tr("");
    ui->resultTextBrowser->setReadOnly(true);
    info=tr("");
    malCodeContains=false;
    hexEdit=new QHexEdit;
    hexEdit->hide();
    ////qWarning()<<__FILE__<<__LINE__;

    //uefiFiles<<tr("");
}

MainWindow::~MainWindow()
{
    delete trayIcon;
    delete ui;
}


void MainWindow::onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason reason){
    if(reason==QSystemTrayIcon::Trigger){
        if(isHidden())
            show();
        else
            hide();
    }
}

void MainWindow::show_adminListContextMenu(const QPoint &/*pos*/){

    if(adminRulesMenu)
    {
        adminRulesMenu->exec(QCursor::pos());
    }


}

void MainWindow::show_userListContextMenu(const QPoint &/*pos*/){

    if(userRulesMenu)
    {
        userRulesMenu->exec(QCursor::pos());
    }


}

void MainWindow::on_delAdminRules(){
    QListWidgetItem* currentItem=ui->adminRulesListWidget->currentItem();
    if(!currentItem)
        return;
    QString ruleInfo=currentItem->text();
    QString ruleMainInfo=ruleInfo.split(":").at(1);
    QStringList ruleQSL=ruleMainInfo.split(",");
    if(ruleQSL.size()>0)
        adminRules.removeOne(ruleQSL);
    this->showAdminRules();
}

void MainWindow::on_delUserRules(){
    QListWidgetItem* currentItem=ui->userRulesListWidget->currentItem();
    if(!currentItem)
        return;
    QString ruleInfo=currentItem->text();
    QString ruleMainInfo=ruleInfo.split(":").at(1);
    QStringList ruleQSL=ruleMainInfo.split(",");
    if(ruleQSL.size()>0)
        userRules.removeOne(ruleQSL);
    this->showUserRules();
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void MainWindow::on_browseBtn_clicked()
{
    uefiFiles =
            QFileDialog::getOpenFileNames(this, tr("请选择待分析的UEFI文件"),   "UEFIFiles/",
                                          tr("UEFI文件(*.efi );;所有文件 (*.*)"));
    if (uefiFiles.isEmpty())
        return;
    //只显示文件名
    QString uefiFileStr;
    textContent.clear();
    textContent.append(tr("待分析的UEFI文件:\n"));
    for(int i=0;i<uefiFiles.size();i++){
        QFileInfo* fileInfo = new QFileInfo(uefiFiles.at(i));
        uefiFileStr.append(fileInfo->fileName());
        textContent.append(fileInfo->fileName());
        textContent.append("\n");
        uefiFileStr.append(tr(" "));
    }
    ui->uefiFileslineEdit->setText(uefiFileStr);
    ui->resultTextBrowser->setText(textContent);
    ui->analysisProgressBar->setValue(0);
}

void MainWindow::on_startAnalysisBtn_clicked()
{
    if(adminRules.size()==0 && userRules.size()==0){
        QMessageBox::information (this,QObject::tr("提示"),QObject::tr("请预先定义危险UEFI文件规则！"));
        return;
    }
    if(uefiFiles.size()==0){
        QMessageBox::information (this,QObject::tr("提示"),QObject::tr("请浏览读入待分析的UEFI文件！"));
        return;
    }
    info.clear();
    if(uefiFiles.size()>0){
        ui->analysisProgressBar->setMaximum(uefiFiles.size());
        QApplication::setOverrideCursor(Qt::WaitCursor);

        for(int i =0;i<uefiFiles.size();++i){
            qApp->processEvents();
            ui->analysisProgressBar->setValue(i);
            QString descripHeader=tr("");
            if(i==0){

                descripHeader=tr("<b>文件 ")+uefiFiles.at(i)+tr(" 恶意代码匹配情况:</b><br>");
            }else{
                descripHeader=tr("<br><br><b>文件 ")+uefiFiles.at(i)+tr(" 恶意代码匹配情况:</b><br>");
            }
            info.append(descripHeader);
            this->uefiMalCodeAnalysis(uefiFiles.at(i));
        }

        ui->analysisProgressBar->setValue(uefiFiles.size());
        uefiFiles.clear();
        ui->statusBar->showMessage(tr("UEFI恶意代码情况分析完毕!"), 4000);
        ui->uefiFileslineEdit->clear();
        QApplication::restoreOverrideCursor();
    }


    ui->resultTextBrowser->setFont(font);
    //ui->resultTextBrowser->clear();
    //  ui->resultTextBrowser->insertHtml(info);
    ui->resultTextBrowser->setText(tr("正在格式化文件分析结果,请稍候..."));
    QTime dieTime = QTime::currentTime().addMSecs(500);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    ui->resultTextBrowser->setHtml(info);
}


void MainWindow::uefiMalCodeAnalysis(QString fileName){

    QString title=tr("");
    title.append(fileName);
    title.append(tr(" UEFI恶意代码情况分析中,\n请稍候..."));
    QProgressDialog *ProgressDialog = new QProgressDialog(title,QString(), 0,100);
    ProgressDialog->setModal(Qt::WindowModal);
    ProgressDialog->setWindowTitle(QObject::tr("UEFI恶意代码分析"));
    ProgressDialog->show();
    ProgressDialog->setMaximum(0);
    //设置进度条来回滚动
    for(int i=0;i<=0;i++){
        ProgressDialog->setValue(i);
    }

    QFile *m_file = new QFile();
    m_file->setFileName(fileName);
    if(!m_file->open( QFile::ReadOnly ))
        return ;
    long size = m_file->size();
    QDataStream *reader = new QDataStream();
    reader->setDevice(m_file);
    char *buf = new char[size];
    reader->readRawData(buf, size);
    QByteArray data = QByteArray::fromRawData(buf, size);
    hexEdit->setData(data);
    QByteArray hexBA=hexEdit->data();

    QString hexCode=QString(hexBA.toHex().toUpper());
    // //qDebug()<<"current hexCode is "<<hexCode;
    QRegExp *rx=new QRegExp();//85F6 7517 68 *8* 68 DB000000 68 *8* E8 *8* 83 C4 0C 8B 44 24 04 8B 54 24 08 89 06 89 56 04 C3

    QString writeUnaligned64=tr("85F6751768[0-9A-F]{8}68DB00000068[0-9A-F]{8}E8[0-9A-F]{8}83C40C8B4424048B5424088906895604C3");
    QString strcpy=tr("53568B[0-9A-F]{2}85DB57[0-9A-F]{,4}BF[0-9A-F]{8}75[0-9A-F]{2}68[0-9A-F]{8}[0-9A-F]{,10}57E8[0-9A-F]{8}83C40CF6C30174[0-9A-F]{2}68[0-9A-F]{8}[0-9A-F]{,10}57E8[0-9A-F]{8}83C40C[0-9A-F]*68[0-9A-F]{8}[0-9A-F]{,10}57E8[0-9A-F]{8}83C40C[0-9A-F]*5F[0-9A-F]*5E5BC3");
    QString ipIoAddIp=tr("558BEC5153578BF885FF751768[0-9A-F]{8}685F06000068[0-9A-F]{8}E8[0-9A-F]{8}83C40C6A38E8[0-9A-F]{8}8BD885DB590F849E000000568D7314E8[0-9A-F]{8}6A108D731C83260053E8[0-9A-F]{8}8D43106A0450E8[0-9A-F]{8}C74330010000000FB647488D4B205150884334FF7714FF7710E8[0-9A-F]{8}83C42085C07C358D45FC50A1[0-9A-F]{8}5368[0-9A-F]{8}6A106800020000FF503483C41485C07D230FB6433450FF36FF7714FF7710E8[0-9A-F]{8}83C410A1[0-9A-F]{8}53FF50305933C0EB138B45FC8943248D47088D7B14E8[0-9A-F]{8}8BC35E5F5BC9C3");
    QString ipIoRemoveIp=tr("558BEC51837F300056BE[0-9A-F]{8}7F1368[0-9A-F]{8}686407000056E8[0-9A-F]{8}83C40CFF4F30837F30007F618A43483C048845FF74173C06741368[0-9A-F]{8}686F07000056E8[0-9A-F]{8}83C40C8D7714E8[0-9A-F]{8}8B47206A0050FF5004807DFF0475046A04EB026A06FF771CFF7314FF7310E8[0-9A-F]{8}FF7724A1[0-9A-F]{8}FF504483C41C57E8[0-9A-F]{8}595EC9C3");
    QString netBufCopy=tr("558BEC5151538B5D0885DB56578BF8BE[0-9A-F]{8}7408813B6E627566741368[0-9A-F]{8}68E004000056E8[0-9A-F]{8}83C40C837D1000751368[0-9A-F]{8}68E104000056E8[0-9A-F]{8}83C40C33F639750C0F84E10000008B43643BC70F86D60000002BC73B450C730389450C8B536033C985D276208D43788945F88B45F88B0085C0740803C13BF8720B8BC88345F814463BF272E68BC66BC0142BF98D4418688B5D108BCF8B78108B40082BF903C1397D0C50770D8B7D0CE840EEFFFF598BC7EB78E836EEFFFF017D10297D0C598B4D08463B7160897DFC73598BC66BC0148D4408788945F8EB058BC88B45F88B550C3B108B5D10762A8B38FF70F8017DFC2BD789550CE8[0-9A-F]{8}8B45F88B000145108B45088345F814463B70605972C9EB120155FC6BF614FF740E708BFAE8[0-9A-F]{8}598B45FCEB0233C05F5E5BC9C3");
    QString asciiStrCopy=tr("5356578BF985FF8BF0BB[0-9A-F]{8}751368[0-9A-F]{8}686204000053E8[0-9A-F]{8}83C40C8BC6E8510000008BCF2BCE3BC8771368[0-9A-F]{8}686704000053E8[0-9A-F]{8}83C40C8BC6E82F0000008BCE2BCF3BC8771368[0-9A-F]{8}686804000053E8[0-9A-F]{8}83C40C8BC7EB04880F47468A0E84C975F6880F5F5E5BC3");
    QString netStringToIp=tr("558BEC51565733FF8BF0893B897DFC8A063C3072413C39773D8BC6E8[0-9A-F]{8}3DFF000000772FC1E7080BF8EB053C397707468A063C3073F5837DFC037305803E2E751246FF45FC837DFC0472C1893B33C05F5EC9C3B802000080EBF5");
    QString sockClone=tr("558BEC83EC388B46548945D48A46248845CC8B86900000008945F88B46208945C88B46408945DC8B46348945D88B46088945FC8D86A80000008945E08B86D00000008945E48B86D40000008945E88B86D80000008945EC8D86940000008945F08D45C8508975D0C745F414000000E8[0-9A-F]{8}85C059751468[0-9A-F]{8}B800000080E8[0-9A-F]{8}5933C0C9C3C64024028A4E1C88481CC9C3");

    QStringList malCodeList;
    malCodeList<<strcpy<<ipIoAddIp<<ipIoRemoveIp<<netBufCopy<<asciiStrCopy<<netStringToIp<<sockClone<<writeUnaligned64;

    QHash <QString,QString> malName_Code ;
    malName_Code.insert("Strcpy",strcpy);
    malName_Code.insert("IpIoAddIp",ipIoAddIp);
    malName_Code.insert("IpIoRemoveIp",ipIoRemoveIp);
    malName_Code.insert("NetBufCopy",netBufCopy);
    malName_Code.insert("AsciiStrCopy",asciiStrCopy);
    malName_Code.insert("NetStringToIp",netStringToIp);
    malName_Code.insert("SockClone",sockClone);
    malName_Code.insert("WriteUnaligned64",writeUnaligned64);




    if(ui->userClassComboBox->currentText()==tr("管理员")){
        int rulesCnt=adminRules.size();
        for(int i=0;i<rulesCnt;i++){
            QStringList malCodeSet=adminRules.at(i);
            QString malCodeHeader=tr("");
            if(i==0){
                malCodeHeader=tr("第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户):<br>");
            }else{
                malCodeHeader=tr("<br>第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户):<br>");
            }

            malCodeHeader.append(malCodeSet.join(","));
            info.append(malCodeHeader);

            QString matchStr;
            for(int j=0;j<malCodeSet.size();j++){
                rx->setPattern(malName_Code.value(malCodeSet.at(j)));
                rx->setCaseSensitivity(Qt::CaseInsensitive);
                if(!rx->isValid()){
                    //qDebug()<<rx->errorString();
                    return ;
                }else{
                    // //qDebug()<<"current pattern is "<<rx->pattern();
                }

                if( rx->indexIn(hexCode)>0 ){
                    QString capCode = rx->cap(0);
                    QString capCodeHeader=tr("<br><b>发现 ")+malCodeSet.at(j)+tr(" 的特征码:</b><br>");
                    capCodeHeader.append(capCode);
                    info.append(capCodeHeader);
                    matchStr.append("1");
                }else{
                    matchStr.append("0");
                }
            }
            /*
            if(isDangerFile){
                info.append("\n################################################################");
                QString description=tr("\n文件 ")+fileName+tr(" 满足定义的第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户):\n");
                description.append(malCodeSet.join(","));
                info.append(description);
            }*/

            if(matchStr.contains("0")){
                QString description=tr("<br><b>分析结论：文件 ")+fileName+tr(" 不满足定义的第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户)。</b>");
                info.append(description);
            }else{
                QString description=tr("<br><b style=\"color:#FF0000\">文件 ")+fileName+tr(" 满足定义的第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户),疑为危险的UEFI文件!!!</b>");
                info.append(description);
            }
        }

    }else if(ui->userClassComboBox->currentText()==tr("普通用户")){
        int rulesCnt=userRules.size();
        for(int i=0;i<rulesCnt;i++){
            QStringList malCodeSet=userRules.at(i);
            QString malCodeHeader=tr("");
            if(i==0){
                malCodeHeader=tr("第")+QString::number(i+1)+tr("条规则(对应于普通用户):<br>");
            }else{
                malCodeHeader=tr("<br>第")+QString::number(i+1)+tr("条规则(对应于普通用户):<br>");
            }

            malCodeHeader.append(malCodeSet.join(","));
            info.append(malCodeHeader);

            QString matchStr;
            for(int j=0;j<malCodeSet.size();j++){
                rx->setPattern(malName_Code.value(malCodeSet.at(j)));
                rx->setCaseSensitivity(Qt::CaseInsensitive);
                if(!rx->isValid()){
                    //qDebug()<<rx->errorString();
                    return ;
                }else{
                    // //qDebug()<<"current pattern is "<<rx->pattern();
                }

                if( rx->indexIn(hexCode)>0 ){
                    QString capCode = rx->cap(0);
                    QString capCodeHeader=tr("<br><b>发现 ")+malCodeSet.at(j)+tr(" 的特征码:</b><br>");
                    capCodeHeader.append(capCode);
                    info.append(capCodeHeader);
                    matchStr.append("1");
                }else{
                    matchStr.append("0");
                }
            }


            if(matchStr.contains("0")){
                QString description=tr("<br><b>分析结论：文件 ")+fileName+tr(" 不满足定义的第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户)。</b>");
                info.append(description);
            }else{
                QString description=tr("<br><b style=\"color:#FF0000\">文件 ")+fileName+tr(" 满足定义的第")+QString::number(i+1)+tr("条规则(对应于管理员权限的用户),疑为危险的UEFI文件!!!</b>");
                info.append(description);
            }
        }

    }
    ProgressDialog->setMaximum(100);
    ProgressDialog->setValue(0);
    delete ProgressDialog;

}


void MainWindow::on_DBManCheckBox_toggled(bool checked)
{
    if(checked){
        ui->logWidget->show();
        ui->adminLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->adminLineEdit->setFocus();
    }else{
        ui->logWidget->hide();
    }
}

void MainWindow::on_logInBtn_clicked()
{
    bool isAdmin=false;
    QString userName=ui->adminLineEdit->text().trimmed();
    QString password=ui->pwdLineEdit->text().trimmed();
    if(userName==tr("admin") && password==tr("uefiadmin")){
        isAdmin=true;
    }else{
        QMessageBox::warning(this, tr("登录错误!"), tr("请输入正确账号和密码!"));
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();

    }
    if(isAdmin){
        ui->rulesManWidget->show();
        ui->logWidget->hide();
        adminRulesMenu=new QMenu(ui->adminRulesListWidget);

        if(ui->adminRulesListWidget->count()>0){
            QAction *delAdminAction=adminRulesMenu->addAction(tr("删除规则"));
            ui->adminRulesListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(ui->adminRulesListWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_adminListContextMenu(QPoint)));
            connect(delAdminAction,SIGNAL(triggered()),this,SLOT(on_delAdminRules()));
        }


        userRulesMenu=new QMenu(ui->userRulesListWidget);
        if(ui->userRulesListWidget->count()>0){
            QAction *delUserAction=userRulesMenu->addAction(tr("删除规则"));
            ui->userRulesListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(ui->userRulesListWidget,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(show_userListContextMenu(QPoint)));
            connect(delUserAction,SIGNAL(triggered()),this,SLOT(on_delUserRules()));
        }

    }else{
        ui->rulesManWidget->hide();
    }
}


QString MainWindow::showAdminRules(){
    QString ruleInfo;
    adminRulesInfo.clear();
    adminRulesInfo.append(tr("管理员类别的危险规则:\n"));
    int size=adminRules.size();
    ui->adminRulesListWidget->clear();
    for(int i=0;i<size;i++){
        ruleInfo.clear();
        QString rule=adminRules.at(i).join(",");
        if(!rule.isEmpty()){
            QString num;
            num=tr("第")+QString ::number(i+1)+tr("条规则:");
            ruleInfo.append(num);
            ruleInfo.append(rule);
            adminRulesInfo.append(ruleInfo);
            adminRulesInfo.append("\n");
            ui->adminRulesListWidget->addItem(ruleInfo);
        }
    }

    this->showAllRules();

    return adminRulesInfo;


}

QString MainWindow::showUserRules(){
    QString ruleInfo;
    userRulesInfo.clear();
    userRulesInfo.append(tr("\n普通用户类别的危险规则:\n"));
    int size=userRules.size();
    ////qWarning()<<__FILE__<<__LINE__;
    ui->userRulesListWidget->clear();
    ////qWarning()<<__FILE__<<__LINE__;
    for(int i=0;i<size;i++){
        ruleInfo.clear();
        QString rule=userRules.at(i).join(",");
        ////qWarning()<<__FILE__<<__LINE__;
        if(!rule.isEmpty()){
            QString num;
            num=tr("第")+QString ::number(i+1)+tr("条规则:");
            ruleInfo.append(num);
            ruleInfo.append(rule);
            userRulesInfo.append(ruleInfo);
            userRulesInfo.append("\n");
            ui->userRulesListWidget->addItem(ruleInfo);
        }
    }
    ////qWarning()<<__FILE__<<__LINE__;
    this->showAllRules();
    ////qWarning()<<__FILE__<<__LINE__;
    return userRulesInfo;
}

void MainWindow::showAllRules(){

    ui->allRuelsTextBrowser->setText(adminRulesInfo+userRulesInfo);
}

int MainWindow::ABContainsRelation(QString A, QString B){
    QStringList AQSL=A.split(",");
    QStringList BQSL=B.split(",");
    if(AQSL==BQSL){
        return 0;
    }
    QString matchStr=tr("");
    if(AQSL.size()>BQSL.size()){
        for(int i=0;i<BQSL.size();i++){
            if(AQSL.contains(BQSL.at(i),Qt::CaseInsensitive)){
                matchStr.append("1");
            }else{
                matchStr.append("0");
            }
        }
        if(!matchStr.contains("0")){
            return 1;
        }
    }
    else{
        for(int i=0;i<AQSL.size();i++){
            if(BQSL.contains(AQSL.at(i),Qt::CaseInsensitive)){
                matchStr.append("1");
            }else{
                matchStr.append("0");
            }
        }
        if(!matchStr.contains("0")){
            return -1;
        }
    }

}

void MainWindow::on_addAdminRuleBtn_clicked()
{
    QStringList currentRule;
    if(ui->StrcpyCheckBox->isChecked()){
        currentRule<<"Strcpy";
    }
    if(ui->IpIoAddIpCheckBox->isChecked()){
        currentRule<<"IpIoAddIp";
    }
    if(ui->IpIoRemoveIpCheckBox->isChecked()){
        currentRule<<"IpIoRemoveIp";
    }
    if(ui->NetBufCopyCheckBox->isChecked()){
        currentRule<<"NetBufCopy";
    }
    if(ui->AsciiStrCopyCheckBox->isChecked()){
        currentRule<<"AsciiStrCopy";
    }
    if(ui->NetStringToIpCheckBox->isChecked()){
        currentRule<<"NetStringToIp";
    }
    if(ui->SockCloneCheckBox->isChecked()){
        currentRule<<"SockClone";
    }
    if(ui->Writeunaligned64CheckBox->isChecked()){
        currentRule<<"WriteUnaligned64";
    }
    if(currentRule.isEmpty()){
        return;
    }
    QString currentRuleStr=currentRule.join(",");
    //qDebug()<<"\n the curretnRuleStr is"<<currentRuleStr;
    if(adminRules.size()==0){
        //qWarning()<<__FILE__<<__LINE__;
        adminRules.append(currentRule);
    } else if(adminRules.contains(currentRule)){
        //qWarning()<<__FILE__<<__LINE__;
        QMessageBox::information (this,QObject::tr("提示"),QObject::tr("已存在该规则！"));
        return;
    }else{


        bool lastDealed=false;
        int i=0;
        for( i=0;i<adminRules.size();i++){
            //qWarning()<<__FILE__<<__LINE__;
            QString ruleStr=QStringList(adminRules.at(i)).join(",");
            ////qDebug()<<"\n the ruleStr is "<<ruleStr;

            if(ruleStr==currentRuleStr){
                if(i==adminRules.size()-1)
                    lastDealed=true;
                //qWarning()<<__FILE__<<__LINE__;
                QMessageBox::information (this,QObject::tr("提示"),QObject::tr("已存在该规则！"));
                return;
            }else if(this->ABContainsRelation(ruleStr,currentRuleStr)==1){
                if(i==adminRules.size()-1)
                    lastDealed=true;
                //qWarning()<<__FILE__<<__LINE__;
                int ok = QMessageBox::warning(this,tr("已存在该规则指定的特征码超集！"),tr("确定"
                                                                            "覆盖超集的规则吗？"),
                                              QMessageBox::Yes,QMessageBox::No);
                if(ok == QMessageBox::No)
                {
                    return;
                }else{
                    adminRules[i]=currentRule;
                    //qWarning()<<__FILE__<<__LINE__;
                    break;
                }
            }else if(this->ABContainsRelation(currentRuleStr,ruleStr)==1){

                if(i==adminRules.size()-1)
                    lastDealed=true;
                //qWarning()<<__FILE__<<__LINE__;
                int ok = QMessageBox::warning(this,tr("已存在以当前规则特征码为子集的规则!"),tr("确定"
                                                                               "覆盖子集的规则吗？"),
                                              QMessageBox::Yes,QMessageBox::No);
                if(ok == QMessageBox::No)
                {
                    return;
                }else{
                    //qWarning()<<__FILE__<<__LINE__;
                    adminRules[i]=currentRule;
                    break;
                }

            }
            else {
                //qWarning()<<__FILE__<<__LINE__;
                continue;
            }


        }

        if(!lastDealed){
            //qDebug()<<"lastdealed false";
        }
        //qDebug()<<"the i is "<<QString::number(i);
        if((!lastDealed) && (i==adminRules.size()) ){
            //qWarning()<<__FILE__<<__LINE__;
            adminRules.append(currentRule);
        }

    }

    this->showAdminRules();

}

void MainWindow::on_clearAdminRuleBtn_clicked()
{
    adminRules.clear();
    // ui->adminRuleTextBrowser->clear();
    ui->adminRulesListWidget->clear();
    ui->StrcpyCheckBox->setChecked(false);
    ui->IpIoAddIpCheckBox->setChecked(false);
    ui->IpIoRemoveIpCheckBox->setChecked(false);
    ui->NetBufCopyCheckBox->setChecked(false);
    ui->AsciiStrCopyCheckBox->setChecked(false);
    ui->NetStringToIpCheckBox->setChecked(false);
    ui->SockCloneCheckBox->setChecked(false);
    ui->Writeunaligned64CheckBox->setChecked(false);
}

void MainWindow::on_clearUserRuleBtn_clicked()
{
    userRules.clear();
    //ui->userRuleTextBrowser->clear();
    ui->userRulesListWidget->clear();
    ui->StrcpyCheckBox_2->setChecked(false);
    ui->IpIoAddIpCheckBox_2->setChecked(false);
    ui->IpIoRemoveIpCheckBox_2->setChecked(false);
    ui->NetBufCopyCheckBox_2->setChecked(false);
    ui->AsciiStrCopyCheckBox_2->setChecked(false);
    ui->NetStringToIpCheckBox_2->setChecked(false);
    ui->SockCloneCheckBox_2->setChecked(false);
    ui->Writeunaligned64CheckBox_2->setChecked(false);
}

void MainWindow::on_addUserRuleBtn_clicked()
{
    QStringList currentRule;
    if(ui->StrcpyCheckBox_2->isChecked()){
        currentRule<<"Strcpy";
    }
    if(ui->IpIoAddIpCheckBox_2->isChecked()){
        currentRule<<"IpIoAddIp";
    }
    if(ui->IpIoRemoveIpCheckBox_2->isChecked()){
        currentRule<<"IpIoRemoveIp";
    }
    if(ui->NetBufCopyCheckBox_2->isChecked()){
        currentRule<<"NetBufCopy";
    }
    if(ui->AsciiStrCopyCheckBox_2->isChecked()){
        currentRule<<"AsciiStrCopy";
    }
    if(ui->NetStringToIpCheckBox_2->isChecked()){
        currentRule<<"NetStringToIp";
    }
    if(ui->SockCloneCheckBox_2->isChecked()){
        currentRule<<"SockClone";
    }
    if(ui->Writeunaligned64CheckBox_2->isChecked()){
        currentRule<<"WriteUnaligned64";
    }
    if(currentRule.isEmpty()){
        return;
    }
    QString currentRuleStr=currentRule.join(",");
    //qDebug()<<"\n the curretnRuleStr is"<<currentRuleStr;
    if(userRules.size()==0){
        //qWarning()<<__FILE__<<__LINE__;
        userRules.append(currentRule);
    } else if(userRules.contains(currentRule)){
        //qWarning()<<__FILE__<<__LINE__;
        QMessageBox::information (this,QObject::tr("提示"),QObject::tr("已存在该规则！"));
        return;
    }else{


        bool lastDealed=false;
        int i=0;
        for( i=0;i<userRules.size();i++){
            //qWarning()<<__FILE__<<__LINE__;
            QString ruleStr=QStringList(userRules.at(i)).join(",");
            //qDebug()<<"\n the ruleStr is "<<ruleStr;

            if(ruleStr==currentRuleStr){
                if(i==userRules.size()-1)
                    lastDealed=true;
                //qWarning()<<__FILE__<<__LINE__;
                QMessageBox::information (this,QObject::tr("提示"),QObject::tr("已存在该规则！"));
                return;
            }else if(this->ABContainsRelation(ruleStr,currentRuleStr)==1){
                if(i==adminRules.size()-1)
                    lastDealed=true;
                //qWarning()<<__FILE__<<__LINE__;
                int ok = QMessageBox::warning(this,tr("已存在该规则指定的特征码超集！"),tr("确定"
                                                                            "覆盖超集的规则吗？"),
                                              QMessageBox::Yes,QMessageBox::No);
                if(ok == QMessageBox::No)
                {
                    return;
                }else{
                    userRules[i]=currentRule;
                    //qWarning()<<__FILE__<<__LINE__;
                    break;
                }
            }else if(this->ABContainsRelation(currentRuleStr,ruleStr)==1){
                if(i==userRules.size()-1)
                    lastDealed=true;
                //qWarning()<<__FILE__<<__LINE__;
                int ok = QMessageBox::warning(this,tr("已存在以当前规则特征码为子集的规则!"),tr("确定"
                                                                               "覆盖子集的规则吗？"),
                                              QMessageBox::Yes,QMessageBox::No);
                if(ok == QMessageBox::No)
                {
                    return;
                }else{
                    //qWarning()<<__FILE__<<__LINE__;
                    userRules[i]=currentRule;
                    break;
                }

            }
            else {
                //qWarning()<<__FILE__<<__LINE__;
                continue;
            }


        }

        if(!lastDealed){
            //qDebug()<<"lastdealed false";
        }
        //qDebug()<<"the i is "<<QString::number(i);
        if((!lastDealed) && (i==userRules.size()) ){
            ////qWarning()<<__FILE__<<__LINE__;
            userRules.append(currentRule);
        }

    }

    this->showUserRules();
}

void MainWindow::on_pwdLineEdit_returnPressed()
{
    this->on_logInBtn_clicked();
}

void MainWindow::readInRules(QString fileName){
    ////qWarning()<<__FILE__<<__LINE__;
    QFile file(fileName);
    QString text=QObject::tr("");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream floStream(&file);
        text.append(floStream.readAll());
        file.close();
    }
    else{

    }
    ////qWarning()<<__FILE__<<__LINE__;
    // QList < QStringList > adminRules;
    //保存时要保证==前的为adminRules,==后的为userRules;
    //strcpy,ipIoAddIp,ipIoRemoveIp:ipIoAddIp,sockClone:asciiStrCopy,writeUnaligned64==strcpy,ipIoAddIp:ipIoAddIp
    QStringList rulesCutInType=text.split("==");
    if(rulesCutInType.size()==0){
        return;
    }else if(rulesCutInType.size()==1){
        QStringList rulesList=QString(rulesCutInType.at(0)).split(":");
        QStringList tempQSL;
        for(int i=0;i<rulesList.size();i++){
            tempQSL=QString(rulesList.at(i)).split(",");
            adminRules.append(tempQSL);
        }
    }else if(rulesCutInType.size()==2){
        QStringList rulesList=QString(rulesCutInType.at(0)).split(":");
        QStringList tempQSL;
        for(int i=0;i<rulesList.size();i++){
            tempQSL=QString(rulesList.at(i)).split(",");
            adminRules.append(tempQSL);
        }
        rulesList=QString(rulesCutInType.at(1)).split(":");
        for(int i=0;i<rulesList.size();i++){
            tempQSL=QString(rulesList.at(i)).split(",");
            userRules.append(tempQSL);
        }

    }

    this->showAdminRules();
    this->showUserRules();
}

void MainWindow::on_saveRulesBtn_clicked()
{
    //保存时要保证==前的为adminRules,==后的为userRules;
    //strcpy,ipIoAddIp,ipIoRemoveIp:ipIoAddIp,sockClone:asciiStrCopy,writeUnaligned64==strcpy,ipIoAddIp:ipIoAddIp
    QString ruleInfo;
    QStringList ruleQSL;
    QString rule;
    for(int i=0;i<adminRules.size();i++){
        rule=adminRules.at(i).join(",");
        if(!rule.isEmpty()){
            ruleQSL<<rule;
        }
    }
    ruleInfo=ruleQSL.join(":");
    ruleInfo.append("==");
    ruleQSL.clear();
    for(int i=0;i<userRules.size();i++){
        rule=userRules.at(i).join(",");
        if(!rule.isEmpty()){
            ruleQSL<<rule;
        }
    }
    ruleInfo.append(ruleQSL.join(":"));
    QFile ruleFile("rules.ini");
    if(ruleFile.open(QFile::ReadWrite|QIODevice::Truncate)){
        QTextStream stream( &ruleFile );
        stream<<ruleInfo;
        ruleFile.close();
        QMessageBox::information (this,QObject::tr("提示"),QObject::tr("危险UEFI文件规则已保存！"));
    }else{
        QMessageBox::warning(this, tr("信息安全检测量化评估系统服务分析端"), ruleFile.errorString());
    }


}

void MainWindow::on_adminRulesListWidget_itemActivated(QListWidgetItem* item)
{
    QString ruleInfo=item->text();
    QString ruleMainInfo=ruleInfo.split(":").at(1);
    //Strcpy,IpIoAddIp,IpIoRemoveIp,NetBufCopy,AsciiStrCopy,NetStringToIp,SockClone,Writeunaligned64
    if(ruleMainInfo.contains(tr("Strcpy"))){
        ui->StrcpyCheckBox->setChecked(true);
    }else{
        ui->StrcpyCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("IpIoAddIp"))){
        ui->IpIoAddIpCheckBox->setChecked(true);
    }else{
        ui->IpIoAddIpCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("IpIoRemoveIp"))){
        ui->IpIoRemoveIpCheckBox->setChecked(true);
    }else{
        ui->IpIoRemoveIpCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("NetBufCopy"))){
        ui->NetBufCopyCheckBox->setChecked(true);
    }else{
        ui->NetBufCopyCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("AsciiStrCopy"))){
        ui->AsciiStrCopyCheckBox->setChecked(true);
    }else{
        ui->AsciiStrCopyCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("NetStringToIp"))){
        ui->NetStringToIpCheckBox->setChecked(true);
    }else{
        ui->NetStringToIpCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("SockClone"))){
        ui->SockCloneCheckBox->setChecked(true);
    }else{
        ui->SockCloneCheckBox->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("WriteUnaligned64"))){
        ui->Writeunaligned64CheckBox->setChecked(true);
    }else{
        ui->Writeunaligned64CheckBox->setChecked(false);
    }

}

void MainWindow::on_userRulesListWidget_itemActivated(QListWidgetItem* item)
{
    QString ruleInfo=item->text();
    QString ruleMainInfo=ruleInfo.split(":").at(1);
    //Strcpy,IpIoAddIp,IpIoRemoveIp,NetBufCopy,AsciiStrCopy,NetStringToIp,SockClone,Writeunaligned64
    if(ruleMainInfo.contains(tr("Strcpy"))){
        ui->StrcpyCheckBox_2->setChecked(true);
    }else{
        ui->StrcpyCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("IpIoAddIp"))){
        ui->IpIoAddIpCheckBox_2->setChecked(true);
    }else{
        ui->IpIoAddIpCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("IpIoRemoveIp"))){
        ui->IpIoRemoveIpCheckBox_2->setChecked(true);
    }else{
        ui->IpIoRemoveIpCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("NetBufCopy"))){
        ui->NetBufCopyCheckBox_2->setChecked(true);
    }else{
        ui->NetBufCopyCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("AsciiStrCopy"))){
        ui->AsciiStrCopyCheckBox_2->setChecked(true);
    }else{
        ui->AsciiStrCopyCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("NetStringToIp"))){
        ui->NetStringToIpCheckBox_2->setChecked(true);
    }else{
        ui->NetStringToIpCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("SockClone"))){
        ui->SockCloneCheckBox_2->setChecked(true);
    }else{
        ui->SockCloneCheckBox_2->setChecked(false);
    }
    if(ruleMainInfo.contains(tr("WriteUnaligned64"))){
        ui->Writeunaligned64CheckBox_2->setChecked(true);
    }else{
        ui->Writeunaligned64CheckBox_2->setChecked(false);
    }

}

void MainWindow::on_DBManCheckBox_stateChanged(int checkInt )
{
    if(checkInt==0){
        ui->rulesManWidget->hide();
    }
}
