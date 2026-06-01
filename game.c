#include <ncurses/ncurses.h>
#include <time.h>
#include "game.h"
#include <stdlib.h>

int mostrar_menu()
{
    int opcao;
    clear();
    mvprintw(2, 10, "=== RESTA 1 ===");
    mvprintw(4, 10, "1. Jogar");
    mvprintw(5, 10, "2. Como Jogar");
    mvprintw(6, 10, "3. Ver Historico");
    mvprintw(7, 10, "4. Sair");
    mvprintw(9, 10, "Escolha: ");
    refresh();
    echo();
    scanw("%d", &opcao);
    noecho();
    return opcao;
}

void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    int linha, coluna;
    for (linha = 0; linha < TAMANHO; linha++)
    {
        for (coluna = 0; coluna < TAMANHO; coluna++)
        {
            if ((linha < 2 || linha > 4) && (coluna < 2 || coluna > 4))
                tabuleiro[linha][coluna] = INVALIDO;
            else if (linha == 3 && coluna == 3)
                tabuleiro[linha][coluna] = VAZIO;
            else
                tabuleiro[linha][coluna] = PINO;
        }
    }
}

void mostrar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    int linha, coluna;
    mvprintw(1, 1, "  0  1  2  3  4  5  6");
    for (linha = 0; linha < TAMANHO; linha++)
    {
        mvprintw(linha + 2, 0, "%d", linha);
        for (coluna = 0; coluna < TAMANHO; coluna++)
        {
            if (tabuleiro[linha][coluna] == INVALIDO)
                mvprintw(linha + 2, coluna * 3 + 2, "   ");
            else if (tabuleiro[linha][coluna] == VAZIO)
                mvprintw(linha + 2, coluna * 3 + 2, " _ ");
            else
                mvprintw(linha + 2, coluna * 3 + 2, " O ");
        }
    }
}

int validar_movimento(int tabuleiro[TAMANHO][TAMANHO], int orig_linha, int orig_coluna, int dest_linha, int dest_coluna)
{
    int linha_meio, coluna_meio;
    if (dest_linha < 0 || dest_linha >= TAMANHO || dest_coluna < 0 || dest_coluna >= TAMANHO)
        return 0;
    linha_meio = (orig_linha + dest_linha) / 2;
    coluna_meio = (orig_coluna + dest_coluna) / 2;
    if (tabuleiro[orig_linha][orig_coluna] != PINO) return 0;
    if (tabuleiro[dest_linha][dest_coluna] != VAZIO) return 0;
    if (tabuleiro[linha_meio][coluna_meio] != PINO) return 0;
    if (abs(dest_linha - orig_linha) + abs(dest_coluna - orig_coluna) != 2) return 0;
    return 1;
}

void executar_movimento(int tabuleiro[TAMANHO][TAMANHO], int orig_linha, int orig_coluna, int dest_linha, int dest_coluna)
{
    int linha_meio = (orig_linha + dest_linha) / 2;
    int coluna_meio = (orig_coluna + dest_coluna) / 2;
    tabuleiro[orig_linha][orig_coluna] = VAZIO;
    tabuleiro[linha_meio][coluna_meio] = VAZIO;
    tabuleiro[dest_linha][dest_coluna] = PINO;
}

int verificar_fim_do_jogo(int tabuleiro[TAMANHO][TAMANHO])
{
    int linha, coluna, contador = 0;
    for (linha = 0; linha < TAMANHO; linha++)
        for (coluna = 0; coluna < TAMANHO; coluna++)
            if (tabuleiro[linha][coluna] == PINO) contador++;
    if (contador == 1) return 1;
    for (linha = 0; linha < TAMANHO; linha++)
        for (coluna = 0; coluna < TAMANHO; coluna++) {
            if (validar_movimento(tabuleiro, linha, coluna, linha - 2, coluna)) return 0;
            if (validar_movimento(tabuleiro, linha, coluna, linha + 2, coluna)) return 0;
            if (validar_movimento(tabuleiro, linha, coluna, linha, coluna - 2)) return 0;
            if (validar_movimento(tabuleiro, linha, coluna, linha, coluna + 2)) return 0;
        }
    return 2;
}