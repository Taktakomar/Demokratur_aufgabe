#include <iostream>
#include<windows.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <chrono>
#include<unistd.h>
#include<farbe_code.h>
#include<partei.h>
#include<einwohner.h>
#include <sstream>
using namespace std;
int c ;
 farbe_code farbe[6];
void farbe_fuhlen(farbe_code farbe[])
{
    farbe[0]=farbe_code(15,"weiß ");
    farbe[1]=farbe_code(2,"Grün");
    farbe[2]=farbe_code(4,"Rot");
    farbe[3]=farbe_code(6,"Orange");
    farbe[4]=farbe_code(1,"Blau");
    farbe[5]=farbe_code(8,"Grau");
}

void lsite_fuhlen_anzeigen()
{

    farbe_fuhlen(farbe);
    int i=0;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"Bitte wählen sie 2 oder mehrere gewünschten Farben aus Liste !"<<endl<<endl;
    cout<<" |Id | Inhalt |  Name |"<<endl;
    cout<<" ----------------------"<<endl;

 for (const farbe_code & omar : farbe){
     i++;
     cout<<" |"<<i<<"  |  ";
     SetConsoleTextAttribute(h,16*omar.code);
     cout<<"|__|";
     SetConsoleTextAttribute(h,15);
     cout<<"  |  "<<omar.farbe_Wert<<endl;
 }
     SetConsoleTextAttribute(h,15);
     cout<<" ----------------------";
     cout<<endl;
}

int  check_num()
{
    int f ;
    string line;
    while (getline(cin, line))
       {
           stringstream ss(line);
           if (ss >> f)
           {
               if (ss.eof())
               {
                   break;
               }
           }
           cout<<"Achtung !der Anzahl sollte zwischen 2 und 6 sein!"<<endl;
           cout<<"Bitte tippen Sie den Anzahl noch mal Hier  : ";
       }
    return f ;
}
int  check_num1()
{
    int f ;
    string line;
    while (getline(cin, line))
       {
           stringstream ss(line);
           if (ss >> f)
           {
               if (ss.eof())
               {
                   break;
               }
           }
           cout<<"Achtung !die ID sollte zwischen 1 und 6 sein!"<<endl;
           cout<<"Bitte eine Gültige ID eingeben : ";
       }
    return f ;
}

int main(){

//Partei p1;
//farbe_code f1;
//einwohner ein1;
//f1=farbe_code(1,"tak");
//p1=Partei(10,"omar",f1);
//ein1=einwohner(1,p1);
//cout<<ein1.get_gewahlte_partei_Farbe();
//sleep(30) ;

    // UT8-format console
     SetConsoleOutputCP( 65001 );
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     //liste der Farben an der console zeigen lassen
     lsite_fuhlen_anzeigen();
   bool x,check_zufallig=false;
   int num;
   int parteiAnzahl=0;
   string zufallig;
   srand ( time(NULL) );
   int wahl =0;
   int bewohner[400];
   int nachbarn[4];
   int zwei[2];
   //Frage nach der Anzahl der gewüschten Fragen
      cout<<"Bitte tippen Sie hier den Anzahl der gewünschten Farben : ";

        num=check_num();

        if (num>6||num<2){
            x=false;
        }else{
            x=true;
        }

          while(x==false){
            cout<<"Achtung !der Anzahl sollte zwischen 2 und 6 sein!"<<endl;
            cout<<"Bitte tippen Sie den Anzahl noch mal Hier : ";
            num=check_num();
               if (num<2 || num>6){
                   x=false;
                }else{
                   x=true;
                }
          }
     cout<<endl;
    // Frage nach Farbe
         int id_gewunschte_farbe[num];
         int num1;
         bool check_id=false;
         cout<<"Wählen Sie ("<<num<<") Farben nach ID aus?(\"Bitte geben sie "<<num<<" ID\")"<<endl;
         for (int i=0 ; i<num;i++)
         {
             cout<<"Bitte Farbe_id num ("<<i+1<<") eingeben: ";
             num1=check_num1();
             if (num1>6||num<1)
                {
                 check_id=false;
             }
             else
             {
                 check_id=true;
             }
             while(check_id==false){
             cout<< "Bitte eine Gültige ID eingeben : " ;
               num1=check_num1();
               if (num1>6||num<1)
                  {
                   check_id=false;
               }
               else
               {
                   check_id=true;
               }
             }
             id_gewunschte_farbe[i]=farbe[num1-1].get_farbe_code();
        }
    cout<<endl;





    // Frage nach der wünsch der verteil


         cout<<"wollen Sie die \""<<num<<"\" Parteien zufällig auf den Bewohnern verteilen ?  (\"JA\" Oder \"NEIN\")"<<endl;
         cin>>zufallig;
            if ((zufallig=="JA") || (zufallig=="NEIN")){
                check_zufallig=true;
             }
                while (check_zufallig==false){
                    cout<<"Bitte nur \"JA\" Oder \"NEIN\" eingeben"<<endl;
                    cin>>zufallig;
                      if (zufallig=="JA"||zufallig=="NEIN"||zufallig=="ja"||zufallig=="nein"){
                            check_zufallig=true;
                        }
                 }


            if (zufallig=="JA"){
            int zufall,zufall_id=0;

                   for (int i=0; i<=399; i++){
                       zufall =rand()% num;
                       zufall_id=id_gewunschte_farbe[zufall];
                       bewohner[i]=zufall_id;

                   }

            }

    int j=1;
    int d=0;
    while(j!=400 && d!=400){

     j=1;

         for (int i=0;i<=399;i++){
             if (i%20==0 || i==0){
               cout<<endl;

             }

                SetConsoleTextAttribute(h,16*bewohner[i]);
                  cout<<"|__";

         }
         SetConsoleTextAttribute(h,2);
         cout<<endl;
         Sleep(300);


     for(int c=0;c<=1999;c++)
     {
        wahl = rand()%400;



         nachbarn[0]= wahl-1;
         nachbarn[1] = wahl+1;
         nachbarn[2] = wahl+20;
         nachbarn[3] = wahl-20;

         if (wahl%19==0 && wahl!=0)
         {
              nachbarn[1]= wahl-19 ;
         }

         if (wahl%20==0)
         {
              nachbarn[0] = wahl+19;
         }
         if(nachbarn[3]<0)
         {
              nachbarn[3]= wahl+380;
         }
         if(nachbarn[2]>=400)
           {
             nachbarn[2]= wahl-380;
         }



         int gewahltenachbar= rand() % 4;

          zwei[0]= wahl;
          //cout<<endl<<"das ist der wahl"<<zwei[0]<<endl;
          zwei[1]= nachbarn[gewahltenachbar];
          //cout<<endl<<"das ist der wahl"<<zwei[1]<<endl;
         // Sleep(2000);
         int compar=rand()%2;
//test
         if (compar==0 )
         {  // cout<<"es war so "<<bewohner[wahl]<<" muss der wert enthalten "<<bewohner[zwei[1]]<<endl;
             bewohner[wahl]=bewohner[zwei[1]];
            // cout<<"es ist so geworden "<<bewohner[wahl]<<" muss der wert enthalten "<<bewohner[zwei[1]]<<endl;
         }
         else
         {
           // cout<<"es war so "<<bewohner[zwei[1]]<<" muss der wert enthalten "<<bewohner[wahl]<<endl;

             bewohner[zwei[1]]=bewohner[wahl];
           // cout<<"es ist so geworden "<<bewohner[zwei[1]]<<" muss der wert enthalten "<<bewohner[wahl]<<endl;
         }
//Sleep(1000);
     }
 system ("CLS");


//          sleep(10);


           while((j<=parteiAnzahl) &&(d<=399))
           {  d=0;
               for(int i=0;i<=399;i++){
                if (bewohner[i]==j)
                   {
                       d++;
                   }
               }


               j++;
           }



    }
  cout<<endl;
  cout<<"Demokratur!! "<<d;
  cout<<endl;



  //  }

}

