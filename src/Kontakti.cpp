//  Kontakti.cpp
//  yhteystiedot_sovellus

#include <iostream>
#include "Kontakti.h"

// Perusrakentaja
Kontakti::Kontakti() {}

// Rakentaja parametreilla
Kontakti::Kontakti(string nimi, string puhNo, string osoite, string sPosti)
{
    this->nimi = nimi;
    this->puhNo = puhNo;
    this->osoite = osoite;
    this->sPosti = sPosti;
}


// Setter funktiot
void Kontakti::setNimi(string nimi)
{
    this->nimi = nimi;
}

void Kontakti::setPuhelinNumero(string puhNo)
{
    this->puhNo = puhNo;
}

void Kontakti::setOsoite(string osoite)
{
    this->osoite = osoite;
}

void Kontakti::setSahkoposti(string sPosti) {
    this->sPosti = sPosti;
}

// Getter funktiot
string Kontakti::getNimi()
{
    return nimi;
}
string Kontakti::getPuhelinNumero()
{
    return puhNo;
}
string Kontakti::getOsoite()
{
    return osoite;
}
string Kontakti::getSahkoposti()
{
    return sPosti;
}


// Tulostaja funktio
void Kontakti::tulosta() {
    cout << "\nNimi: " << nimi << "\nPuhelinnumero: " << puhNo << "\nOsoite: "<< osoite
        << "\nSähköposti: " << sPosti << endl;
}
