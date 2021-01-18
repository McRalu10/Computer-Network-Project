#ifndef CLIENT_H
#define CLIENT_H

#include "ui_client.h"
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QMessageBox>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <QDateTime>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int sd;
    struct sockaddr_in server;
    QString train_ID_delayed;
    int delay=0;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void create_socket();

    void connectToServer();

private slots:
    void on_admin_clicked();

    void on_guest_clicked();

    void on_quit_clicked();

    void on_logout_clicked();

    void on_bactToPage1_clicked();

    void on_departures_clicked();

    void on_arrivals_clicked();

    void on_backToPage3_clicked();


    void on_back_button_clicked();

    void display_time();

    void on_submit_login_clicked();


    void on_horizontalSlider_valueChanged(int value);

    void on_train_ID_currentIndexChanged(const QString &arg1);

    void on_submit_delay_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // CLIENT_H
