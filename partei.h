#ifndef PARTEI_H
#define PARTEI_H
#include<farbe_code.h>

class Partei
{
private:
    int partei_id;
    string partei_name;
    farbe_code farbe;

public:

    Partei();
    Partei(int P_id, string name,farbe_code farbe);
    void set_partei_id(int partei_id);
    void set_partei_name(string partei_name);
    void set_partei_farbe(farbe_code farbe);
    string getFarbe(void);
    string get_partei_name(void);
    int get_code(void);
};

#endif // PARTEI_H
