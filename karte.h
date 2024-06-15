#ifndef KARTE_H
#define KARTE_H

#include <string>

using namespace std;

class Karte
{
private:
    int wert;
    string farbe;

public:
    Karte(int wert, string farbe);
    Karte();
    void setWert(int wert);
    int getWert();
    void setFarbe(string farbe);
    string getFarbe();
    void showKarte();
};


#endif // KARTE_H
