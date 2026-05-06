#Pensando nas variaveis

tabuleiro - uma matriz 7x7 de inteiros
nome_jogador - string (array de char)
pontuacao - inteiro
tempo - inteiro
estado_jogo - inteiro (0, 1 ou 2)
opcao_menu - inteiro (1, 2, 3 ou 4)


#Planeando as funções

inicializar_tabuleiro → recebe o tabuleiro[7][7] , não devolve nada.

mostrar_tabuleiro → recebe o tabuleiro[7][7] e nao devolve nada .


validar_movimento → recebe o tabuleiro + coordenadas de origem e destino
                  → devolve 1 (válido) ou 0 (inválido)


executar_movimento → recebe tabuleiro + coordenadas de origem e destino
                   → não devolve nada (modifica o tabuleiro diretamente)


verificar_fim_do_jogo → recebe tabuleiro
                      → devolve 0, 1 ou 2
0 → jogo continua
1 → ganhou (restou 1 peça)
2 → perdeu (sem movimentos, mais de 1 peça)


mostrar_menu → não recebe nada
             → devolve a opção escolhida (1, 2, 3 ou 4)


pedir_nome → não recebe nada
           → devolve o nome introduzido (string)


guardar_score → recebe nome, pontuação e tempo
             → não devolve nada (escreve no ficheiro)

mostrar_historico → não recebe nada
                  → não devolve nada (lê e imprime o ficheiro)