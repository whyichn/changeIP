#include "inputform.h"
#include "ui_inputform.h"
#include <QProcess>
#include <QComboBox>

inputForm::inputForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inputForm)
{
    ui->setupUi(this);
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==0)
        {ipaddr = QString("10.104.5.132");
        ui->comboBox->setEditable(false);
        }
        else if(index==1)
        {
            ipaddr = QString("10.104.0.113");
            ui->comboBox->setEditable(false);
        }else if(index==2)
             {ui->comboBox->setEditable(true);
            ui->comboBox->lineEdit()->setReadOnly(false);
            ui->comboBox->lineEdit()->clear();
    }});

    connect(ui->comboBox_2,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index){
        if(index==0)
        {mask = QString("255.255.254.0");
            ui->comboBox_2->setEditable(false);}
        else if(index==1)
          {mask = QString("255.255.254.0");
        ui->comboBox->setEditable(false);}
        else if(index==2)
             {ui->comboBox_2->setEditable(true);
            ui->comboBox_2->lineEdit()->setReadOnly(false);
            ui->comboBox_2->lineEdit()->clear();
    }});

}

inputForm::~inputForm()
{
    delete ui;
}

void inputForm::on_pushButton_clicked()
{

    if(ui->comboBox->currentIndex()==2)
    {
        ipaddr=QString(ui->comboBox->lineEdit()->text());
    }
    if(ui->comboBox_2->currentIndex()==2)
    {
        mask=QString(ui->comboBox_2->lineEdit()->text());
    }
    QString adapter = QString(ui->lineEdit->text());
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

