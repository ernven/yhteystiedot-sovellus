//  Kontakti.h
//  yhteystiedot_sovellus

#ifndef KONTAKTI_H
#define KONTAKTI_H

using namespace std;

class Kontakti
{
private:
    string nimi, puhNo, osoite, sPosti;

public:
    Kontakti();
    Kontakti(string nimi, string puhNo, string osoite, string sPosti);
    
    
    void setNimi(string nimi);
    void setPuhelinNumero(string puhNo);
    void setOsoite(string osoite);
    void setSahkoposti(string sPosti);
    
    string getNimi();
    string getPuhelinNumero();
    string getOsoite();
    string getSahkoposti();
    
    void tulosta();
};

#endif // KONTAKTI_H
