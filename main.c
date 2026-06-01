#include <stdio.h>
#include <ncurses/ncurses.h>
#include <time.h>
#include "game.h"
#include "score.h"

int contar_pinos(int tabuleiro[TAMANHO][TAMANHO]) {
    int i, j, count = 0;
    for (i = 0; i < TAMANHO; i++)
        for (j = 0; j < TAMANHO; j++)
            if (tabuleiro[i][j] == PINO) count++;
    return count;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int opcao, orig_linha, orig_coluna, dest_linha, dest_coluna, estado;
    char nome[50];
    time_t inicio, fim;

    initscr();
    noecho();
    cbreak();

    opcao = mostrar_menu();

    if (opcao == 3) { endwin(); return 0; }

    if (opcao == 2) {
        mostrar_historico();
        endwin();
        return 0;
    }

    clear();
    mvprintw(5, 10, "O teu nome: ");
    echo();
    scanw("%s", nome);
    noecho();
    time(&inicio);

    inicializar_tabuleiro(tabuleiro);

    while (1) {
        clear();
        mostrar_tabuleiro(tabuleiro);
        refresh();

        estado = verificar_fim_do_jogo(tabuleiro);
        if (estado == 1) {
            time(&fim);
            guardar_score(nome, contar_pinos(tabuleiro), fim - inicio);
            mvprintw(11, 0, "GANHOU! Restou 1 pino! Tempo: %lds", fim - inicio);
            refresh();
            getch();
            break;
        }
        if (estado == 2) {
            time(&fim);
            guardar_score(nome, contar_pinos(tabuleiro), fim - inicio);
            mvprintw(11, 0, "PERDEU! %d pinos restantes. Tempo: %lds", contar_pinos(tabuleiro), fim - inicio);
            refresh();
            getch();
            break;
        }

        mvprintw(10, 0, "Origem (linha coluna): ");
        echo();
        scanw("%d %d", &orig_linha, &orig_coluna);
        noecho();
        mvprintw(10, 0, "Destino (linha coluna):                    ");
        mvprintw(10, 0, "Destino (linha coluna): ");
        echo();
        scanw("%d %d", &dest_linha, &dest_coluna);
        noecho();

        if (!validar_movimento(tabuleiro, orig_linha, orig_coluna, dest_linha, dest_coluna)) {
            mvprintw(11, 0, "Movimento invalido! Tente novamente.");
            refresh();
            getch();
        } else {
            executar_movimento(tabuleiro, orig_linha, orig_coluna, dest_linha, dest_coluna);
        }
    }

    endwin();
    return 0;
}