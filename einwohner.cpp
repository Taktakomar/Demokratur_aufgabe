#include "einwohner.h"

einwohner::einwohner()
{
einwohner_id=1;
gewahlte_partei=Partei();
}
einwohner::einwohner(int id , Partei gewahlte_partei)
{
this->einwohner_id=id;
this->gewahlte_partei=gewahlte_partei;
}
void einwohner::set_einwohner_id(int id)
{
 this->einwohner_id=id;
}
void einwohner::set_gewahlte_partei(Partei gewahlte_partei)
{
    this->gewahlte_partei=gewahlte_partei;
}
string einwohner::get_gewahlte_partei_Farbe()
{
    return gewahlte_partei.getFarbe();
}
int einwohner::get_bewohner_code_farbe()
{
    return gewahlte_partei.get_code();
}
