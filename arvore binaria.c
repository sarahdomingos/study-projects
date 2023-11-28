#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int valor;
    struct no *esquerda;
    struct no *direita;
}no;

no *inserir (no *raiz, int val) {
    if (raiz == NULL) {
        no *nodo = (no*) malloc (sizeof(no));
        nodo->direita = NULL;
        nodo->esquerda = NULL;
        nodo->valor = val;
        return nodo;
    }
    else {
        if (val < raiz->valor) {
            raiz->esquerda = inserir (raiz->esquerda, val);
        }
        else if (val > raiz->valor) {
            raiz->direita = inserir (raiz->direita, val);
        }
        return raiz;
    }
}

void imprimir (no *raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf ("%d ", raiz->valor);
        imprimir(raiz->direita);
    }
}

int tamanho (no *raiz) {
    if (raiz == NULL) {
        return 0;
    }
    return 1 + tamanho (raiz->esquerda) + tamanho (raiz->direita);
}

int buscar (no *raiz, int procurado) {
    if (raiz == NULL) {
        return 0;
    }
    else if (raiz->valor == procurado) {
        return 1;
    }
    else if (procurado < raiz->valor) {
        return buscar (raiz->esquerda, procurado);
    }
    else if (procurado > raiz->valor) {
        return buscar (raiz->direita, procurado);
    }
    return 0;
}

int main () {
int opcao, val;
no *raiz = NULL;

do {
    printf ("\n\nMenu de opcoes:\n\n1 - Inserir.\n2 - Remover.\n3 - Imprimir.\n4 - Buscar.\n5 - Sair.\n");
    scanf ("%d", &opcao);

        switch (opcao) {

        case 1:
        printf ("\nDigite o valor a ser inserido: ");
        scanf ("%d", &val);
        raiz = inserir (raiz, val);
        break;

        case 2:
        //remover();
        break;

        case 3:
        imprimir (raiz);
        printf ("\nTamanho da raiz: %d", tamanho (raiz));
        break;

        case 4:
        printf ("\nDigite o valor a ser buscado: ");
        int procurado;
        scanf ("%d", &procurado);
        printf ("Resultado da busca: %d", buscar (raiz, procurado));
        break;

        case 5:
        printf ("\nSaindo...");
        break;

        default:
        printf ("\nOpcao invalida.");
        break;
    }
}while (opcao != 5);

return 0;
}