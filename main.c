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

    while (1) {
        opcao = mostrar_menu();

        if (opcao == 4) { endwin(); return 0; }

        if (opcao == 2) {
            clear();
            mvprintw(2, 10, "=== COMO JOGAR ===");
            mvprintw(4, 5, "O tabuleiro tem coordenadas de linha e coluna (0-6).");
            mvprintw(5, 5, "Para mover, introduz a linha e coluna de origem,");
            mvprintw(6, 5, "depois a linha e coluna de destino.");
            mvprintw(7, 5, "Exemplo: origem '3 5', destino '3 3'");
            mvprintw(8, 5, "A peca salta sobre a adjacente e elimina-a.");
            mvprintw(9, 5, "Objetivo: restar apenas 1 pino no tabuleiro!");
            mvprintw(11, 5, "Prima qualquer tecla para voltar...");
            refresh();
            getch();
            continue;
        }

        if (opcao == 3) {
            mostrar_historico();
            continue;
        }

        // opcao == 1 → Jogar
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
    }

    endwin();
    return 0;
}