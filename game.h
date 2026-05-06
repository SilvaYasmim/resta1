#ifndef GAME_H
#define GAME_H

#include <time.h>

#define TAMANHO 7
#define PINO 1
#define VAZIO 0
#define INVALIDO -1

void inicializar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]);

void mostrar_tabuleiro(int tabuleiro[TAMANHO][TAMANHO]);

int validar_movimento(int tabuleiro[TAMANHO][TAMANHO],int orig_linha, int orig_coluna, int dest_linha, int dest_coluna);

void executar_movimento( int tabuleiro[TAMANHO][TAMANHO],int orig_linha, int orig_coluna, int dest_linha, int dest_coluna);

int verificar_fim_do_jogo( int tabuleiro[TAMANHO][TAMANHO]);

int mostrar_menu();

char* pedir_nome();

void guardar_score( char* nome, int pontuacao, time_t tempo);

void mostrar_historico();






#endif