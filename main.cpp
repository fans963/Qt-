#include <QApplication>
#include "ElaApplication.h"
#include "loading.h"
#include <QResource>
#include <QDebug>
#include "gamepanel.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    qRegisterMetaType<Cards>("Cards&");
    qRegisterMetaType<Cards>("Cards");
    QResource::registerResource("D:/qtdoudizhu/doudizhu/doudizhu/resource.rcc");
    ElaApplication::getInstance()->init();

    Loading w;
    w.show();
    return a.exec();
}
