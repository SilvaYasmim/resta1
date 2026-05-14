#include <stdio.h>
#include "game.h"

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    inicializar_tabuleiro(tabuleiro);
    mostrar_tabuleiro(tabuleiro);
    return 0;
}