#include <iostream>
#include<windows.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <chrono>
#include <sstream>
#include<unistd.h>
#include<farbe_code.h>
#include<partei.h>
#include<einwohner.h>
#include<farbe_prozent.h>
#include <cmath>



    using namespace std;
    int c ;
    farbe_code farbe[6];

void farbe_fuhlen(farbe_code farbe[]){

    farbe[0]=farbe_code(15,"weiß   ");
    farbe[1]=farbe_code(2,"Grün   ");
    farbe[2]=farbe_code(4,"Rot    ");
    farbe[3]=farbe_code(6,"Orange ");
    farbe[4]=farbe_code(1,"Blau   ");
    farbe[5]=farbe_code(8,"Grau   ");

}

void lsite_fuhlen_anzeigen(){

    farbe_fuhlen(farbe);
    int i=0;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
        cout<<"Bitte wählen sie 2 oder mehrere gewünschten Farben aus Liste !"<<endl<<endl;
        cout<<" |Id | Inhalt |  Name |"<<endl;
        cout<<" ----------------------"<<endl;
        for (const farbe_code  &omar : farbe){
             i++;
             cout<<" |"<<i<<"  |  ";
             SetConsoleTextAttribute(h,16*omar.code);
                 cout<<"    ";
             SetConsoleTextAttribute(h,0);
                 cout<<"  ";
             SetConsoleTextAttribute(h,15);
                 cout<<"|";
             SetConsoleTextAttribute(h,15);
                 cout<<omar.farbe_Wert;
                 cout<<"|";
             SetConsoleTextAttribute(h,0);
                 cout<<endl;
             SetConsoleTextAttribute(h,15);
         }

        SetConsoleTextAttribute(h,15);
     cout<<endl;

}

int  check_num(){
    int f ;
    string line;
        while (getline(cin, line)){
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
    while (getline(cin, line)){
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
int  check_num2()
{
    int f ;
    string line;
    while (getline(cin, line)){
           stringstream ss(line);
           if (ss >> f)
           {
               if (ss.eof())
               {
                   break;
               }
           }
           cout<<"Achtung ! prozent soll eine nummer sein"<<endl;
           cout<<"Bitte eine Gültiges Prozent eingeben : ";
       }
    return f ;
}
void tabelle_zeigen(HANDLE h , einwohner bewohner[])
{ int d=0;
    cout<<endl;
    for (int i=0;i<=399;i++){
        if (i%20==0 && i!=0){
           SetConsoleTextAttribute(h,0);
           cout<<"|";
          cout<<endl;

        }

           SetConsoleTextAttribute(h,16*bewohner[i].get_bewohner_code_farbe());
           if (bewohner[i].get_corona_status()==1)
           {
               d++;
             cout<<"|*_*";
           }
           else
           {
             cout<<"|___";
           }

    }

    SetConsoleTextAttribute(h,0);
    cout<<"|";
     cout<<endl;
     SetConsoleTextAttribute(h,15);
     cout<<"Anzahl der Bewohner der Aktuell Corona haben :"<<d;
     SetConsoleTextAttribute(h,0);
     cout<<endl;
}

string get_farbe_wert_durch_farbe_code(int code , farbe_code farbe[])
{
    string wert="";
 for(int i=0;i<6;i++)
 {
   if (code==farbe[i].get_farbe_code())
   {
       wert=farbe[i].get_farbe_wert();
       break;
   }
 }
 return  wert;
}

int main(){



    int j,d=0;
    bool x,check_zufallig=false;
    int num;
    string zufallig;
    int wahl =0;
    int nachbarn[4];
    int zwei[2];
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    einwohner bewohner[400];
    SetConsoleOutputCP( 65001 ); // UT8-format console
    srand ( time(NULL) );

        lsite_fuhlen_anzeigen();
            cout<<"Bitte tippen Sie hier  den Anzahl der gewünschten Farben : ";
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

      int id_gewunschte_farbe[num];
      int num1;
      bool check_id=false;

            cout<<"Wählen Sie ("<<num<<") Farben nach ID aus?(\"Bitte geben sie "<<num<<" ID\")"<<endl;
                for (int i=0 ; i<num;i++){
                    cout<<"Bitte Farbe_id num ("<<i+1<<") eingeben: ";
                        num1=check_num1();
                            if (num1>6||num<1){
                                check_id=false;
                             }else{
                                check_id=true;
                             }
                                while(check_id==false){
                                    cout<< "Bitte eine Gültige ID eingeben : " ;
                                        num1=check_num1();
                                            if (num1>6||num<1){
                                                check_id=false;
                                             }else{
                                                check_id=true;
                                             }
                                        }
                               id_gewunschte_farbe[i]=farbe[num1-1].get_farbe_code();
                }

          cout<<endl;
          cout<<"wollen Sie die \""<<num<<"\" Parteien zufällig auf den Bewohnern verteilen ?  (\"JA\" Oder \"NEIN\")"<<endl;
            cin>>zufallig;
                if ((zufallig=="JA"||zufallig=="ja") || (zufallig=="NEIN"||zufallig=="nein")){
                    check_zufallig=true;
                  }
                    while (check_zufallig==false){
                        cout<<"Bitte nur \"JA\" Oder \"NEIN\" eingeben"<<endl;
                            cin>>zufallig;
                                if (zufallig=="JA"||zufallig=="NEIN"||zufallig=="ja"||zufallig=="nein"){
                                    check_zufallig=true;
                                }
                     }


                if (zufallig=="JA"||zufallig=="ja"){
                        int zufall,zufall_id=0;
                        string wert="";
                        int corona_zahl=0;
                        int corona_haber;

                        cout<<"wie viel Bewohner sollen Corona haben ?";
                        cin>>corona_zahl;
                            for(int i=0; i<=399; i++){
                                zufall =rand()% num;
                                    zufall_id=id_gewunschte_farbe[zufall];

                                        for (int j=0;j<6;j++){
                                            if (farbe[j].get_farbe_code()==zufall_id){
                                                wert = farbe[j].get_farbe_wert();
                                                    break;
                                             }
                                       }

                                        farbe_code f2(zufall_id,wert);
                                            Partei p2(i,"1",f2);
                                            bewohner[i]=einwohner(i,p2,0);
                                  }

                            for(int i=0;i<corona_zahl;i++)
                            {


                                corona_haber= rand()%400;

                                 bewohner[corona_haber].set_corona_status(1);
                            }


                            cout<< "die Parteien sind Auf die Bewohner so verteilt : "<<endl;
                            tabelle_zeigen(h,bewohner);

                    }

                if (zufallig=="NEIN"||zufallig=="nein")
                {
                    cout<<"noch nicht programiert!"<<endl;
                    cout<<"versuch nochmal und wähl 'ja' bei zufällig"<<endl;
                    //cout<<"wie wollen Sie die Parteien auf die Bewohner verteilt ?"<<endl;
                    int f=0;
                    int summe=100;
                    farbe_prozent Prozent_tabelle[num];
                    bool check_prozent=false;

while(f<num-1){

string wert=get_farbe_wert_durch_farbe_code(id_gewunschte_farbe[f],farbe) ;

cout<<"wie viele Prozent der Bewhonern sollte  die Partei name'"<<wert<<"'haben?(Prozent zwischen 0 und "<< summe<<"eingeben)"<<endl;
Prozent_tabelle[f].prozent=check_num2();
if (Prozent_tabelle[f].prozent>summe||Prozent_tabelle[f].prozent<0)
{
    check_prozent=false;
}
else
{
    check_prozent=true;
    summe=summe-Prozent_tabelle[f].prozent;
    Prozent_tabelle[f].farbe_code=id_gewunschte_farbe[f];
    f++;
}
while(check_prozent==false)
{
    cout<<"bitte gültiges Prozent nochmal:";
   Prozent_tabelle[f].prozent=check_num2();
   if (Prozent_tabelle[f].prozent>summe||Prozent_tabelle[f].prozent<0)
   {
       check_prozent=false;
   }
   else
   {
       check_prozent=true;
       summe=summe-Prozent_tabelle[f].prozent;
       Prozent_tabelle[f].farbe_code=id_gewunschte_farbe[f];
       f++;
   }
}

}

Prozent_tabelle[f].prozent=summe;
Prozent_tabelle[f].farbe_code=id_gewunschte_farbe[f];
int anfang=0;

for(const farbe_prozent & omar : Prozent_tabelle)
{
    if (omar.prozent>0)
    {

    int bewohnerzahl=round(399*omar.prozent/100);
    for(int i=anfang; i<bewohnerzahl+anfang+1; i++){
    string wert=get_farbe_wert_durch_farbe_code(omar.farbe_code,farbe);
    if (i==400)
    {break;}

                           farbe_code f2(omar.farbe_code,wert);
                           Partei p2(i,"",f2);
                           bewohner[i]=einwohner(i,p2,0);

                       }
    anfang=anfang+bewohnerzahl+1;
}
}
cout<< "die Parteien sind Auf die Bewohner so verteilt : "<<endl;
tabelle_zeigen(h,bewohner);
 }


    GetConsoleScreenBufferInfo(h, &SBInfo);
    SHORT a=SBInfo.dwCursorPosition.X;
    SHORT b=SBInfo.dwCursorPosition.Y;
    if(bewohner[0].get_gewahlte_partei().get_code()!=0)
    {

    while(d!=400){
        j=0;
        SetConsoleTextAttribute(h,15);
        cout<<"Parteien werden zufällig überzeugen bitte warten Sie....";
         SetConsoleTextAttribute(h,0);
         cout<<endl;
            tabelle_zeigen(h,bewohner);
                SetConsoleTextAttribute(h,0);
                   cout<<endl;
                        SetConsoleCursorPosition(h, {a,b});
                            Sleep(500);


                                    for(int c=0;c<=5000;c++){
                                         wahl = rand()%400;
                                         nachbarn[0]= wahl-1;
                                         nachbarn[1] = wahl+1;
                                         nachbarn[2] = wahl+20;
                                         nachbarn[3] = wahl-20;
                                            if(wahl%19==0 && wahl!=0){
                                                nachbarn[1]= wahl-19 ;
                                            }
                                              if (wahl%20==0){

                                              nachbarn[0] = wahl+19;
                                            }
                                            if(nachbarn[3]<0){

                                              nachbarn[3]= wahl+380;
                                            }
                                            if(nachbarn[2]>=400){

                                              nachbarn[2]= wahl-380;
                                            }
     int gewahltenachbar= rand() % 4;
          zwei[0]= wahl;
          zwei[1]= nachbarn[gewahltenachbar];

         int compar=rand()%2;
         if (compar==0 )
         {
             bewohner[wahl].set_gewahlte_partei(bewohner[zwei[1]].get_gewahlte_partei());
            if (bewohner[zwei[1]].get_corona_status()==1)
            {
                 bewohner[wahl].set_corona_status(bewohner[zwei[1]].get_corona_status());
            }

         }
         else
         {

             bewohner[zwei[1]].set_gewahlte_partei(bewohner[wahl].get_gewahlte_partei());
             if (bewohner[wahl].get_corona_status()==1)
             {
                   bewohner[zwei[1]].set_corona_status(bewohner[wahl].get_corona_status());
             }
         }
     }


           while((j<6) &&(d<=399))
           {  d=0;
               for(int i=0;i<=399;i++){

                if (bewohner[i].get_bewohner_code_farbe()==farbe[j].get_farbe_code())
                   {
                       d++;

                   }
               }

               j++;
           }
           SetConsoleCursorPosition(h, {a,b});

}
  cout<<endl;

   SetConsoleTextAttribute(h,15);
   cout<<"Alle bewohner haben jetzt zufällig '"<<bewohner[0].get_gewahlte_partei().getFarbe()<<"' als gewählte Partei!";
   SetConsoleTextAttribute(h,0);
  cout<<endl;
  tabelle_zeigen(h,bewohner);

  SetConsoleTextAttribute(h,15);


    }

}

