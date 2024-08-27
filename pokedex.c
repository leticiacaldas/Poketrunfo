#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Pokedex *criarPokedex()
{
    Pokedex *pokedex = (Pokedex *)malloc(sizeof(Pokedex));
    if (!pokedex)
    {
        perror("Erro ao alocar memória para a Pokédex");
        exit(EXIT_FAILURE);
    }
    pokedex->head = NULL;
    pokedex->tail = NULL;
    return pokedex;
}

void adicionarPokemon(Pokedex *pokedex, Pokemon *pokemon)
{
    if (pokedex->head == NULL)
    {
        pokedex->head = pokemon;
        pokedex->tail = pokemon;
    }
    else
    {
        pokedex->tail->next = pokemon;
        pokemon->prev = pokedex->tail;
        pokedex->tail = pokemon;
    }
}

void carregarPokedex(Pokedex *pokedex, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        Pokemon *pokemon = (Pokemon *)malloc(sizeof(Pokemon));
        if (!pokemon)
        {
            perror("Erro ao alocar memória para o Pokémon");
            fclose(file);
            return;
        }
        sscanf(line, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d",
               pokemon->name, pokemon->type1, pokemon->type2,
               &pokemon->hp, &pokemon->attack, &pokemon->defense,
               &pokemon->sp_atk, &pokemon->sp_def,
               &pokemon->legendary);
        pokemon->prev = NULL;
        pokemon->next = NULL;
        adicionarPokemon(pokedex, pokemon);
    }

    fclose(file);
}

void exibirPokedex(Pokedex *pokedex)
{
    Pokemon *current = pokedex->head;
    while (current)
    {
        printf("Nome: %s, Tipo1: %s, Tipo2: %s, HP: %d, Ataque: %d, Defesa: %d, Ataque Especial: %d, Defesa Especial: %d, Lendário: %d\n",
               current->name, current->type1, current->type2, current->hp,
               current->attack, current->defense, current->sp_atk,
               current->sp_def, current->legendary);
        current = current->next;
    }
}

void liberarPokedex(Pokedex *pokedex)
{
    Pokemon *current = pokedex->head;
    while (current != NULL)
    {
        Pokemon *next = current->next;
        free(current);
        current = next;
    }
    free(pokedex);
}
