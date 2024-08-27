#include "fila.h"
#include "pokemon.h"
#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>

void iniciarJogo(Pokedex *pokedex, int numCartas)
{
    // Inicialização das filas dos jogadores
    Fila *jogador1 = criarFila();
    Fila *jogador2 = criarFila();

    // Distribuição das cartas
    Pokemon *current = pokedex->head;
    int count = 0;
    while (current && count < numCartas * 2)
    {
        Pokemon *carta = malloc(sizeof(Pokemon));
        *carta = *current;
        carta->next = carta->prev = NULL; // Corrigir ponteiros da lista
        if (count % 2 == 0)
        {
            enfileirar(jogador1, carta);
        }
        else
        {
            enfileirar(jogador2, carta);
        }
        current = current->next;
        count++;
    }

    int desempate(Fila * jogador1, Fila * jogador2, int atributoEscolhido);

    int compararAtributo(Pokemon * carta1, Pokemon * carta2, int atributoEscolhido);

    int escolherAtributo();

    // Lógica do jogo
    while (!filaVazia(jogador1) && !filaVazia(jogador2))
    {
        Pokemon *carta1 = desenfileirar(jogador1);
        Pokemon *carta2 = desenfileirar(jogador2);

        // Jogador 1 escolhe um atributo
        int atributoEscolhido = escolherAtributo();

        int resultado = compararAtributo(carta1, carta2, atributoEscolhido);
        if (resultado > 0)
        {
            printf("Jogador 1 vence a rodada!\n");
            enfileirar(jogador1, carta1);
            enfileirar(jogador1, carta2);
        }
        else if (resultado < 0)
        {
            printf("Jogador 2 vence a rodada!\n");
            enfileirar(jogador2, carta1);
            enfileirar(jogador2, carta2);
        }
        else
        {
            printf("Empate! Desempate com nova carta.\n");
            enfileirar(jogador1, carta1);
            enfileirar(jogador2, carta2);
            resultado = desempate(jogador1, jogador2, atributoEscolhido);
            if (resultado > 0)
            {
                printf("Jogador 1 vence o desempate!\n");
            }
            else
            {
                printf("Jogador 2 vence o desempate!\n");
            }
        }
    }

    if (filaVazia(jogador1))
    {
        printf("Jogador 2 vence o jogo!\n");
    }
    else
    {
        printf("Jogador 1 vence o jogo!\n");
    }

    // Liberar memória das filas
    while (!filaVazia(jogador1))
    {
        Pokemon *pokemon = desenfileirar(jogador1);
        free(pokemon);
    }
    while (!filaVazia(jogador2))
    {
        void *pokemon = desenfileirar(jogador2);
        free(pokemon);
    }

    free(jogador1);
    free(jogador2);
}