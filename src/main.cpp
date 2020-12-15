//  main.cpp
//  yhteystiedot_sovellus
//  Created by Ernesto on 11.12.2020.

#include <iostream>
#include "Kontakti.h"
#include "TaulukonFunktiot.h"
#include "KayttoliitFunktiot.h"

// taulukon koko on vakio
#define T_KOKO 50

using namespace KayttoliitFunktiot;
using namespace TaulukonFunktiot;

int main(int argc, const char * argv[]) {
    
    string vaihtoehdot = "\nValitse sopiva vaihtoehto:\n1. Lataa tiedosto\n2. Luo uusi yhteyshenkilö\n3. Tulosta kaikki nimet"
        "\n4. Etsi yhteyshenkilö\n5. Päivitä yhteyshenkilö\n6. Poista yhteyshenkilö\n7. Tallenna tiedostoon\n0. Lopeta";
    int valinta = 99;
    
    // Taulukko, johon kontaktit on tallennettu
    Kontakti kirja[T_KOKO];
    
    // Tiedosto, johon tiedot on tallennettu
    string tiedostonNimi = "default.txt";
    
    cout << "Tervetuloa kontaktiluetteloon!" << endl;
    
    // Sovellus lopettaa kun valitaan 0
    while (valinta != 0) {
        cout << vaihtoehdot << endl;
        valinta = saaLuvun();
        
        switch (valinta) {
                
            case 1:     // Tiedoston lataaminen
            {
                cout << "\n Tiedoston lataaminen." <<
                    "\n\n Varoitus: Tiedoston lataaminen kirjoittaa olemassa olevien tietojen päälle. Haluatko jatkaa?" << endl;
                
                string tarkistaja = saaSyoteKayttajalta("valintasi (\"Joo\": jatkaa, muut syötteet: takaisin valikkoon)");
                
                if (tarkistaja == "Joo" || tarkistaja == "joo") {
                    
                    cout << endl;
                    string nimi = saaSyoteKayttajalta("tiedoston nimi (tyhjä avaa oletustiedoston: default.txt)");
                    
                    if (!nimi.empty()) {
                        tiedostonNimi = nimi;
                    }
                    
                    int tulos = lisaaTiedostosta(tiedostonNimi, kirja, T_KOKO);
                    if (tulos == -1) {
                        cout << "\n Virhe! Ei voinut avata tiedostoa tai sitä ei löytynyt." << endl;
                    } else {
                        cout << "\n Lataaminen onnistui! " << tulos << " kontaktia lisätty." << endl;
                    }
                }
                
                break;
            }
                
            case 2:      // Kontaktin lisääminen
            {
                cout << "\n Lisää uusi kontakti\n" << endl;
                Kontakti uusi = luoKontaktin();
                bool uniikki = true;
                
                // kaksoisnimet eivät ole sallittua. Tarkastaan nyt tämän.
                for (int i = 0; i < T_KOKO; i++) {
                    if (kirja[i].getNimi() == uusi.getNimi()) {
                        uniikki = false;
                    }
                }
                
                if (uniikki) {
                    
                    int tulos = lisaaTaulukkoon(uusi, kirja, T_KOKO);
                    
                    (tulos == -1) ? (cout << "\n Virhe: Luettelo on täynnä. Poista tietue ensin." << endl) : (cout << "\n Onnistui! Uusi koktakti luotu." << endl);
                    
                } else {
                    cout << "\n Nimi on jo käytetty." << endl;
                }
                
                break;
            }
                
            case 3:      // Tulosta kaikkien kontaktien nimet
            {
                cout << "\n Kontaktien nimet:" << endl;
                
                tulostaaKaikkiNimet(kirja, T_KOKO);
                
                break;
            }
                
            case 4:    // Kontaktin etsiminen
            {
                cout << "\n Kontaktin etsiminen\n" << endl;
                string annettu = saaSyoteKayttajalta("yhteyshenkilön nimi");

                int tulos = etsiTaulukosta(annettu, kirja, T_KOKO);

                if (tulos == -1) {
                  cout << "\n Ei löytynyt." << endl;
                } else {
                  kirja[tulos].tulosta();
                }
                
                break;
            }
                
            case 5:    // Kontaktin päivitys
            {
                cout << "\n Kontaktin päivitys\n" << endl;
                string annettu = saaSyoteKayttajalta("yhteyshenkilön nimi");

                int tulos = etsiTaulukosta(annettu, kirja, T_KOKO);

                if (tulos == -1) {
                  cout << "\n Ei löytynyt." << endl;
                } else {
                  cout << "\n Nämä ovat yhteyshenkilön tiedot:";
                  kirja[tulos].tulosta();
                  cout << endl;
                  paivitysKasittely(kirja[tulos]);        // Funktio päivittää alkuperäinen obj/kontakti
                  kirja[tulos].tulosta();
                  cout << "\n Onnistui! Kontakti päivitetty." << endl;
                }
                
                break;
            }
                
            case 6:    // Kontaktin poistaminen
            {
                cout << "\n Kontaktin poistaminen" << "\n\n Varoitus: Poistettua kontaktia ei voi palauttaa. " << endl;


                string annettu = saaSyoteKayttajalta("yhteyshenkilön nimi");

                int tulos = poistaTaulukosta(annettu, kirja, T_KOKO);
                if (tulos == 0) {
                   cout << "\n Onnistui! Kontakti on poistettu." << endl;
                } else {
                   cout << "\n Ei löytynyt." << endl;
                }
                
                break;
            }
                
            case 7:      // Tiedoston tallentaminen
            {
                cout << "\n Varoitus: Tallentaminen kirjoittaa olemassa olevan tiedoston päälle." << endl;
                
                string nimi = saaSyoteKayttajalta("tiedoston nimi (tyhjä syöte tarkoittaa aiemmin ladattua tai default.txt)");
                
                if (!nimi.empty()) {
                    tiedostonNimi = nimi;
                }
                
                int tulos = tallentaaTiedostoon(tiedostonNimi, kirja, T_KOKO);
                if (tulos == 0) {
                    cout << "\n Onnistui!" << endl;
                } else {
                    cout << "\n Virhe!" << endl;
                }
                
                break;
            }
        }
    }
    
    cout << "\nKiitos sovelluksen käyttämisesta.\n" << endl;
    
    return 0;
}
