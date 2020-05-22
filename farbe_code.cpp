#include "farbe_code.h"
#include <string>
using namespace std;
farbe_code::farbe_code()
{
    this->code=0;
    this->farbe_Wert="schwarz";
}
farbe_code::farbe_code(int x ,string y)
{
    this->code=x;
    this->farbe_Wert=y;
}
int farbe_code::get_farbe_code()
{
    return this->code;
}
string farbe_code::get_farbe_wert()
{
    return this->farbe_Wert;
}
void farbe_code::set_farbe_code_wert(int code,string farbe_Wert)
{
    this->code=code;
    this->farbe_Wert=farbe_Wert;
}


