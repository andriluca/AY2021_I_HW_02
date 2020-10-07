# Assignment \#2

Devo progettare un modo per commutare tra vari stati di intermittenza di una strip di led (2 led?):

- 1 led rosso
- 1 led verde

Sono presenti sette diversi stati. la pressione di un tasto commuta tra questi sette stati in modo ciclico (i=(i+1)%7 ad ogni pressione di pulsante).

## Funzione switch stato

La pressione del pulsante può essere interpretata come l'incremento di un intero (uint8\_t) che deve trovarsi in un range da 0 a 6. Si risolve andando a incrementare con (count+1)%N\_STATES.
