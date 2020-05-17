#ifndef FARBE_PROZENT_H
#define FARBE_PROZENT_H


class farbe_prozent
{
public:
    int farbe_code;
    int prozent;
    farbe_prozent();
    farbe_prozent(int farbe_code,int prozent);
    int get_farbe_prozent();
};

#endif // FARBE_PROZENT_H
