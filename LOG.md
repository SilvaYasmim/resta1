## Sessão 1 – 04/05/2026

**Funcionalidades implementadas:**
- Estrutura inicial do projeto criada (main.c, game.c, game.h, README.md, README.en.md, LOG.md)
- README.md em português com introdução, regras e estrutura do projeto
- Repositório GitHub criado e ligado ao projeto local
- Primeiro commit efetuado

**Maior dificuldade:**
Pensar na estrutura do projeto e na estrutura do README.

**Como resolvi (ou não resolvi):**
Olhei o matérial e os projetos anteriores, para ter como base.

**Próximo passo planeado:**
- Completar o README (secções: Como compilar, Como jogar, Autor)
- Iniciar o game.h com a estrutura de dados do tabuleiro

**Linhas de código escritas (estimativa):**
0 (sessão dedicada a documentação e configuração do projeto)


## Sessão 2 – 06/05/2026

**Funcionalidades implementadas:**
- Planeamento de funções e variáveis (PLANNING.md)
- game.h completo com constantes, includes e protótipos de funções

**Maior dificuldade:**
Saber a variavel do tempo do score, qual caracteristica ia levar, se int ou alguma de tempo.

**Como resolvi (ou não resolvi):**
Pensando que é um jogo de paciencia e que provavelmente teriamos horas e minutos para representar, então ia precisar mais do que um int em segundos. 

**Próximo passo planeado:**
- Iniciar game.c com a implementação das funções
- Começar por inicializar_tabuleiro e mostrar_tabuleiro

**Linhas de código escritas (estimativa):**
15

## Sessão 3 – 14/05/2026

**Funcionalidades implementadas:**
- Adicionaei inicializador do tabuleiro e mostrar tabuleiro
- Adicionei ncurses

**Maior dificuldade:**
integrar o ncurses com o MSYS2

**Como resolvi (ou não resolvi):**
Encontrando exatamente onde estavam as pastas do projeto e do MSYS2 e rodando cd no MSYS2 e depois copiando o caminho pro vscode.

**Próximo passo planeado:**
-implementar função validar_movimento

**Linhas de código escritas (estimativa):**
25

## Sessão 4 – 15/05/2026

**Funcionalidades implementadas:**
- Adicionaei funções validar movimento e executar movimento no game.c 
- Adicionei função para verificar o fim do jogo.

**Maior dificuldade:**
-Como calcular a verificação do tabuleiro em 4 sentidos ( cima, baixo, esquerda e direita)
-Como fazer o Ncurses funcionar direito para poder redesenhar o tabuleiro no final do loop.

**Como resolvi (ou não resolvi):**
-desenhei o tabuleiro e pensei como a peça tinha q se mover em linhas e colunas e identifiquei que seria com linha +2 ou -2 e coluna +2 ou -2
-ainda n resolvi o problema do ncurses...

**Próximo passo planeado:**
-Resolver problema do ncurses para ele poder gerar novo tabuleiro, talvez fazer um clear e um refresh depois.

**Linhas de código escritas (estimativa):**
30

## Sessão 5 – 01/06/2026

**Funcionalidades implementadas:**
- Menu principal com opções Jogar, Ver Histórico e Sair
- Sistema de score com nome do jogador e tempo de jogo
- Ficheiros score.c e score.h criados
- Histórico guardado em scores.txt
- Coordenadas no tabuleiro (linhas e colunas)
- Loop do jogo completo e funcional

**Maior dificuldade:**
foi conseguir achar uma forma mais intuitiva de representar a tabela... acho que o jogo não da pra entender como as peças se movem...

**Como resolvi (ou não resolvi):**
ainda estou organizando, coloquei uma malha com coordenadas, mas ainda n acho suficiente.

**Próximo passo planeado:**
- Completar README com estrutura do projeto
- Testes finais e entrega

**Linhas de código escritas (estimativa):**
80