#ifndef FILA_H
#define FILA_H

#include "pokemon.h" // Inclua o cabeçalho que define a estrutura Pokemon

typedef struct FilaNode {
    Pokemon *pokemon;
    struct FilaNode *next;
} FilaNode;

typedef struct Fila {
    FilaNode *front;
    FilaNode *rear;
} Fila;

Fila* criarFila();
void enfileirar(Fila *fila, Pokemon *pokemon);
Pokemon* desenfileirar(Fila *fila);
int filaVazia(Fila *fila);

#endif // FILA_H