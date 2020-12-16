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

    int etsiTaulukosta(std::string nimi, Kontakti array[], int koko);

    int poistaTaulukosta(std::string nimi, Kontakti array[], int koko);

    void tulostaaKaikkiNimet(Kontakti array[], int koko);

    int lisaaTiedostosta(std::string tNimi, Kontakti array[]);

    int tallentaaTiedostoon(std::string tNimi, Kontakti array[], int koko);
}

#endif /* TaulukonFunktiot_h */
