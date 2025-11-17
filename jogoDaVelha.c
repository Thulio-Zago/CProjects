#include <stdio.h>

#define TAMANHO 3

char tabuleiro[TAMANHO][TAMANHO];
char jogador_atual = 'X';

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro() {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("---|---|---\n");
    }
    printf("\n");
}

int verificarVencedor() {
    // Verificar linhas e colunas
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] == jogador_atual && tabuleiro[i][1] == jogador_atual && tabuleiro[i][2] == jogador_atual)
            return 1;
        if (tabuleiro[0][i] == jogador_atual && tabuleiro[1][i] == jogador_atual && tabuleiro[2][i] == jogador_atual)
            return 1;
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][2] == jogador_atual)
        return 1;
    if (tabuleiro[0][2] == jogador_atual && tabuleiro[1][1] == jogador_atual && tabuleiro[2][0] == jogador_atual)
        return 1;
    return 0;
}

int verificarEmpate() {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (tabuleiro[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void trocarJogador() {
    jogador_atual = (jogador_atual == 'X') ? 'O' : 'X';
}

int jogadaValida(int linha, int coluna) {
    return linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ';
}

void realizarJogada() {
    int linha, coluna;
    do {
        printf("Jogador %c, digite a linha e coluna (0, 1 ou 2) para a sua jogada: ", jogador_atual);
        scanf("%d %d", &linha, &coluna);
    } while (!jogadaValida(linha, coluna));
    tabuleiro[linha][coluna] = jogador_atual;
}

int main() {
    inicializarTabuleiro();
    while (1) {
        exibirTabuleiro();
        realizarJogada();
        if (verificarVencedor()) {
            exibirTabuleiro();
            printf("Jogador %c venceu!\n", jogador_atual);
            break;
        }
        if (verificarEmpate()) {
            exibirTabuleiro();
            printf("O jogo terminou em empate!\n");
            break;
        }
        trocarJogador();
    }
    return 0;
}
