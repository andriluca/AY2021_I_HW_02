# Assignment \#2

Il prototipo del dispositivo, mediante la pressione del pulsante built-in, commuta sette diversi stati (o color pattern). 

## Pin

- Built-in
	- 2.2 → Momentary switch.
- LED RGB:
	- 2.6 → GREEN CHANNEL.
	- 2.7 → RED CHANNEL.

## Color Pattern

1. OFF - Stazionario
1. ON/OFF Green - Intermittenza
1. ON/OFF Red - Intermittenza
1. Green ON, Red OFF - Alternanza lenta
1. Green ON, Red OFF - Alternanza veloce
1. OFF, Green, Orange - Ciclico
1. Red, Orange, OFF, Green - Ciclico

_NB_: Utilizzando la configurazione riportata nello schematico il colore Orange è poco visibile. L'impiego di due resistenze da 330Ω, posizionate rispettivamente tra catodo di ciascun channel e pwm di quel channel, risolve questo problema, ottenendo il colore Yellow al posto dell'Orange.

## ISR: Pressione del pulsante integrato

In particolare è stato utilizzato un evento hardware associato al segnale, opportunamente filtrato dal Debouncer Software, pressione del pulsante (collegato in modalità PULL-UP resistivo).
La pressione incrementa un indicatore di stato (chiamato "state") in un intervallo da 0 a 6, per selezionare il pattern di colori da eseguire.
I dati relativi alla collezione dei vari stati sono memorizzati in un array di tipo Color, la cui definizione è riportata in "RGBLedDriver.h".
In questo modo lo stato aggiornato dall'ISR punta sequenzialmente ai dati contenuti nell'array.

## PWM: Gestione accensione/spegnimento LED RGB

La gestione dei colori è stata la parte più complessa da realizzare.
Sono stati utilizzati due PWM connessi, rispettivamente, ai due catodi del LED RGB.
La modulazione delle onde quadre che questi devono generare ha tenuto conto delle seguenti considerazioni:

- _Periodo_: in generale ogni stato sopra elencato possiede due componenti con periodi indipendenti. In particolar modo mi riferisco all'ultimo stato in cui si ha il RED CHANNEL a periodo T e duty cycle del 50% e il GREEN CHANNEL con periodo T/2 e duty cycle del 50%. Non ci fosse stata questa indipendenza tra i due stati avrei potuto addirittura utilizzare un solo PWM. La gestione del periodo è mediata dalla procedura "PWM\_WritePeriod()".
- _Seconda parte dell'onda quadra_: Determina il duty cycle dell'onda quadra generata in ciascun channel. La gestione del duty cycle è mediata dalla procedura "PWM\_WriteCompare()".
- _Tipologia di onda quadra_: in alcuni casi lo stato iniziale è HIGH, in altri è LOW. La gestione del tipo è mediata dalla procedura "PWM\_SetCompareMode()", abilitabile soltanto abilitando PWM \> CMP Type 1 \> Firmware Control da schematico.

### Struct: Color

La struttura dei colori tiene conto di ciò per entrambi i colori, quindi ciascun colore dispone di sei attributi in totale.

## Delay

Una feature del codice permette di impostare il delay di ciascuno stato indipendentemente, necessario quando nel loop del main si esegue un pattern.
L'obiettivo è stato quello di minimizzare i tempi d'attesa, dal momento che la procedura "CyDelay()" è bloccante e l'ISR non è in grado di interromperla.
