#include "Graph.h"
#include <QtWidgets/QApplication>
#include "graph.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph w;
    w.show();
    w.resize(900, 900);

  
    return a.exec();
}
