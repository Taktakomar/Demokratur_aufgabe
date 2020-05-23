#include <game.h>

int main(){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    einwohner bewohner[400];
    Game g;
    SetConsoleOutputCP( 65001 ); // UT8-format console
    srand ( time(NULL) );

    g.lsite_fuhlen_anzeigen();
    g.frage_nach_anzahl_farbe();
    int id_gewunschte_farbe[g.num];
    g.frage_nach_gewunschte_id(id_gewunschte_farbe,g.num);
    g.frage_nach_zufall_veteil();

    if (g.zufallig=="JA"||g.zufallig=="ja"){
        g.ja_action(id_gewunschte_farbe,bewohner);
    }

    if (g.zufallig=="NEIN"||g.zufallig=="nein"){
        g.nein_action(id_gewunschte_farbe,bewohner);
    }

    g.ueberzeugung_action(bewohner);
    g.tabelle_zeigen(h,bewohner);
    SetConsoleTextAttribute(h,15);
}

