#include <stdio.h>

#define TAM 10
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\nTabuleiro:\n   ");
    for (int j = 0; j < TAM; j++)
        printf("%2d ", j);
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2d ", i);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0)
                printf(" ~ ");
            else if (tabuleiro[i][j] == NAVIO)
                printf(" N ");
        }
        printf("\n");
    }
}

int posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (coluna + tamanho > TAM) return 0;

    for (int j = 0; j < tamanho; j++)
        if (tabuleiro[linha][coluna + j] != 0) return 0;

    for (int j = 0; j < tamanho; j++)
        tabuleiro[linha][coluna + j] = NAVIO;

    return 1;
}

int posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho) {
    if (linha + tamanho > TAM) return 0;

    for (int i = 0; i < tamanho; i++)
        if (tabuleiro[linha + i][coluna] != 0) return 0;

    for (int i = 0; i < tamanho; i++)
        tabuleiro[linha + i][coluna] = NAVIO;

    return 1;
}

int posicionarNavioDiagonal(int tabuleiro[TAM][TAM], int linha, int coluna, int tamanho, int direcao) {
    if ((linha + tamanho > TAM) || (coluna + direcao * (tamanho - 1) < 0) || (coluna + direcao * (tamanho - 1) >= TAM))
        return 0;

    for (int i = 0; i < tamanho; i++)
        if (tabuleiro[linha + i][coluna + i * direcao] != 0) return 0;

    for (int i = 0; i < tamanho; i++)
        tabuleiro[linha + i][coluna + i * direcao] = NAVIO;

    return 1;
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Posicionando navios
    posicionarNavioHorizontal(tabuleiro, 2, 1, 4);   // Horizontal
    posicionarNavioVertical(tabuleiro, 0, 7, 3);     // Vertical
    posicionarNavioDiagonal(tabuleiro, 5, 0, 4, 1);  // Diagonal ↘
    posicionarNavioDiagonal(tabuleiro, 1, 9, 3, -1); // Diagonal ↙

    exibirTabuleiro(tabuleiro);

    return 0;
}
