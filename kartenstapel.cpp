#include "kartenstapel.h"
#include <iostream>
#include <random>
#include <algorithm>

KartenStapel::KartenStapel()
{
    erstelleStapel();
}

void KartenStapel::erstelleStapel()
{
    enum{
        kreuz,
        pik,
        karo,
        herz
    };
    string farbeText;
    for(int farbe = 0; farbe<4; farbe++){
        for(int wert = 1; wert<=10; wert++){
            switch (farbe){
            case kreuz:
                farbeText = "Kreuz";
                break;
            case pik:
                farbeText = "Pik";
                break;
            case karo:
                farbeText = "Karo";
                break;
            case herz:
                farbeText = "Herz";
                break;
            default: cout << "keine Gültige Farbe" << endl;
            }
            Karte* karte = new Karte(wert, farbeText);
            deck.push_back(karte);
        }
    }
    mischeStapel();
}

void KartenStapel::mischeStapel()
{
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deck.begin(), deck.end(), g);
    for (auto karte : deck)
    {
        stapel.push(karte);
    }
}

Karte KartenStapel::zieheKarte()
{
    if(stapel.empty())
    {
        erstelleStapel();
    }
    gezogeneKarte = *stapel.top();
    stapel.pop();
    return gezogeneKarte;
}
