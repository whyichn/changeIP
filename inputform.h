#ifndef INPUTFORM_H
#define INPUTFORM_H

#include <QWidget>

class ChangeIPWidget;
namespace Ui {
class inputForm;
}

class inputForm : public QWidget
{
    Q_OBJECT

public:
    explicit inputForm(QWidget *parent = nullptr);
    ~inputForm();

signals:
    void sendSignal();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::inputForm *ui;
    ChangeIPWidget *parentWidge;
};

#endif // INPUTFORM_H
