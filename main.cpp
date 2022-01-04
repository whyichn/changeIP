#include "changeipwidget.h"

#include <QApplication>
#include <QPushButton>
#include <QStyle>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChangeIPWidget w;

    w.show();
//    a.setStyle(new QPlastiqueStyle);
    return a.exec();
}
