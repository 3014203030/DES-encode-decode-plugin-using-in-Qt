#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pB_encrypt,SIGNAL(clicked()),this,SLOT(encrypt()));
    connect(ui->pB_decrypt,SIGNAL(clicked()),this,SLOT(decrypt()));
    des = new JSDES;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::encrypt(){
    QString DESkey = ui->keyText->text();
    QString _data = ui->encryptText->toPlainText().toLocal8Bit();
    ui->decryptText->clear();
    if(DESkey.isEmpty()||_data.isEmpty()){
        //打印日志
        showLogs("Text encode error.. ..","#EC5228");
    }else{
        QString data = des->DES_encode(_data,DESkey);
        if(ui->checkBase64->checkState() == Qt::Checked){
            ui->decryptText->setPlainText(data);
        }else{
            ui->decryptText->setPlainText(QByteArray::fromBase64(data.toLocal8Bit()));
        }
        showLogs("Congratulations, text encode success!","#65B265");
    }
}
void MainWindow::decrypt(){
    QString DESkey = ui->keyText->text();
    QString _data = ui->decryptText->toPlainText().toLocal8Bit();
    ui->encryptText->clear();
    if(DESkey.isEmpty()||_data.isEmpty()){
        //打印日志
        showLogs("Text decode error.. ..","#EC5228");
    }else{
        QString data = des->DES_decode(_data,DESkey);
        if(ui->checkBase64->checkState() == Qt::Checked){
            ui->encryptText->setPlainText(data);
        }else{
            ui->encryptText->setPlainText(QByteArray::fromBase64(data.toLocal8Bit()));
        }
        showLogs("Congratulations, text decode success!","#65B265");
    }
}
void MainWindow::showLogs(QString text, QString color){
    if(color == ""){color = "#000000";}
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("MM.dd hh:mm:ss ");
    QString log = current_date+":"+"<font color=\""+color+"\">"+text+"</font>";
    ui->logText->append(log);
    //移动光标到末尾
    QTextCursor cursor = ui->logText->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->logText->setTextCursor(cursor);
}
