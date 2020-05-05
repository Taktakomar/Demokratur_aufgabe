#include <iostream>
#include<windows.h>
#include <string.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <chrono>
#include<unistd.h>
using namespace std;
int main(){
    srand ( time(NULL) );
    int wahl =0;
    int partei=0;
    int bewohner[400];
    int nachbarn[4];
    int zwei[2];
   HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int parteiAnzahl=0;
    cout << "Bitte Anzahl der Partei eingeben!!";
    cin >>parteiAnzahl;
   // cout << parteiAnzahl;
    //bewohner[i]="  ";
    for (int i=0; i<=399; i++){

        partei = rand ()% parteiAnzahl+1;
        bewohner[i]=partei;

    }



    int j=1;
    int d=0;
    while(j!=400 && d!=400){

     j=1;

         for (int i=0;i<=399;i++){
             if (i%20==0 || i==0){
               cout<<endl;

             }

                SetConsoleTextAttribute(h,100*bewohner[i]);
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

