#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

typedef struct {
    int indPai;
    char valor;
} No;

int inserir (int tam, No arvore[]) {

    if (tam >= MAX) {
        printf ("Arvore cheia! Remova um elemento antes de inserir outro.\n");
        return tam;
    }
    char elemento, pai;
    if (tam == -1) {
        printf ("Digite o elemento a ser inserido: ");
        scanf (" %c", &elemento);
        arvore[0].indPai = tam;
        arvore[0].valor = elemento;
        tam++;
        printf ("Arvore atualizada!\n");
        return tam;
    }
    else {
        printf ("Digite o elemento a ser inserido: ");
        scanf (" %c", &elemento);
        printf ("Digite quem sera o pai do elemento: ");
        scanf (" %c", &pai);
        for (int i = 0; i <= tam; i++) {
            if (arvore[i].valor == pai) {
                tam++;
                arvore[tam].indPai = i;
                arvore[tam].valor = elemento;
                printf ("Arvore atualizada!\n");
                return tam;
            }
        }
        printf ("O pai informado nao existe.\n");
        return tam;
    }
return tam;
}

void imprimir (No arvore[], int tam) {
    if (tam == -1) {
        printf ("Arvore vazia!\n");
        return;
    }
    for (int i = 0; i <= tam; i++) {
        int pai = arvore[i].indPai;
        printf("Valor -> %c | Pai -> %c\n", arvore[i].valor, arvore[pai].valor);
    }
}

int main () {
    int tam = -1, op;
    No arvore[MAX];

do {
    printf ("1 - inserir\n2 - Remover\n3 - Imprimir\n4 - Buscar\n5 - Sair\n");
    scanf ("%d", &op);

    switch (op) {
        case 1:
        tam = inserir(tam, arvore);
        break;
        //case 2:
        //remover();

        case 3:
        imprimir(arvore, tam);
        break;
        //case 4:
        //buscar();
    }
}while (op != 5);
    
return 0;
}