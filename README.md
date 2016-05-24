#Żółtaniecki Piotr 
## Symulacja meczu piłkarskiego

Program ma składać się z 2 plików, z nazwiskami piłkarzy. Program inicjalizuje dwie drużyny.(drużyna miałaby być kolejką lub wektorem n elementowym).

Konstruktor tworzy obiekty piłkarzy, którzy dostają od 30 do 80 następujących cech:

- obrony podania,
- obrony dryblingu,
- strzał na bramkę (z pewnym prawdopodobieństwem trafienia w bramkę), 
- podania, 
- dryblingu.

Żeby strzelić gola trzeba pokonać wszystkich zawodników drużyny przeciwnej i trafić do bramki.
 Pokonuje się zawsze 1 zawodnika poprzez podanie lub drybling, gdzie drybling i podanie występuje z pewnym prawdopodobieństwem, zależnym TYLKO od cech napastnika.
Gdy zawodnik przedrybluje przeciwnika to pomijany jest jeden gracz z druzyny atakujacej, gdy obronca przejmie pilke staje sie pierwszym zawodnikiem druzyny atkujacej. Czyli żeby strzelic gola trzeba wykonac z wynikiem pozytywnym 5 akcji typu podanie/drybling oraz strzał.

Po pokonaniu ostatniego zawodnika z pola, zawodnik może podać lub strzelić, przy czym podanie może się odbyć tylko raz po pokonaniu wszystkich zawodników z pola.

Następuje strzał w światło lub nie. 

Po strzale zaczyna druzyna przeciwna.

Gra toczy się do momentu wykonania n akcji, gdzie akcja to podanie strzał itp.

Elementy, które zrobiłbym jeśli poszło by szybko z fazą opisana powyżej.

- zmiana zawodników z ławki
-bramkarz


