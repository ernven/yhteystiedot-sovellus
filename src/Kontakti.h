//  Kontakti.h
//  yhteystiedot_sovellus

#ifndef KONTAKTI_H
#define KONTAKTI_H

#include <string>

class Kontakti
{
private:
    std::string nimi, puhNo, osoite, sPosti;

public:
    Kontakti();
    Kontakti(std::string nimi, std::string puhNo, std::string osoite, std::string sPosti);
    
    
    void setNimi(std::string nimi);
    void setPuhelinNumero(std::string puhNo);
    void setOsoite(std::string osoite);
    void setSahkoposti(std::string sPosti);
    
    std::string getNimi();
    std::string getPuhelinNumero();
    std::string getOsoite();
    std::string getSahkoposti();
    
    void tulosta();
};

#endif // KONTAKTI_H
