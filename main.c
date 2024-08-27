#include <stdio.h>
#include <stdlib.h>
#include "pokedex.h"
#include "busca.h"
#include "jogo.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Uso: %s <num_cartas>\n", argv[0]);
    return 1;
  }

  int numCartas = atoi(argv[1]);

  Pokedex *pokedex = criarPokedex();
  carregarPokedex(pokedex, "pokemon.csv");

  printf("Pokédex carregada:\n");
  exibirPokedex(pokedex);

  TreeNode *root = NULL;
  Pokemon *current = pokedex->head;

  while (current)
  {
    root = inserir(root, current);
    current = current->next; // Certifique-se de iterar corretamente sobre a lista de Pokémons
  }

  liberarArvore(root);
  liberarPokedex(pokedex); // Liberação da memória da Pokédex

  return 0;
}
