#include "karte.h"
#include <iostream>

Karte::Karte()
{
    farbe = "";
    wert = 0;
}

Karte::Karte(int wert, string farbe)
{
    this->wert = wert;
    this->farbe = farbe;
}

string Karte::getFarbe()
{
    return farbe;
}

void Karte::setFarbe(string farbe)
{
    this->farbe = farbe;
}

int Karte::getWert()
{
    return wert;
}

void Karte::setWert(int wert)
{
    this->wert = wert;
}

void Karte::showKarte()
{
   cout << wert << farbe << endl;
}
