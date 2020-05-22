#include "farbe_prozent.h"

farbe_prozent::farbe_prozent()
{
    this->farbe_code=0;
    this->prozent=0;
}
farbe_prozent::farbe_prozent(int farbe_code,int prozent)
{
    this->farbe_code=farbe_code;
    this->prozent=prozent;
}
int farbe_prozent::get_farbe_prozent()
{
    return this->prozent;
}
