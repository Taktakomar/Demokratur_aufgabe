#include "farbe_code.h"
#include <string>
using namespace std;
farbe_code::farbe_code()
{
    code=0;
    farbe_Wert="schwarz";
}
farbe_code::farbe_code(int x ,string y)
{
    code=x;
    farbe_Wert=y;
}
int farbe_code::get_farbe_code()
{
    return code;
}
string farbe_code::get_farbe_wert()
{
    return farbe_Wert;
}
void farbe_code::set_farbe_code_wert(int code,string farbe_Wert)
{
    this->code=code;
    this->farbe_Wert=farbe_Wert;
}


