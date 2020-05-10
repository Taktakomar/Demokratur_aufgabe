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
    string get_gewahlte_partei_Farbe(void);
};

#endif // EINWOHNER_H
