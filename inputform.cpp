#include "inputform.h"
#include "ui_inputform.h"
#include <QProcess>
#include "changeipwidget.h"

inputForm::inputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputForm)
{
    ui->setupUi(this);
    parentWidge = static_cast<ChangeIPWidget*>(parent);

}

inputForm::~inputForm()
{
    delete ui;
}

void inputForm::on_pushButton_clicked()
{
    QString adapter = QString(ui->lineEdit->text());
    QString ipaddr  = QString(ui->lineEdit_2->text());
    QString mask    = QString(ui->lineEdit_3->text());
    QProcess p(0);
    p.start("netsh", QStringList()<<"interface"<<"ip"<<"set"<<"address"<<adapter<<"source=static"<<ipaddr<<mask);
    p.waitForStarted();
    p.closeWriteChannel();
    p.waitForFinished();
    emit sendSignal();
    this->close();
}


void inputForm::on_pushButton_2_clicked()
{
    this->close();
}

