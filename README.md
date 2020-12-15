# Yhteystiedot Sovellus
  
Sovellus tallettaa kontakteja (maks. 50), joissa on nimi, puhelinnumero, osoite ja sähköposti. Kaikki ovat teksti-tyyppejä (string), eli ne voivat olla mitä tahansa muotoa.
Tiedot on talletettu muistiin, mutta ne voivat olla tallennettu ulkoiseen tiedostoon (josta ne voidaan ladata).

## Käyttöohjeet

Sovellus toimii komentorivi-käyttöliittymän kautta. Kun sovellus käynnistetään, käyttäjälle näytetään valinta-kokoelma. Vaihtoehdot ovat numerot 0-7, ja muut syötteet eivät ole sallittuja.
Jos operaatio ei onnistunut tai mitään ei löytynyt, info-viesti ilmestyy.

### Vaihtoehdot ovat seuraavat:

`0` Lopettaa sovelluksen

Varo! Tämä vaihtoehto ei tallenna mitään levyyn.

`1` Lataa tiedoston

Lataa tiedot teksti-tiedostosta. Tiedoston täytyy olla samassa kansiossa kuin sovellus.
Varo! Vanhat tiedot on kirjoitettu päälle.
Käyttäjä voi ladata oletus- (default.txt) tai toisen tiedoston. Jos tiedostoa ei ole olemassa, mitään ei ole ladattu, ja näytetään viesti, joka kertoo tämän.


`2` Luo uuden yhteyshenkilön

Käyttäjä antaa tiedot, josta uusi kontakti luodaan. Kontakti talletetaan muistiin.

Nimi ei saa olla tyhjä ja sen tulee olla uniikki. Muut kentät saa olla tyhjiä, jos kyseistä tietoa ei ole.


`3` Tulostaa kaikki nimet

Tulostaa listan, jossa on kaikki kontaktien nimet. Se auttaa tarkistamaan, mitä tietoja on talletettu sovellukseen.


`4` Etsii yhteyshenkilön

Käyttäjä antaa nimen. Sitten, systeemi etsii vastaavan kontaktin ja näyttää kaikki tiedot.


`5` Päivittää yhteyshenkilön

Käyttäjä antaa nimen. Sitten, systeemi etsii vastaavan kontaktin ja kysyy käyttäjältä uudet tiedot päivitykseen (nimi ei voi muuttua).


`6` Poistaa yhteyshenkilön

Käyttäjä antaa nimen. Sitten, systeemi etsii vastaavan kontaktin ja, jos se löytyy, poistaa sen.
Varo! Poistettua kontaktia ei voi palauttaa. 


`7` Tallentaa tiedostoon

Tallentaa kaikki tiedot teksti-tiedostoon, sovellus-kansiossa. Käyttäjä voi antaa tiedoston nimen tai käyttää oletustiedostoa (default.txt). Jos tiedosto ei ole olemassa, se luodaan.
Varo! Jos tiedosto on jo olemassa, sovellus kirjoittaa sen päälle.
