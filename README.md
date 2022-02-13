# Practica2-skeleton

Esquelet de la segona pràctica de Programació 1.

No modifiqueu els noms dels fitxers.

Nom dels Participans i número d'indentificació:

Àlex Codina Braceros 49750825P
Sebastian Jitaru Y1051960T

Hem fet la versió dificil de area.cpp

mapa.cpp:

La primera part del programa, ha sigut la recollida de dades del document localitzacio.csv, les quals les hem guardat en DadesMunicipis[1000][7] (Amb posicions extra per a marges)
Per aquesta taula a la columna 0 es guarda el codi de municipi, a la 1 i 2 la latitud i longitud, a la 3 es guarda el número que es dibuixara en el mapa, que es decideix posteriorment.
Per acabar, a la 4 i 5 es guarda la coordenada entre 0 i 19 dels dos eixos(que es posaran a mapa[20][20]) en que s'ha transformat la latitud i longitud reals.

A continuació treballem amb el registre-covid.csv, aqui comparem en cada fila el codi de municipi amb el que nosaltres tenim guardat, i un cop coincideixen comparem si els seus casos són més elevats al nostre llindar. En el cas en que el llindar fos més gran, posariam un '1' a la columna 3 de DadesMunicipis[][].

Una vegada tenim les dades, coloquem els '1' en la variable mapa. Ho fem amb un bucle en qual a dintre coloquem la condició per a que s'ompleni amb '1' o '0'.

Per acabar s'implement imprimim el mapa.

area.cpp:

Comencem generant dos nombres aleatoris i els assignem a les variables x, y; tal que aquestes correspondran a una posició del mapa.

Continuem introduint el mapa anterior en mapa[N+1][N+1] (Amb posicions extra per a marges) la qual manipularem més endavant.

A continuació situarem un '2' en la posició mapa[x][y], sols si aquesta és '1'.
Més endavant farem les linies en totes direccions, dal, baix, esquerra, dreta, i les diagonals corresponents també.

Per acabar imprimirem el mapa igual que en mapa.cpp.



