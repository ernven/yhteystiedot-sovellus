//  TaulukonFunktiot.h
//  yhteystiedot_sovellus
//  Created by Ernesto on 13.12.2020.

#ifndef TaulukonFunktiot_h
#define TaulukonFunktiot_h

#include <iostream>
#include <fstream>     // Antaa funktiot tiedostojen toiminnoille
#include "Kontakti.h"

namespace TaulukonFunktiot
{
    int lisaaTaulukkoon(Kontakti kontakti, Kontakti array[], int koko);

    int etsiTaulukosta(string nimi, Kontakti array[], int koko);

    int poistaTaulukosta(string nimi, Kontakti array[], int koko);

    void tulostaaKaikkiNimet(Kontakti array[], int koko);

    int lisaaTiedostosta(string tNimi, Kontakti array[], int koko);

    int tallentaaTiedostoon(string tNimi, Kontakti array[], int koko);
}

#endif /* TaulukonFunktiot_h */
