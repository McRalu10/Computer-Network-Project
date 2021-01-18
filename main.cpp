#include "client.h"
#include "client.cpp"
#include <QApplication>

int main(int argc, char *argv[]){

    QApplication app(argc, argv);
    MainWindow window;
    window.create_socket();
    window.connectToServer();
    window.show();
    return app.exec();
}
