#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 5

// Função para exibir a matriz
void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Habilidade em cone
void habilidadeCone(int matriz[TAM][TAM]) {
    // Zera toda a matriz
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = 0;

    int centro = TAM / 2; // coluna central (2)
    
    // Início do cone na linha 1, vai até linha 3 (inclusive)
    for (int i = 1; i <= 3; i++) {
        int largura = i - 1; // quantas colunas expandem para os lados
        for (int j = centro - largura; j <= centro + largura; j++) {
            matriz[i][j] = 1;
        }
    }
}

// Habilidade em cruz
void habilidadeCruz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            matriz[i][j] = (i == TAM / 2 || j == TAM / 2) ? 1 : 0;
}

// Habilidade em octaedro
void habilidadeOctaedro(int matriz[TAM][TAM]) {
    int centro = TAM / 2;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Soma das distâncias verticais e horizontais em relação ao centro <= centro
            matriz[i][j] = (abs(i - centro) + abs(j - centro) <= centro) ? 1 : 0;
        }
    }
}

int main() {
    int matriz[TAM][TAM];

    printf("Habilidade: CONE\n");
    habilidadeCone(matriz);
    exibirMatriz(matriz);

    printf("Habilidade: CRUZ\n");
    habilidadeCruz(matriz);
    exibirMatriz(matriz);

    printf("Habilidade: OCTAEDRO\n");
    habilidadeOctaedro(matriz);
    exibirMatriz(matriz);

    return 0;
}
