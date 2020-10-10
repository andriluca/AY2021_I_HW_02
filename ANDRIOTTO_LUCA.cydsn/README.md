# Assignment \#2

Il prototipo del dispositivo, mediante la pressione del pulsante built-in, commuta sette diversi stati. 

1. OFF - Stazionario
1. ON/OFF Green - Intermittenza
1. ON/OFF Red - Intermittenza
1. Green ON, Red OFF - Alternanza lenta
1. Green ON, Red OFF - Alternanza veloce
1. OFF, Green, Orange - Ciclico
1. Red, Orange, OFF, Green - Ciclico

NB: Utilizzando la configurazione riportata nello schematico il colore Orange è poco visibile. L'impiego di due resistenze da 330\Omega

In particolare è stato utilizzato un evento hardware associato al segnale, opportunamente filtrato dal Debouncer Software, pressione del pulsante (collegato in modalità PULL-UP resistivo).
La pressione incrementa un indicatore di stato (chiamato ``state'') in un intervallo da 0 a 6, per selezionare il pattern di colori da eseguire.
I dati relativi alla collezione dei vari stati sono memorizzati in un array di tipo Color, la cui definizione è riportata in ``RGBLedDriver.h''.
In questo modo lo stato aggiornato dall'ISR punta sequenzialmente ai dati contenuti nell'array.

La gestione dei colori è stata la parte più complessa da realizzare.
Sono stati utilizzati due PWM connessi, rispettivamente, ai due catodi del led RGB.
La modulazione delle onde quadre che questi devono generare ha tenuto conto delle seguenti considerazioni:

- Periodo: in generale ogni stato sopra elencato possiede due componenti con periodi indipendenti. In particolar modo mi riferisco all'ultimo stato in cui si ha il RED CHANNEL a periodo T e duty cycle del 50% e il GREEN CHANNEL con periodo T/2 e duty cycle del 50%. Non ci fosse stata questa indipendenza tra i due stati avrei potuto addirittura utilizzare un solo PWM. La gestione del periodo è mediata dalla procedura ``PWM\_WritePeriod()''.
- Seconda parte dell'onda quadra: Determina il duty cycle dell'onda quadra generata in ciascun channel. La gestione del duty cycle è mediata dalla procedura ``PWM\_WriteCompare''.
- Tipologia di onda quadra: in alcuni casi lo stato iniziale è HIGH, in altri è LOW. La gestione del tipo è mediata dalla procedura "PWM\_SetCompareMode()", abilitabile soltanto abilitando PWM\> CMP Type 1\> Firmware Control da schematico.

La struttura dei colori tiene conto di ciò per entrambi i colori, quindi ciascun colore dispone di sei attributi in totale.

Una feature del codice permette di impostare il delay di ciascuno stato indipendentemente, necessario quando nel loop del main si esegue un pattern.
L'obiettivo è stato quello di minimizzare i tempi d'attesa, dal momento che la procedura "CyDelay()" è bloccante e l'ISR non è in grado di interromperla.


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
