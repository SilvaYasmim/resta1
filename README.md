# Resta 1

## Sobre o projeto

Este projeto foi desenvolvido no âmbito da cadeira de Programação em C/C++ — Fundamentos,
integrada na formação de Java do IEFP. A escolha do jogo, porém, foi pessoal: o Resta 1 
foi-me ensinado pela minha bisavó, com quem cresci, e que tinha uma paixão especial por 
jogos de paciência. Este mês ela completa 100 anos — este projeto é, de certa forma, 
uma homenagem a ela.

## O que é o Resta 1

O Resta 1 é um jogo de paciência para um jogador. O objetivo é simples: 
a partir de um tabuleiro quase cheio, tens de eliminar peças até restar apenas uma.
As peças eliminam-se "saltando" umas sobre as outras — e é aí que está o desafio.
Parece fácil, mas exige estratégia e antecipação.

## Regras

- O tabuleiro começa com 32 pinos e um único espaço vazio no centro.
- O tabuleiro tem formato de cruz ("+").
- Um movimento consiste em saltar um pino por cima de outro adjacente, 
  na horizontal ou na vertical, para um espaço vazio — o pino saltado é removido.
- Só é possível saltar um pino de cada vez.
- Não é permitido mover na diagonal.
- O jogo termina quando não há mais movimentos possíveis.
- **Ganhas** se restar apenas um pino no tabuleiro.
- **Perdes** se restarem mais do que um pino sem movimentos possíveis.

## Como compilar

Precisas de ter o GCC e o ncurses instalados.

**Linux/macOS:**
```bash
gcc main.c game.c score.c -o resta1 -lncurses
```

**Windows (MSYS2 UCRT64):**
```bash
gcc main.c game.c score.c -o resta1 -I/ucrt64/include/ncurses -L/ucrt64/lib -lncursesw
```

Para executar:
```bash
./resta1
```

## Como jogar

Ao iniciar o programa aparece um menu com as opções Jogar, Como Jogar, Ver Histórico e Sair.

O tabuleiro é apresentado no terminal com coordenadas de linha e coluna (0-6).
Para realizar um movimento, introduz as coordenadas de origem e destino:

Origem (linha coluna): 3 5
Destino (linha coluna): 3 3

A peça salta sobre a peça adjacente e esta é removida do tabuleiro.

## Estrutura do projeto

resta1/
├── main.c        → ponto de entrada, menu principal e loop do jogo
├── game.c        → lógica do jogo (tabuleiro, movimentos, validação)
├── game.h        → declarações e constantes de game.c
├── score.c       → guardar e mostrar histórico de pontuações
├── score.h       → declarações de score.c
├── README.md     → documentação em português
├── README.en.md  → documentação em inglês
├── PLANNING.md   → planeamento de funções e variáveis
└── LOG.md        → diário de desenvolvimento

## Autor

**Yasmim Silva**  
Formação em Java — IEFP  
[GitHub](https://github.com/SilvaYasmim)