#ifndef KARTENSTAPEL_H
#define KARTENSTAPEL_H

#include "Karte.h"
#include <stack>
#include <vector>


using namespace std;

class KartenStapel : public Karte
{
private:
    stack<Karte*> stapel;
    vector<Karte*> deck;
    Karte neueKarte;
    Karte gezogeneKarte;
public:
    KartenStapel();
    Karte zieheKarte();
    void erstelleStapel();
    void mischeStapel();
};


#endif // KARTENSTAPEL_H
