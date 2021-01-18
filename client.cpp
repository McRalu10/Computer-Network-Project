#include "client.h"
#include <string>
#include<cstring>
#include <iostream>
using namespace std;
/* codul de eroare returnat de anumite apeluri */
extern int errno;

/* portul de conectare la server*/
#define port 2908
#define MAX_SIZE 4096

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap cover("/home/raluca/projects/RC_Project/train.png");
    ui->label->setPixmap(cover);
    int myWidth=this->size().width();
    int myHeight=this->size().height();
    ui->label->resize(myWidth,myHeight/2.5);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setMinimum(-100);
    ui->horizontalSlider->setMaximum(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_socket(){
    if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
      {
        perror ("Eroare la socket().\n");
        exit(EXIT_FAILURE);
      }
}

void MainWindow::connectToServer(){
    /* umplem structura folosita pentru realizarea conexiunii cu serverul */
      /* familia socket-ului */
      server.sin_family = AF_INET;
      /* adresa IP a serverului */
      server.sin_addr.s_addr = inet_addr("127.0.0.1");
      /* portul de conectare */
      server.sin_port = htons (port);

      /* ne conectam la server */
      if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
        {
          perror ("[client]Eroare la connect().\n");
          exit(EXIT_FAILURE);
        }

        printf("Te-ai conectat!");
}

void MainWindow::on_admin_clicked()
{
    ui->pages->setCurrentIndex(1);
}

void MainWindow::on_guest_clicked()
{
    int function_id=2;

    if (write (sd,&function_id,sizeof(int)) <= 0)
       {
         printf ("[client]Eroare la write() spre server.\n");
         exit(EXIT_FAILURE);
       }
    bool ok;
    if (read (sd, &ok,sizeof(bool)) < 0)
        {
          printf ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }
    char infoTrains[MAX_SIZE];
    if(ok){
        if (read (sd, &infoTrains,MAX_SIZE) < 0)
            {
              printf ("[client]Eroare la read() de la server.\n");
              exit(EXIT_FAILURE);}

        ui->info_label->setText(infoTrains);
        ui->pages->setCurrentIndex(3);
    }
}

void MainWindow::on_quit_clicked()
{
    int function_id=3;

    if (write (sd,&function_id,sizeof(int)) <= 0)
       {
         printf ("[client]Eroare la write() spre server.\n");
         exit(EXIT_FAILURE);
       }
    bool ok;
    if (read (sd, &ok,sizeof(bool)) < 0)
        {
          printf ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }
        if(ok)
        this->close();
}

void MainWindow::on_logout_clicked()
{
    ui->pages->setCurrentIndex(0);
}

void MainWindow::on_bactToPage1_clicked()
{
    ui->pages->setCurrentIndex(0);
}

void MainWindow::on_departures_clicked()
{
    int function_id=5;

    if (write (sd,&function_id,sizeof(int)) <= 0)
       {
         printf ("[client]Eroare la write() spre server.\n");
         exit(EXIT_FAILURE);
       }
    bool ok;
    if (read (sd, &ok,sizeof(bool)) < 0)
        {
          printf ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }
    char infoDepartures[MAX_SIZE];
    if(ok){
        if (read (sd, &infoDepartures,MAX_SIZE) < 0)
            {
              printf ("[client]Eroare la read() de la server.\n");
              exit(EXIT_FAILURE);}
        //cout<<infoDepartures;
        ui->next_hour_label->setText(infoDepartures);
        ui->pages->setCurrentIndex(4);
    }

}

void MainWindow::on_arrivals_clicked()
{
    int function_id=6;

    if (write (sd,&function_id,sizeof(int)) <= 0)
       {
         printf ("[client]Eroare la write() spre server.\n");
         exit(EXIT_FAILURE);
       }
    bool ok;
    if (read (sd, &ok,sizeof(bool)) < 0)
        {
          printf ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }
    char infoArrivals[MAX_SIZE];
    if(ok){
        if (read (sd, &infoArrivals,MAX_SIZE) < 0)
            {
              printf ("[client]Eroare la read() de la server.\n");
              exit(EXIT_FAILURE);}

        ui->next_hour_label->setText(infoArrivals);
        ui->pages->setCurrentIndex(4);
    }
}

void MainWindow::on_backToPage3_clicked()
{
    ui->pages->setCurrentIndex(3);
}



void MainWindow::on_back_button_clicked()
{
    ui->pages->setCurrentIndex(0);
}
void MainWindow::display_time(){

    QTime time = QTime::currentTime();
    ui->date_time->display(time.toString("hh:mm:ss"));
}
void MainWindow::on_submit_login_clicked()
{
    QString username=ui->username->text();
    QString password=ui->password->text();
    int function_id=1;//login are id=1;
    char user[MAX_SIZE];
    strcpy(user,username.toStdString().c_str());
    char pass[MAX_SIZE];
    strcpy(pass,password.toStdString().c_str());
    //cout<<user<<" "<<pass;
    if (write (sd,&function_id,sizeof(int)) <= 0)
       {
         printf ("[client]Eroare la write() spre server.\n");
         exit(EXIT_FAILURE);
       }
    bool ok;
    if (read (sd, &ok,sizeof(bool)) < 0)
        {
          printf ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }


    if(ok){ //serverul a primit id-ul de functie si o apeleaza
        if (write (sd,&user,strlen(user)+1) <= 0) //trimitem username-ul introdus de client
           {
             cout<<user;
            printf ("[client]Eroare la write() username spre server.\n");
             exit(EXIT_FAILURE);
           }
        bool username_received=0;;
             if (read(sd, &username_received, sizeof(bool)) <= 0)
               {
                 printf ("[client]Eroare la read() de la server.\n");
                 exit(EXIT_FAILURE);
               }
             if(username_received){
                 if (write (sd,&pass,strlen(pass)+1) <= 0) //trimitem username-ul introdus de client
                    {
                      cout<<pass;
                     printf ("[client]Eroare la write() username spre server.\n");
                      exit(EXIT_FAILURE);
                    }
             }
    }
    bool check_credentials;
    if (read (sd, &check_credentials,sizeof(bool)) < 0)
        {
          perror ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }
    //cout<<check_credentials;
    if(!check_credentials){
            QString error=ui->error_label->text();
            cout<<error.toStdString();
            error.append("Username or password invalid!");
            ui->error_label->setText(error);;
            ui->error_label->setStyleSheet("color: red");

    }
    else{
    ui->pages->setCurrentIndex(2);
    QTimer *timer = new QTimer(this);
    connectQT(timer, &QTimer::timeout, this, &MainWindow::display_time);
        timer->start();
    }
}



void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    delay=value;
    QString minutes_delay=QString::number(value);
    QString text_delay=minutes_delay+" minutes";
    ui->delay->setText(text_delay);
}

void MainWindow::on_train_ID_currentIndexChanged(const QString &arg1)
{
    train_ID_delayed=arg1;
}

void MainWindow::on_submit_delay_clicked()
{
    //cout<<delay;
    char train_ID[MAX_SIZE];
    //cout<<train_ID_delayed.toStdString();
    strcpy(train_ID,train_ID_delayed.toStdString().c_str());
    int function_id = 4;
    if (write (sd,&function_id,sizeof(int)) <= 0)
       {
         printf ("[client]Eroare la write() spre server.\n");
         exit(EXIT_FAILURE);
       }
    bool ok;
    if (read (sd, &ok,sizeof(bool)) < 0)
        {
          printf ("[client]Eroare la read() de la server.\n");
          exit(EXIT_FAILURE);
        }
    cout<<ok;
    if(ok){
        if (write (sd,&delay,sizeof(int)) <= 0)
           {
             printf ("[client]Eroare la write() spre server.\n");
             exit(EXIT_FAILURE);
           }
        bool delay_sent=0;
        if (read (sd, &delay_sent,sizeof(bool)) < 0)
            {
              printf ("[client]Eroare la read() de la server.\n");
              exit(EXIT_FAILURE);
            }
        delay_sent=1;
        if(delay_sent){
            if (write (sd,&train_ID,strlen(train_ID)+1) <= 0)
               {
                 printf ("[client]Eroare la write() spre server.\n");
                 exit(EXIT_FAILURE);
               }
            bool update_successful=false;
            if (read (sd, &update_successful,sizeof(bool)) < 0)
                {
                  printf ("[client]Eroare la read() de la server.\n");
                  exit(EXIT_FAILURE);
                }
            if(update_successful){
                QMessageBox msgBox;
                msgBox.setText("Delay has been added successfully!");
                msgBox.exec();
            }
        }

    }

}
