#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

// Função para inserir um elemento no início da lista
void inserir(No** cabeca, int dado) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->proximo = *cabeca;
    *cabeca = novoNo;
}

// Função para exibir todos os elementos da lista
void exibir(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

// Função para atualizar um elemento da lista
void atualizar(No* cabeca, int dadoAntigo, int dadoNovo) {
    No* atual = cabeca;
    while (atual != NULL) {
        if (atual->dado == dadoAntigo) {
            atual->dado = dadoNovo;
            printf("Valor %d atualizado para %d.\n", dadoAntigo, dadoNovo);
            return;
        }
        atual = atual->proximo;
    }
    printf("Valor %d não encontrado.\n", dadoAntigo);
}

// Função para remover um elemento da lista
void remover(No** cabeca, int dado) {
    No* temp = *cabeca;
    No* anterior = NULL;

    if (temp != NULL && temp->dado == dado) {
        *cabeca = temp->proximo;
        free(temp);
        printf("Valor %d removido.\n", dado);
        return;
    }

    while (temp != NULL && temp->dado != dado) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Valor %d não encontrado.\n", dado);
        return;
    }

    anterior->proximo = temp->proximo;
    free(temp);
    printf("Valor %d removido.\n", dado);
}

int main() {
    // Configuração para aceitar caracteres especiais
    setlocale(LC_ALL, "Portuguese_Brazil");

    No* cabeca = NULL;
    int opcao, dado, dadoAntigo, dadoNovo;

    while (1) {
        printf("\nEscolha uma operação:\n");
        printf("1. Inserir\n");
        printf("2. Consultar\n");
        printf("3. Alterar\n");
        printf("4. Remover\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &dado);
                inserir(&cabeca, dado);
                break;
            case 2:
                printf("Lista: ");
                exibir(cabeca);
                break;
            case 3:
                printf("Digite o valor a ser alterado: ");
                scanf("%d", &dadoAntigo);
                printf("Digite o novo valor: ");
                scanf("%d", &dadoNovo);
                atualizar(cabeca, dadoAntigo, dadoNovo);
                break;
            case 4:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &dado);
                remover(&cabeca, dado);
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
}
