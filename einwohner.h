#ifndef EINWOHNER_H
#define EINWOHNER_H
#include <partei.h>

class einwohner
{
public:

    int einwohner_id;
    Partei gewahlte_partei;
    einwohner();
    einwohner(int id , Partei gewahlte_partei);
    void set_einwohner_id(int id);
    void set_gewahlte_partei(Partei gewahlte_partei);
    string get_gewahlte_partei_Farbe(void);
    int get_bewohner_code_farbe(void);
};

#endif // EINWOHNER_H
