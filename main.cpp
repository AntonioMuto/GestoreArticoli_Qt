#include "gestore.h"
#include "ui_gestore.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Gestore w;
    w.show();
    return a.exec();
}
