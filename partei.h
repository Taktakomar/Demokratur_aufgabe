#ifndef PARTEI_H
#define PARTEI_H
#include<farbe_code.h>

class Partei
{
public:
    int partei_id;
    string partei_name;
    farbe_code farbe;
    Partei();
    Partei(int P_id, string name,farbe_code farbe);
    string getFarbe(void);
    int get_code(void);
};

#endif // PARTEI_H
