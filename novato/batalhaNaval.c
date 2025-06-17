#include <stdio.h>

#define TAM 5
#define NAVIOS 3

int main() {
    char tabuleiro[TAM][TAM];
    int linha, coluna;

    // Inicializa
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = '~';
        }
    }

    // Posição dos navios
    printf("Posicione os %d navios:\n", NAVIOS);
    for (int i = 0; i < NAVIOS; i++) {
        do {
            printf("Informe linha e coluna do navio %d (0 a 4): ", i + 1);
            scanf("%d %d", &linha, &coluna);

            if (linha < 0 || linha >= TAM || coluna < 0 || coluna >= TAM) {
                printf("Coordenada inválida! Tente novamente.\n");
            } else if (tabuleiro[linha][coluna] == 'N') {
                printf("Já tem um navio aqui! Escolha outro lugar.\n");
            } else {
                break;
            }
        } while (1);

        tabuleiro[linha][coluna] = 'N';
    }

    // resustado da batatlha
    printf("\nTabuleiro Final:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf(" %c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
