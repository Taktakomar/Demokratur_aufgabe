#include "partei.h"

Partei::Partei()
{
partei_id=1;
partei_name="Grün";
this->farbe.code=5;
this->farbe.farbe_Wert="ss";

}
Partei::Partei(int F_id , string name , farbe_code farbe)
{
partei_id=F_id;
partei_name=name;
this->farbe.code=farbe.code;
this->farbe.farbe_Wert=farbe.farbe_Wert;
}
void Partei::set_partei_id(int partei_id)
{
    this->partei_id=partei_id;
}
void Partei::set_partei_name(string partei_name)
{
    this->partei_name=partei_name;
}
void Partei::set_partei_farbe(farbe_code farbe)
{
    this->farbe=farbe;
}
string Partei::getFarbe()
{
    return  farbe.get_farbe_wert();
}
int Partei::get_code()
{
    return  farbe.get_farbe_code();
}
