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
string Partei::getFarbe()
{
    return  farbe.get_farbe_wert();
}
