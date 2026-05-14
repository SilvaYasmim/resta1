#include <stdio.h>
#include <ncurses/ncurses.h>
#include "game.h"

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    initscr();
    noecho();
    cbreak();
    mousemask(ALL_MOUSE_EVENTS, NULL);
    
    inicializar_tabuleiro(tabuleiro);
    mostrar_tabuleiro(tabuleiro);
    refresh();
    getch();
    endwin();
    return 0;
}