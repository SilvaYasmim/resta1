#include <stdio.h>
#include <ncurses/ncurses.h>
#include "score.h"

void guardar_score(char* nome, int pontuacao, time_t tempo)
{
    FILE* f = fopen("scores.txt", "a");
    if (f == NULL) return;
    fprintf(f, "%s | Pinos restantes: %d | Tempo: %lds\n", nome, pontuacao, tempo);
    fclose(f);
}

void mostrar_historico()
{
    FILE* f = fopen("scores.txt", "r");
    char linha[200];
    int y = 3;
    clear();
    mvprintw(1, 10, "=== HISTORICO ===");
    if (f == NULL) {
        mvprintw(3, 10, "Sem registos ainda.");
    } else {
        while (fgets(linha, sizeof(linha), f)) {
            mvprintw(y++, 5, "%s", linha);
        }
        fclose(f);
    }
    mvprintw(y + 1, 10, "Prima qualquer tecla para voltar...");
    refresh();
    getch();
}