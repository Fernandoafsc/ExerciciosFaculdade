#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

// Funcao para criar um novo no
No* criarNo(int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Funcao para inserir um no na arvore
No* inserir(No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

// Funcao para encontrar o no minimo da arvore (utilizado na remocao)
No* encontrarMinimo(No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Funcao para remover um no da arvore
No* remover(No* raiz, int dado) {
    if (raiz == NULL) {
        return raiz;
    }
    if (dado < raiz->dado) {
        raiz->esquerda = remover(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = remover(raiz->direita, dado);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        No* temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
    }
    return raiz;
}

// Funcao de busca em pre-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Funcao de busca em ordem
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->dado);
        emOrdem(raiz->direita);
    }
}

// Funcao de busca em pos-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->dado);
    }
}

int main() {
    No* raiz = NULL;
    int opcao, dado;

    while (1) {
        printf("\n* * * MENU DE OPCOES * * *\n");
        printf("1. Incluir no\n");
        printf("2. Remover no\n");
        printf("3. Buscar pre-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pos-ordem\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &dado);
                raiz = inserir(raiz, dado);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &dado);
                raiz = remover(raiz, dado);
                break;
            case 3:
                printf("Busca pre-ordem: ");
                preOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("Busca em ordem: ");
                emOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("Busca pos-ordem: ");
                posOrdem(raiz);
                printf("\n");
                break;
            case 0:
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Opcao invalida!\n");
        }
    }
}
