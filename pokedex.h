#ifndef POKEDEX_H
#define POKEDEX_H
#include "pokemon.h"

typedef struct Pokedex
{
    Pokemon *head;
    Pokemon *tail;
} Pokedex;

Pokedex *criarPokedex();
void adicionarPokemon(Pokedex *pokedex, Pokemon *pokemon);
void carregarPokedex(Pokedex *pokedex, const char *filename);
void exibirPokedex(Pokedex *pokedex);
void liberarPokedex(Pokedex *pokedex);

#endif // POKEDEX_H
