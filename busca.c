#include "busca.h"
#include <stdlib.h>
#include <string.h>

TreeNode *inserir(TreeNode *root, Pokemon *pokemon)
{
  if (root == NULL)
  {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->pokemon = pokemon;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  if (strcmp(pokemon->name, root->pokemon->name) < 0)
  {
    root->left = inserir(root->left, pokemon);
  }
  else
  {
    root->right = inserir(root->right, pokemon);
  }

  return root;
}

Pokemon *buscar(TreeNode *root, const char *nome)
{
  if (root == NULL)
  {
    return NULL;
  }

  int cmp = strcasecmp(nome, root->pokemon->name);
  if (cmp == 0)
  {
    return root->pokemon;
  }
  else if (cmp < 0)
  {
    return buscar(root->left, nome);
  }
  else
  {
    return buscar(root->right, nome);
  }
}

void liberarArvore(TreeNode *root)
{
  if (root != NULL)
  {
    liberarArvore(root->left);
    liberarArvore(root->right);
    free(root);
  }
}
