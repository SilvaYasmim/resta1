#include <stdio.h>
#include <ncurses/ncurses.h>
#include "game.h"

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    int orig_linha, orig_coluna, dest_linha, dest_coluna;
    int estado;

    initscr();
    noecho();
    cbreak();

    inicializar_tabuleiro(tabuleiro);

    while (1) {
        clear();
        mostrar_tabuleiro(tabuleiro);
        refresh();

        estado = verificar_fim_do_jogo(tabuleiro);
        if (estado == 1) {
            mvprintw(10, 0, "GANHOU! Restou 1 pino!");
            refresh();
            getch();
            break;
        }
        if (estado == 2) {
            mvprintw(10, 0, "PERDEU! Sem movimentos possiveis.");
            refresh();
            getch();
            break;
        }

       mvprintw(9, 0, "Origem (linha coluna): ");
echo();
scanw("%d %d", &orig_linha, &orig_coluna);
noecho();
mvprintw(9, 0, "Destino (linha coluna):                    ");
mvprintw(9, 0, "Destino (linha coluna): ");
echo();
scanw("%d %d", &dest_linha, &dest_coluna);
noecho();

        if (!validar_movimento(tabuleiro, orig_linha, orig_coluna, dest_linha, dest_coluna)) {
            mvprintw(10, 0, "Movimento invalido! Tente novamente.");
            refresh();
            getch();
        } else {
            executar_movimento(tabuleiro, orig_linha, orig_coluna, dest_linha, dest_coluna);
        }
    }

    endwin();
    return 0;
}