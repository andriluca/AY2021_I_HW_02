# Assignment \#2

Devo progettare un modo per commutare tra vari stati di intermittenza di una strip di led (2 led?):

- 1 led rosso
- 1 led verde

Sono presenti sette diversi stati. la pressione di un tasto commuta tra questi sette stati in modo ciclico (i=(i+1)%7 ad ogni pressione di pulsante).

## Funzione switch stato

La pressione del pulsante può essere interpretata come l'incremento di un intero (uint8\_t) che deve trovarsi in un range da 0 a 6. Si risolve andando a incrementare con (count+1)%N\_STATES.

La gestione dello stato avverrà mediante un'ISR al pin 2.2, quando lo stato cambia dal precedente.
il PWM può essere necessario alla generazione del colore e basta. il colore dipende dal duty cycle delle singole componenti del R e del G.

Un'interrupt sevice routine è stata utilizzata, in quanto l'evento HW può essere più facilmente controllato in questo modo, rispetto alla tecnica del polling.
Ho deciso di utilizzare il segnale NEG del debouncer, così da sfruttare il falling edge del pulsante per generare l'isr.
L'unica operazione che deve essere effettuata nella ISR è l'aggiornamento dell'indice in modo da spaziare numeri da 0 a 6.

## Funzione per generare i colori

è necessario lavorare sia sul fronte d'onda che sul duty cycle per ottenere i diversi colori e per questo le funzioni presenti sul datasheet del PWM sono utilissime (la setCompareMode(...) infatti potrebbe essermi utile).

Fortunatamente mi sono accorto che la maggior parte del lavoro è stata fatta svolgendo l'esercizio 5 dell'ultima esercitazione. le funzioni possono essere riciclate anche se è stato necessario adattare alcuni parametri importanti, come la tipologia del fronte d'onda e il periodo sia per il canale del verde che per il canale del rosso. Essendoci due periodi diversi da considerare per le due componenti nell'ultimo stato, è stato necessario utilizzare due pwm aventi lo stesso clock in ingresso. in questo modo i segnali dei due canali venivano gestiti indipendentemente dai due pwm.

I colori sono stati definiti nel fine "colors.h". in particolare si noti l'array di colori. questo è stato molto utile in quanto basta solo aggiornare l'indice all'interno di questo array per andare a vagliare qualsivoglia stato.
