#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash
// Este código inicial serve como base para o desenvolvimento das estruturas de navegação, pistas e suspeitos.
// Use as instruções de cada região para desenvolver o sistema completo com árvore binária, árvore de busca e tabela hash.

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void explorarSalas(Sala* sala) {
    char opcao;
    Sala* atual = sala;

    while (atual != NULL) {
        printf("\nVocê está em: %s\n", atual->nome);
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("Fim do caminho.\n");
            break;
        }
        printf("Escolha (e=esquerda, d=direita, s=sair): ");
        scanf(" %c", &opcao);

        if (opcao == 's') break;
        else if (opcao == 'e' && atual->esquerda != NULL) atual = atual->esquerda;
        else if (opcao == 'd' && atual->direita != NULL) atual = atual->direita;
        else printf("Caminho inválido!\n");
    }
}

int main() {
    Sala* hall = criarSala("Hall de Entrada");
    Sala* salaJantar = criarSala("Sala de Jantar");
    Sala* biblioteca = criarSala("Biblioteca");
    Sala* cozinha = criarSala("Cozinha");
    Sala* escritorio = criarSala("Escritório");

    hall->esquerda = salaJantar;
    hall->direita = biblioteca;
    salaJantar->esquerda = cozinha;
    biblioteca->direita = escritorio;

    explorarSalas(hall);

    free(cozinha);
    free(salaJantar);
    free(escritorio);
    free(biblioteca);
    free(hall);

    return 0;
}
