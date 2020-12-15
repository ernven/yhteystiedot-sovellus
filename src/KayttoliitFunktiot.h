//  KayttoliitFunktiot.h
//  yhteystiedot_sovellus
//  Created by Ernesto on 13.12.2020.

#ifndef KayttoliitFunktiot_h
#define KayttoliitFunktiot_h

#include <iostream>
#include "Kontakti.h"

namespace KayttoliitFunktiot
{
    int saaLuvun();

    string saaSyoteKayttajalta(string pyydetty);

    Kontakti luoKontaktin();

    void paivitysKasittely(Kontakti &k);
}

#endif /* KayttoliitFunktiot_h */
