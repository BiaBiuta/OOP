#include "QtWidgetsApplication2.h"
#include <QtWidgets/QApplication>
//#include <QtCore/QCoreApplication>
#include"obiect.h"
#include"service.h"
#include"CosGUI.h"
#include"gui.h"
//#include"ui.h"
//#include"Teste.h"
void Rungui(int argc, char* argv[]) {
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QtWidgetsApplication2 w;
    RepoException msg{ msg };
    vector<Obiect> vector;
    ObiectRepoFile rep{ "obiecte.txt" };
    Validare v;
    ObiectService serv{ rep,v };
    //CosGui cos{ serv.getCos(),serv};
    //cos.show();
    ObiectGui gui{ serv};
    gui.show();
    a.exec();
}
int main(int argc, char* argv[])
{
    //Teste t;
    //t.testeAll();
    Rungui(argc, argv);

    return 0;
}
