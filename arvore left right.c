#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

typedef struct {
    int indPai, filhoEsq, irmaoDir;
    char info;
} No;

int inserir(int tam, No arvore[]) {
    if (tam >= MAX) {
        printf ("Arvore cheia!!\n");
        return tam;
    }
    char elemento, pai;
    if (tam == -1) {
        printf ("Digite o elemento a ser inserido: ");
        scanf (" %c", &elemento);
        arvore[0].indPai = tam;
        arvore[0].info = elemento;
        arvore[0].filhoEsq = -1;
        arvore[0].irmaoDir = -1;
        tam++;
        printf ("Arvore atualizada!\n");
        return tam;
    }
    printf ("Digite o elemento a ser inserido: ");
    scanf (" %c", &elemento);
    printf ("Digite quem sera o pai do elemento: ");
    scanf (" %c", &pai);
    for (int i = 0; i <= tam; i++) {
        if (arvore[i].info == pai) {
            tam++;
            arvore[tam].info = elemento;
            arvore[tam].indPai = i;
            arvore[tam].filhoEsq = -1;
            if (arvore[i].filhoEsq == -1) {
                arvore[i].filhoEsq = tam;
                arvore[tam].irmaoDir = -1;
                printf ("Arvore atualizada!\n");
                return tam;
            }
            else {
                int filhoEsq = arvore[i].filhoEsq;
                if (arvore[filhoEsq].irmaoDir == -1) {
                    arvore[filhoEsq].irmaoDir = tam;
                    arvore[tam].irmaoDir = -1;
                    printf ("Arvore atualizada!\n");
                    return tam;
                }
                else {
                    int irmaoDir = arvore[filhoEsq].irmaoDir;
                    for (int j = irmaoDir; j <= tam; j++) {
                        if (arvore[j].irmaoDir == -1) {
                            arvore[j].irmaoDir = tam;
                            arvore[tam].irmaoDir = -1;
                            printf ("Arvore atualizada!\n");
                            return tam;
                        }
                    }
                }
            }
        }
    }
printf ("O pai informado nao existe.\n");
return tam;
}

void imprimir (No arvore[], int tam) {
    if (tam == -1) {
        printf ("Arvore vazia!!\n");
        return;
    }
    for (int i = 0; i <= tam; i++) {
        printf ("[%d] ", i);
        printf("Valor -> %c | Pai -> %d | FilhoEsq -> %d | IrmaoDir -> %d\n", arvore[i].info, arvore[i].indPai, arvore[i].filhoEsq, arvore[i].irmaoDir);
    }
}

int main () {
    int tam = -1, op;
    No arvore[MAX];

do {
    printf ("1 - inserir\n2 - Remover\n3 - Imprimir\n4 - Buscar\n5 - Sair\nDigite a opcao escolhida: ");
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