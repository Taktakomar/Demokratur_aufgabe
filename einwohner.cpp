#include "einwohner.h"

einwohner::einwohner()
{
einwohner_id=1;
gewahlte_partei=Partei();
}
einwohner::einwohner(int id , Partei gewahlte_partei)
{
einwohner_id=id;
this->gewahlte_partei=gewahlte_partei;
}
string einwohner::get_gewahlte_partei_Farbe()
{
    return gewahlte_partei.getFarbe();
}