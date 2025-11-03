# geant4-tecniche-sperimentali-2025


Documentazione per le lezioni su Geant4 del corso di  "Tecniche Sperimentali per la Fisica delle Alte Eenergie"
per la Laurea Magistrale in Fisica dell'Università degli Studi di Perugia.


- le lezioni sono disponibili sotto forma di file PDF;
- è disponibile anche il codice per la soluzine dell'esrcizio proposto.


Utilizzo soluzioni:

1) Nella cartella `Esercizio` creare la sottocartella `build` e spostarsi al suo interno:

$ mkdir build
$ cd build

2) compilare il codice attraverso i comandi:

$ cmake -DGeant4_DIR=/path/to/geant4-install/lib/cmake/Geant4/ ..
$ make -j 4 esercizioG4

3) eseguire con:

$ ./esercizioG4 -m run10000.mac > run10000.log

Un esempio di macro  ROOT per analizzare il file generato è disponibile nella cartella `root`.

