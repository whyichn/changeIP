#include "changeipwidget.h"
#include "ui_changeipwidget.h"
#include <winsock2.h>
#include <iphlpapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <QProcess>
#include <QDebug>
#include <QTextCursor>


#pragma comment(lib, "IPHLPAPI.lib")

#define WORKING_BUFFER_SIZE 15000
#define MAX_TRIES 3

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

ChangeIPWidget::ChangeIPWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeIPWidget)
{
    ui->setupUi(this);
    connect(ui->btn_ClearBUF,&QPushButton::clicked,this,&ChangeIPWidget::ClearBuf);
    connect(ui->btn_SetIPDynamic,&QPushButton::clicked,this,&ChangeIPWidget::SetIPDynamic);
    connect(ui->btn_SetIPNEW,&QPushButton::clicked,this,&ChangeIPWidget::SetIPNEW);
    connect(ui->btn_SetIPOLD,&QPushButton::clicked,this,&ChangeIPWidget::SetIPOLD);
    connect(ui->btn_QueryIP,&QPushButton::clicked,this,&ChangeIPWidget::QueryIP);
//    ui->btn_SetIPDynamic->setEnabled(false);
}

ChangeIPWidget::~ChangeIPWidget()
{
    delete ui;
}

void ChangeIPWidget::QueryIP()
{

    QProcess p(0);
    p.start("ipconfig");
    p.waitForStarted();
    p.waitForFinished();
   ui->textEdit->append(QString::fromLocal8Bit(p.readAllStandardOutput()));
//   ui->textEdit->moveCursor(QTextCursor::End);

}

void ChangeIPWidget::SetIPNEW()
{
    QProcess p(0);
     p.start("netsh", QStringList()<<"interface"<<"ip"<<"set"<<"address"<<"name=\"以太网\""<<"source=static"<<"addr=10.104.0.113"<<"mask=255.255.254.0");
       p.waitForStarted();
        p.closeWriteChannel();
    p.waitForFinished();
    ui->textEdit->append("已设置为新版IP");
//    ui->textEdit->moveCursor(QTextCursor::End);

}

void ChangeIPWidget::SetIPOLD()
{
    QProcess p(0);
     p.start("netsh", QStringList()<<"interface"<<"ip"<<"set"<<"address"<<"name=\"以太网\""<<"source=static"<<"addr=10.104.5.132"<<"mask=255.255.254.0");
       p.waitForStarted();
        p.closeWriteChannel();
    p.waitForFinished();
    ui->textEdit->append("已设置为旧版IP");
//    ui->textEdit->moveCursor(QTextCursor::End);
}

void ChangeIPWidget::SetIPDynamic()
{
    QProcess p(0);
     p.start("netsh", QStringList()<<"interface"<<"ip"<<"set"<<"address"<<"name=\"以太网\""<<"dhcp");
     p.waitForStarted();
     p.closeWriteChannel();
    p.waitForFinished();
    ui->textEdit->append("已恢复动态IP");
//    ui->textEdit->moveCursor(QTextCursor::End);

}

bool ChangeIPWidget::ClearBuf()
{
    ui->textEdit->clear();
    ui->textEdit->append("缓冲区已清空");
    return TRUE;
}

void ChangeIPWidget::on_textEdit_textChanged()
{
    ui->textEdit->moveCursor(QTextCursor::End);

}


void ChangeIPWidget::on_btn_input_clicked()
{
    inputform = new inputForm();
    connect(inputform,&inputForm::sendSignal,this,&ChangeIPWidget::chanegInputIP);
    inputform->show();

}

void ChangeIPWidget::chanegInputIP()
{
    ui->textEdit->append("IP设置成功");
}
