/* Resurse:
  edit pic with: https://pixlr.com/x/
   https://doc.qt.io/
   https://doc.qt.io/archives/3.3/clientserver-example.html
   qt tutorials: https://www.youtube.com/channel/UCL6h8AbNBjHMuxwy8NILDUA
                 https://www.youtube.com/channel/UCs6nmQViDpUw0nuIx9c_WvA
   https://www.geeksforgeeks.org/ - string/char manipulations
   https://profs.info.uaic.ro/~computernetworks/cursullaboratorul.php

*/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "/home/raluca/projects/Server/rapidxml-1.13/rapidxml.hpp" //XML parser library
#include "/home/raluca/projects/Server/rapidxml-1.13/rapidxml_ext.hpp"

using namespace rapidxml;
using namespace std;

/* portul folosit */
#define PORT 2908
#define MAX_SIZE 4096

/* codul de eroare returnat de anumite apeluri */
extern int errno;

typedef struct thData{
	int idThread; //id-ul thread-ului tinut in evidenta de acest program
	int cl; //descriptorul intors de accept
}thData;

int get_id(void *);
void login(void *);
string readXMLfile();
void show_trains_info(void *);
void update_delays(void *);
void next_hour_departures(void *);
void next_hour_arrivals(void *);
void what_function_to_use(int function_id, void *);
static void *treat(void *); /* functia executata de fiecare thread ce realizeaza comunicarea cu clientii */

int main ()
{
  struct sockaddr_in server;	// structura folosita de server
  struct sockaddr_in from;	
  int sd;		//descriptorul de socket 
  int pid;
  pthread_t th[100];    //Identificatorii thread-urilor care se vor crea
	int i=0;
  

  /* crearea unui socket */
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
      perror ("[server]Eroare la socket().\n");
      return errno;
    }
  /* utilizarea optiunii SO_REUSEADDR */
  int on=1;
  setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&on,sizeof(on));
  
  /* pregatirea structurilor de date */
  bzero (&server, sizeof (server));
  bzero (&from, sizeof (from));
  
  /* umplem structura folosita de server */
  /* stabilirea familiei de socket-uri */
    server.sin_family = AF_INET;	
  /* acceptam orice adresa */
    server.sin_addr.s_addr = htonl (INADDR_ANY);
  /* utilizam un port utilizator */
    server.sin_port = htons (PORT);
  
  /* atasam socketul */
  if (bind (sd, (struct sockaddr *) &server, sizeof (struct sockaddr)) == -1)
    {
      perror ("[server]Eroare la bind().\n");
      return errno;
    }

  /* punem serverul sa asculte daca vin clienti sa se conecteze */
  if (listen (sd, 2) == -1)
    {
      perror ("[server]Eroare la listen().\n");
      return errno;
    }
  /* servim in mod concurent clientii...folosind thread-uri */
  while (1)
    {
      int client;
      thData * td; //parametru functia executata de thread     
      unsigned int length = sizeof (from);

      printf ("[server]Asteptam la portul %d...\n",PORT);
      fflush (stdout);

      // client= malloc(sizeof(int));
      /* acceptam un client (stare blocanta pana la realizarea conexiunii) */
      if ( (client = accept (sd, (struct sockaddr *) &from, &length)) < 0)
	{
	  perror ("[server]Eroare la accept().\n");
	  continue;
	}
	
        /* s-a realizat conexiunea, se astepta mesajul */
    
	// int idThread; //id-ul threadului
	// int cl; //descriptorul intors de accept

	td=(struct thData*)malloc(sizeof(struct thData));	
	td->idThread=i++;
	td->cl=client;

	pthread_create(&th[i], NULL, &treat, td);	      
				
	}   
};				
static void *treat(void * arg)
{		
		struct thData tdL; 
		tdL= *((struct thData*)arg);	
		printf ("[thread]- %d - Asteptam mesajul...\n", tdL.idThread);
        //printf ("[thread] Asteptam mesajul...\n");
		fflush (stdout);		 
		pthread_detach(pthread_self());	
    bool running=1;	
		//raspunde((struct thData*)arg);

    while(running){
      int id=get_id((struct thData*)arg);
      cout<<id<<endl;
      what_function_to_use(id, (struct thData*)arg);
      if(id==3){
        running=false;
        close ((intptr_t)arg);
		    return(NULL);
      }
          }
  		
}
int get_id(void * arg){
  int id;
  struct thData tdL;
  tdL= *((struct thData*)arg);
  if (read (tdL.cl, &id,sizeof(int)) <= 0)
			{
			  printf("[Thread %d]\n",tdL.idThread);
			  perror ("Eroare la read() de la client.\n");
			
			}
    bool ok=1;
  if (write (tdL.cl, &ok, sizeof(bool)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
  return id;
}
void what_function_to_use(int function_id, void * arg){
  switch(function_id){
    case 1:  { 
      login((struct thData*)arg);
      break;
      }
    case 2: { 
      show_trains_info((struct thData*)arg);
		  break;	
      }
    case 3: {
      //quit 
      break;
    }
    case 4: {
      update_delays((struct thData*)arg);
      break;
    }
    case 5: {
      next_hour_departures((struct thData*)arg);
      break;
    }
    case 6: {
      next_hour_arrivals((struct thData*)arg);
      break;
    }
    default: {
      cout<<"I don't know what function to use!";
      break;}
    
  }
}
void login(void * arg){
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    struct thData tdL; 
    tdL= *((struct thData*)arg);
		//tdL= *((struct thData*)arg);
    bool username_received=0;
    if (read (tdL.cl, &username,MAX_SIZE) <= 0)
			{
			  printf("[Thread %d]\n",tdL.idThread);
			  perror ("Eroare la read() de la client.\n");
      }
      cout<<username<<endl;
      username_received=1;
      if (write (tdL.cl, &username_received, sizeof(bool)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
    if (read (tdL.cl, &password,MAX_SIZE) <= 0)
			{
			  printf("[Thread %d]\n",tdL.idThread);
			  perror ("Eroare la read() de la client.\n");
      }
    cout<<password<<endl;
    FILE *fp;
    bool check_credentials=false;
            
    if((fp = fopen("admins.txt", "r")) == NULL) {
        cout<<"could not open file";
	        perror("Opening file error.\n");
            }
            string line;
            ifstream infile("admins.txt");

               while(infile>>line && check_credentials==false){
                 char s[100];
                 strcpy(s,line.c_str());
                if((!strcmp(username,strtok(s,","))) && (!strcmp(password,strtok(NULL,",")))) {
                    check_credentials=true;
                    infile.close();
                    break;
                } 
           }
            
        cout<<check_credentials<<endl;

        if (write (tdL.cl,&check_credentials, sizeof(bool)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
}
string readXMLfile(){
  xml_document<> data;
  xml_node<> * root_node = NULL;
   
    // Read the file
    ifstream myFile ("Schedule.xml");
    vector<char> buffer((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
   
    // Parse the buffer
    data.parse<0>(&buffer[0]);
   
    // Find out the root node
    root_node = data.first_node("trains");
    string info="\0";
    // Iterate over the nodes
    for (xml_node<> * train_node = root_node->first_node("train"); train_node; train_node = train_node->next_sibling())
    {
         
            xml_node<> * train_ID_node = train_node->first_node("train_ID");
            info+="Train ID: ";
            info+= train_ID_node->value();
            info+= "\n";
            xml_node<> * from_node = train_node->first_node("from");
            info+="From: ";
            info+= from_node->value();
            info+= "\n";
            xml_node<> * to_node = train_node->first_node("to");
            info+="To: "; 
            info+= to_node->value(); 
            info+= "\n";
            xml_node<> * departure_node = train_node->first_node("departure_time");
            info+="Scheduled departure time: ";
            info+= departure_node->value(); 
            info+= "\n";
            xml_node<> * arrival_node = train_node->first_node("arrival_time");
            info+="Scheduled arrival time: ";
            info+= arrival_node->value(); 
            info+= "\n";
            info=info+"\n"; 
      
    }
    return info;
}
void show_trains_info(void * arg){
    struct thData tdL; 
    tdL= *((struct thData*)arg);
    string data=readXMLfile();
    char infoTrains[data.length()+1];
    strcpy(infoTrains,data.c_str());
    if (write (tdL.cl, &infoTrains, (strlen(infoTrains)+1)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
}
void update_delays(void * arg){
    struct thData tdL; 
    tdL= *((struct thData*)arg);
    int delay;
    char id_train[MAX_SIZE];
    bool delay_received=0;
    if (read (tdL.cl, &delay,sizeof(int)) <= 0)
			{
			  printf("[Thread %d]\n",tdL.idThread);
			  perror ("Eroare la read() de la client.\n");
      }
      cout<<delay<<endl;
      delay_received=1;
    if (write (tdL.cl, &delay_received, sizeof(bool)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
    if (read (tdL.cl, &id_train,MAX_SIZE) <= 0)
			{
			  printf("[Thread %d]\n",tdL.idThread);
			  perror ("Eroare la read() de la client.\n");
      }
      cout<<id_train<<endl;
    //now we look for the train in xml by the id and update the delay and eta
      bool update_successful=false;
      xml_document<> data;
      xml_node<> * root_node = NULL;
   
    // Read the sample.xml file
    ifstream myFile ("Schedule.xml");
    vector<char> buffer((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
   
    // Parse the buffer
    data.parse<rapidxml::parse_no_data_nodes>(&buffer[0]);
   
    // Find out the root node
    root_node = data.first_node("trains");
    // Iterate over the nodes
    for (xml_node<> * train_node = root_node->first_node("train"); train_node; train_node = train_node->next_sibling())
    {
      xml_node<> * train_ID_node = train_node->first_node("train_ID");
      xml_node<> * delay_minutes_node = train_node->first_node("delay_minutes");
      xml_node<> *arrival_time_node = train_node->first_node("arrival_time");
      xml_node<> * eta_node = train_node->first_node("eta");
      char id[MAX_SIZE];
      strcpy(id,train_ID_node->value());
      //cout<<id<<endl;
      if(!strcmp(id_train,id)){
        string delay_string=to_string(delay);
        string eta;
        char arrival_time[MAX_SIZE];
        strcpy(arrival_time,arrival_time_node->value());
        char *hours=strtok(arrival_time,":");
        char *minutes=strtok(NULL,":");
        int h=atoi(hours);
        int m=atoi(minutes);
        cout<<h<<":"<<m<<endl;
        h=h+(m+delay)/60;
        if(h>=24)
        h=h-24;
        m=(m+delay)%60;
        if((h<10)&&(m<10))
        eta="0"+to_string(h)+":0"+to_string(m);
        else if(h<10)
        eta="0"+to_string(h)+":"+to_string(m);
        else if(m<10)
        eta=to_string(h)+":0"+to_string(m);
        else
        eta=to_string(h)+":"+to_string(m);
        cout<<eta;
        const char * new_value=data.allocate_string(delay_string.c_str(), strlen(delay_string.c_str()));
        const char * new_eta=data.allocate_string(eta.c_str(), strlen(eta.c_str()));
        delay_minutes_node->value(new_value);
        eta_node->value(new_eta);
        string new_data;
        rapidxml::print(std::back_inserter(new_data),data);
        myFile.close();
        std::ofstream file;
        file.open("Test.xml",std::ofstream::trunc);
        file << new_data;
        file.close();
    
      }
    }
    update_successful=true;
     if (write (tdL.cl, &update_successful, sizeof(bool)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
}
void next_hour_departures(void * arg){
    struct thData tdL; 
    tdL= *((struct thData*)arg);
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    int current_time_hour = local_time->tm_hour;
    int current_time_minutes = local_time->tm_min;
   

    //parse again and display only the next hour departures
    xml_document<> data;
    xml_node<> * root_node = NULL;
   
    // Read the schedule.xml file
    ifstream myFile ("Schedule.xml");
    vector<char> buffer((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
   
    // Parse the buffer
    data.parse<0>(&buffer[0]);
   
    // Find out the root node
    root_node = data.first_node("trains");
    string info="\0";

    // Iterate over the nodes
    for (xml_node<> * train_node = root_node->first_node("train"); train_node; train_node = train_node->next_sibling())
    {
         
            xml_node<> * train_ID_node = train_node->first_node("train_ID");
            xml_node<> * from_node = train_node->first_node("from");
            xml_node<> * to_node = train_node->first_node("to");
            xml_node<> * departure_node = train_node->first_node("departure_time");
            xml_node<> * delay_minutes_node = train_node->first_node("delay_minutes");
            xml_node<> * eta_node = train_node->first_node("eta");
            char departure_time[MAX_SIZE];
            strcpy(departure_time,departure_node->value());
            char *hours=strtok(departure_time,":");
            char *minutes=strtok(NULL,":");
            int h=atoi(hours);
            int m=atoi(minutes);
            if(((current_time_hour==h)&&(current_time_minutes<=m))||(((current_time_hour+1)==h)&&(current_time_minutes>=m))){
            info+="Train ID: ";
            info+= train_ID_node->value();
            info+= "\n";
            info+="Departs from: ";
            info+= from_node->value();
            info+= "\n";
            info+="To: "; 
            info+= to_node->value(); 
            info+= "\n";
            info+="Original departure time: ";
            info+= departure_node->value(); 
            info+=". ";
            info+= delay_minutes_node->value(); 
            info+=" minutes delay.";
            info+= "\n";
            info+="Estimated Time of Arrival: ";
            info+= eta_node->value(); 
            info+= "\n";
            info=info+"\n"; }
      
    }
    //cout<<info<<endl;
    char infoDepartures[MAX_SIZE];
    if(info.empty()){
      strcpy(infoDepartures,"No departures scheduled in the next hour! Come back later.");
    }
    else{
    strcpy(infoDepartures,info.c_str());
    }
    if (write (tdL.cl, &infoDepartures, (strlen(infoDepartures)+1)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
}
void next_hour_arrivals(void * arg){
    struct thData tdL; 
    tdL= *((struct thData*)arg);
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    int current_time_hour = local_time->tm_hour;
    int current_time_minutes = local_time->tm_min;
   

    //parse again and display only the next hour departures
    xml_document<> data;
    xml_node<> * root_node = NULL;
   
    // Read the schedule.xml file
    ifstream myFile ("Schedule.xml");
    vector<char> buffer((istreambuf_iterator<char>(myFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');
   
    // Parse the buffer
    data.parse<0>(&buffer[0]);
   
    // Find out the root node
    root_node = data.first_node("trains");
    string info="\0";

    // Iterate over the nodes
    for (xml_node<> * train_node = root_node->first_node("train"); train_node; train_node = train_node->next_sibling())
    {
         
            xml_node<> * train_ID_node = train_node->first_node("train_ID");
            xml_node<> * from_node = train_node->first_node("from");
            xml_node<> * to_node = train_node->first_node("to");
            xml_node<> * arrival_node = train_node->first_node("arrival_time");
            xml_node<> * delay_minutes_node = train_node->first_node("delay_minutes");
            xml_node<> * eta_node = train_node->first_node("eta");
            char arrival_time[MAX_SIZE];
            strcpy(arrival_time,arrival_node->value());
            char *hours=strtok(arrival_time,":");
            char *minutes=strtok(NULL,":");
            int h=atoi(hours);
            int m=atoi(minutes);
            if(((current_time_hour==h)&&(current_time_minutes<=m))||(((current_time_hour+1)==h)&&(current_time_minutes>=m))){
            info+="Train ID: ";
            info+= train_ID_node->value();
            info+= "\n";
            info+="Departed from: ";
            info+= from_node->value();
            info+= "\n";
            info+="Arrives at: "; 
            info+= to_node->value(); 
            info+= "\n";
            info+= delay_minutes_node->value(); 
            info+=" minutes delay.";
            info+="Estimated Time of Arrival: ";
            info+= eta_node->value(); 
            info+= "\n";
            info=info+"\n"; }
      
    }
    //cout<<info<<endl;
    char infoArrivals[MAX_SIZE];
    if(info.empty()){
      strcpy(infoArrivals,"No arrivals scheduled in the next hour! Come back later.");
    }
    else{
    strcpy(infoArrivals,info.c_str());
    }
    if (write (tdL.cl, &infoArrivals, (strlen(infoArrivals)+1)) <= 0)
		{
		 printf("[Thread %d] ",tdL.idThread);
		 perror ("[Thread]Eroare la write() catre client.\n");
		}
}
