#ifndef JOGO_H
#define JOGO_H
#include "pokedex.h"

// Definição da estrutura para os nós da fila
typedef struct FilaNode
{
    Pokemon *pokemon;
    struct FilaNode *next;
} FilaNode;

// Definição da estrutura da fila
typedef struct Fila
{
    FilaNode *front; // Primeiro elemento da fila
    FilaNode *rear;  // Último elemento da fila
} Fila;

// Declaração das funções
Fila *criarFila();
void enfileirar(Fila *fila, Pokemon *pokemon);
Pokemon *desenfileirar(Fila *fila);
int filaVazia(Fila *fila);
int compararAtributo(Pokemon *carta1, Pokemon *carta2);
int desempate(Fila *jogador1, Fila *jogador2);
void iniciarJogo(Pokedex *pokedex, int numCartas);

#endif // JOGO_H
