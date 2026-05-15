#include <ncurses/ncurses.h>
#include <time.h>
#include "game.h"
#include <stdlib.h>

void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    int linha, coluna;
    for (linha = 0; linha < TAMANHO; linha++)
    {
        for (coluna = 0; coluna < TAMANHO; coluna++)
        {
            if ((linha < 2 || linha > 4) && (coluna < 2 || coluna > 4))
            {
                tabuleiro[linha][coluna] = INVALIDO;
            }
            else if (linha == 3 && coluna == 3)
            {
                tabuleiro[linha][coluna] = VAZIO;
            }
            else
            {
                tabuleiro[linha][coluna] = PINO;
            }
        }
    }
}

void mostrar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO])
{
    int linha, coluna;
    for (linha = 0; linha < TAMANHO; linha++)
    {
        for (coluna = 0; coluna < TAMANHO; coluna++)
        {
            if ((linha < 2 || linha > 4) && (coluna < 2 || coluna > 4))
            {
                mvprintw(linha, coluna * 3, "   ");
            }
            else if (linha == 3 && coluna == 3)
            {
                mvprintw(linha, coluna * 3, " _ ");
            }
            else
            {
                mvprintw(linha, coluna * 3, " O ");
            }
        }
    }
}

int validar_movimento(int tabuleiro[TAMANHO][TAMANHO], int orig_linha, int orig_coluna, int dest_linha, int dest_coluna)
{
    int linha_meio;
    int coluna_meio;
    linha_meio = (orig_linha + dest_linha) / 2;
    coluna_meio = (orig_coluna + dest_coluna) / 2;

    if (tabuleiro[orig_linha][orig_coluna] != PINO)
        return 0;
    if (tabuleiro[dest_linha][dest_coluna] != VAZIO)
        return 0;
    if (tabuleiro[linha_meio][coluna_meio] != PINO)
        return 0;
    if (abs(dest_linha - orig_linha) + abs(dest_coluna - orig_coluna) != 2)
        return 0;

    return 1;
}

void executar_movimento(int tabuleiro[TAMANHO][TAMANHO], int orig_linha, int orig_coluna, int dest_linha, int dest_coluna)
{

    int linha_meio;
    int coluna_meio;
    linha_meio = (orig_linha + dest_linha) / 2;
    coluna_meio = (orig_coluna + dest_coluna) / 2;

    tabuleiro[orig_linha][orig_coluna] = VAZIO;
    tabuleiro[linha_meio][coluna_meio] = VAZIO;
    tabuleiro[dest_linha][dest_coluna] = PINO;
}