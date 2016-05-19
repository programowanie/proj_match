#Żółtaniecki Piotr 
## Symulacja meczu piłkarskiego

Program ma składać się z 10 plików, z nazwiskami piłkarzy. Program inicjalizuje dwie drużyny, czyli zostają wybrane dwa pliki, z których powstaną drużyny.(drużyna miałaby być kolejką lub wektorem 6 elementowym).

Konstruktor tworzy obiekty piłkarzy, którzy dostają od 60 do 90 następujących cech:

- obrony podania,
- obrony dryblingu,
- strzał na bramkę (z pewnym prawdopodobieństwem trafienia w bramkę), 
- podania, 
- dryblingu.

Żeby strzelić gola trzeba pokonać wszystkich zawodników drużyny przeciwnej i trafić do bramki.
 Pokonuje się zawsze 1 zawodnika poprzez podanie lub drybling, gdzie drybling i podanie występuje z pewnym prawdopodobieństwem, zależnym TYLKO od cech napastnika.

Po pokonaniu ostatniego zawodnika z pola, zawodnik może podać lub strzelić, przy czym podanie może się odbyć tylko raz po pokonaniu wszystkich zawodników z pola.

Następuje strzał w światło lub nie. 

Po strzale zaczyna druzyna przeciwna.

Gra toczy się do momentu wykonania n akcji, gdzie akcja to podanie strzał itp.

Elementy, które zrobiłbym jeśli poszło by szybko z fazą opisana powyżej.

- zmiana zawodników z ławki
-bramkarz


