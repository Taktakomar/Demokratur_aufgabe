#ifndef FARBE_CODE_H
#define FARBE_CODE_H
#include <string>
using namespace std;

class farbe_code
{
public:
    int code;
    string  farbe_Wert;
            farbe_code();
            farbe_code(int x , string y);
    int     get_farbe_code();
    string  get_farbe_wert();
    void    set_farbe_code_wert(int code,string farbe_wert);

};


#endif // FARBE_CODE_H
