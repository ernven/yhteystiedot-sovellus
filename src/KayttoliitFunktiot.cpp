//  KayttoliitFunktiot.cpp
//  yhteystiedot_sovellus
//  Created by Ernesto on 13.12.2020.

#include "KayttoliitFunktiot.h"

// Funktiot Käyttöliittymälle

// Funktio saa käyttäjältä syötteet, joiden täytyy olla lukuja. Virheet ovat siepattu.
// Palauta syötetty luku tai -1 jos tuli virhe.
int KayttoliitFunktiot::saaLuvun()
{
    try {
        return stoi(saaSyoteKayttajalta("luku"));
    } catch (invalid_argument) {
        cout << "Virhe: Syötteen täytyy olla luku 1-6:n väliltä." << endl;
        return -1;
    }
    
    /*
    if (cin.fail()) {
        cout << "Virhe: Syötteen täytyy olla luku 1-6:n väliltä." << endl;
        // Virheilmoituksen poisto ja bufferin tyhjennys
        cin.clear();
        cin.ignore(10000,'\n');
        return -1;
    }*/
    
    //return luku;
}

// Funktio saa syötteen käyttäjältä (cin-funktion kautta) ja palauttaa sen.
string KayttoliitFunktiot::saaSyoteKayttajalta(string pyydetty)
{
    cout << " Anna " << pyydetty << ": ";
    
    string annettu;
    getline(cin, annettu);
    
    return annettu;
}

// Funktio saa parametrit käyttäjältä, luo kontakti-olion ja palauttaa sen.
Kontakti KayttoliitFunktiot::luoKontaktin()
{
    string nimi, puhNo, osoite, sPosti;

    while (nimi.empty()) {
        nimi = saaSyoteKayttajalta("yhteyshenkilön nimi");
    }
    puhNo = saaSyoteKayttajalta("yhteyshenkilön puhelinnumero");
    osoite = saaSyoteKayttajalta("yhteyshenkilön osoite");
    sPosti = saaSyoteKayttajalta("yhteyshenkilön sähköposti");
    
    return {nimi, puhNo, osoite, sPosti};
}

// Funktio ottaa viittauksen parametrilla ja päivittää kontaktin taulukossa (se saa muuttujan muistiosoitteen arvon)
void KayttoliitFunktiot::paivitysKasittely(Kontakti &k)
{
    string puhNo, osoite, sPosti;
    
    puhNo = saaSyoteKayttajalta("yhteyshenkilön puhelinnumero");
    k.setPuhelinNumero(puhNo);
    
    osoite = saaSyoteKayttajalta("yhteyshenkilön osoite");
    k.setOsoite(osoite);
    
    sPosti = saaSyoteKayttajalta("yhteyshenkilön sähköposti");
    k.setSahkoposti(sPosti);
}
