#ifndef EINWOHNER_H
#define EINWOHNER_H
#include <partei.h>

class einwohner
{
private:
    int Corona_Status;
    int einwohner_id;
    Partei gewahlte_partei;


public:


    einwohner();
    einwohner(int id , Partei gewahlte_partei,int Corona_Status);
    void set_einwohner_id(int id);
    void set_gewahlte_partei(Partei gewahlte_partei);
    void set_corona_status(int Corona_Status);
    int get_einwohner_id();
    int get_bewohner_code_farbe(void);
    int get_corona_status();
    Partei get_gewahlte_partei(void);

};

#endif // EINWOHNER_H
