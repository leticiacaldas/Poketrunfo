#ifndef BUSCA_H
#define BUSCA_H

#include "pokedex.h"

typedef struct TreeNode {
	Pokemon* pokemon;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode* inserir(TreeNode* root, Pokemon* pokemon);
Pokemon* buscar(TreeNode* root, const char* nome);
void liberarArvore(TreeNode* root);

#endif // BUSCA_H
