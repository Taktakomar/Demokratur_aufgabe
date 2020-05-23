#ifndef GAME_H
#define GAME_H

#include<windows.h>
#include <iostream>
#include <sstream>
#include<math.h>

#include <string.h>
#include <stdio.h>
#include <string>
#include <thread>
#include <chrono>
#include<unistd.h>

#include<farbe_code.h>
#include<farbe_prozent.h>
#include<einwohner.h>
#include<partei.h>



class Game
{
public:
    farbe_code farbe[6];
    int num ;
    int num1;
    string zufallig;

   Game();
   void farbe_fuhlen(farbe_code farbe[]);
   void lsite_fuhlen_anzeigen();
   void frage_nach_anzahl_farbe();
   void frage_nach_zufall_veteil();
   void frage_nach_gewunschte_id(int id_gewunschte_farbe[] ,int num);
   void tabelle_zeigen(HANDLE h , einwohner bewohner[]);
   void ja_action(int id_gewunschte_farbe[],einwohner bewohner[]);
   void nein_action(int id_gewunschte_farbe[],einwohner bewhoner[]);
   void ueberzeugung_action(einwohner bewhoner[]);
   int check_num();
   int check_num1();
   int check_num2();
   bool check_changed_corona_status(einwohner bewohner[],int index_random);
   bool check_gewunschte_id(int gewunschte_id[],int id, int size_id);
   string get_farbe_wert_durch_farbe_code(int code , farbe_code farbe[]);
};

#endif // GAME_H
