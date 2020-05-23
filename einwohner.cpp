#include "einwohner.h"

einwohner::einwohner()
{
    this->einwohner_id=1;
    this->gewahlte_partei=Partei();
    this->Corona_Status=0;
}

einwohner::einwohner(int id , Partei gewahlte_partei,int Corona_Status)
{
    this->einwohner_id=id;
    this->gewahlte_partei=gewahlte_partei;
    this->Corona_Status=Corona_Status;
}

void einwohner::set_corona_status(int Corona_Status)
{
    this->Corona_Status=Corona_Status;
}

int einwohner::get_corona_status()
{
    return this->Corona_Status;
}

void einwohner::set_einwohner_id(int id)
{
     this->einwohner_id=id;
}

void einwohner::set_gewahlte_partei(Partei gewahlte_partei)
{
    this->gewahlte_partei=gewahlte_partei;
}

Partei einwohner::get_gewahlte_partei()
{
    return this->gewahlte_partei;
}

int einwohner::get_bewohner_code_farbe()
{
    return this->gewahlte_partei.get_code();
}

int einwohner::get_einwohner_id()
{
    return this->einwohner_id;
}
