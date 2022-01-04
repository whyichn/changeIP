#ifndef CHANGEIPWIDGET_H
#define CHANGEIPWIDGET_H
#include <inputform.h>

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ChangeIPWidget; }
QT_END_NAMESPACE

class ChangeIPWidget : public QWidget
{
    Q_OBJECT

public:
    ChangeIPWidget(QWidget *parent = nullptr);
    ~ChangeIPWidget();
    void QueryIP();
    bool ClearBuf();
    void SetIPDynamic();
    void SetIPOLD();
    void SetIPNEW();
    void chanegInputIP();



private slots:
    void on_textEdit_textChanged();

    void on_btn_input_clicked();

private:
    Ui::ChangeIPWidget *ui;
    inputForm *inputform;

};
#endif // CHANGEIPWIDGET_H
