#include <stdio.h>
#include <time.h>
#include "game.h"

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
                printf("   ");
            }
            else if (linha == 3 && coluna == 3)
            {
                printf(" _ ");
            }
            else
            {
                printf(" O ");
            }
            
        }
        printf("\n");
    }
    
}