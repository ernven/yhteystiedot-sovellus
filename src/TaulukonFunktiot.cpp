//  TaulukonFunktiot.cpp
//  yhteystiedot_sovellus
//  Created by Ernesto on 13.12.2020.

#include "TaulukonFunktiot.h"

// Nämä funktiot ovat taulukon käsittelylle

// Funktio lisää kontaktin taulukkoon.
// Se palautta kontaktin indeksin, jos onnistui, tai -1 jos taulukko on täynnä.
int TaulukonFunktiot::lisaaTaulukkoon(Kontakti kontakti, Kontakti array[], int koko) {
    for (int i = 0; i < koko; i++) {
        if (array[i].getNimi().empty()) {
            array[i] = kontakti;
            return i;
        }
    }
    return -1;
}

// Funktio etsii saman nimisen kontaktin taulukosta.
// Se palauttaa kontaktin indeksin, jos on taulukossa, tai -1 jos ei ole löytynyt.
int TaulukonFunktiot::etsiTaulukosta(std::string nimi, Kontakti array[], int koko)
{
    for (int i = 0; i < koko; i++) {
        if (array[i].getNimi() == nimi) {
            return i;
        }
    }
    return -1;
}

// Funktio poistaa saman nimisen kontaktin taulukosta.
// Se palauttaa 1 jos kontakti on poistettu, tai 0 jos ei ole löytynyt taulukosta.
int TaulukonFunktiot::poistaTaulukosta(std::string nimi, Kontakti array[], int koko)
{
    for (int i = 0; i < koko; i++) {
        if (array[i].getNimi() == nimi) {
            array[i] = {"", "", "", ""};
            return 0;
        }
    }
    return -1;
}

// Funktio tulostaa kaikki kontaktien nimet taulukossa.
void TaulukonFunktiot::tulostaaKaikkiNimet(Kontakti array[], int koko)
{
    for (int i = 0; i < koko; i++) {
        if (!array[i].getNimi().empty()) {
            std::cout << array[i].getNimi() << std::endl;
        }
    }
}

// Funktio lisää kontakteja tiedostosta, jonka nimi on annettu tai default.txt.
// Se palauta kuinka monta kontaktia on lisätty (0 jos tiedosto oli tyhjä) tai -1 jos tuli virhe.
int TaulukonFunktiot::lisaaTiedostosta(std::string tNimi, Kontakti array[])
{
    std::ifstream tiedosto;
    tiedosto.open(tNimi);
    if (tiedosto.is_open()) {
        std::string rivi;
        std::string params[4];
        int i = 0;
        int j = 0;
        while (getline(tiedosto, rivi)) {
            params[i] = rivi;
            i++;
            if (i == 4) {
                array[j] = {params[0], params[1], params[2], params[3]};
                i = 0;
                j++;
            }
        }
        tiedosto.close();
        return j;
    } else {
        return -1;
    }
}

// Funktio tallentaa kontakteja tiedostoon, jonka nimi on annettu tai default.txt.
// Se palauta 0 jos onnistui tai -1 jos tuli virhe.
int TaulukonFunktiot::tallentaaTiedostoon(std::string tNimi, Kontakti array[], int koko)
{
    std::ofstream tiedosto;
    tiedosto.open(tNimi);
    if (tiedosto.is_open()) {
        for (int i = 0; i < koko; i++) {
            if (!array[i].getNimi().empty()) {
                tiedosto << array[i].getNimi() << std::endl;
                tiedosto << array[i].getPuhelinNumero() << std::endl;
                tiedosto << array[i].getOsoite() << std::endl;
                tiedosto << array[i].getSahkoposti() << std::endl;
            }
        }
        tiedosto.close();
        return 0;
    } else {
        return -1;
    }
}
