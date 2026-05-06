# Resta 1

> 🚧 Em progresso / Work in progress

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

Precisas de ter o GCC instalado.

```bash
gcc main.c game.c -o resta1
```

Para executar:

```bash
# Linux/macOS
./resta1

# Windows
resta1.exe
```

## Como jogar

Ao iniciar o programa, o tabuleiro é apresentado no terminal com as coordenadas
de cada posição (linha e coluna).

Para realizar um movimento, introduz as coordenadas da peça que queres mover
e as coordenadas do destino:

Origem (linha coluna): 3 1
Destino (linha coluna): 3 3

A peça salta sobre a peça adjacente e esta é removida do tabuleiro.

> 🚧 Navegação por setas do teclado planeada como funcionalidade futura.

## Estrutura do projeto

1.Menu principal — 1 jogador, 2 jogadores, histórico, sair
2.Pedir nome do jogador — para guardar no histórico
3.Inicializar o tabuleiro — colocar as 32 peças + centro vazio
4.Mostrar o tabuleiro — no terminal com coordenadas
5.Receber input — coordenadas de origem e destino
6.Validar o movimento — segue as regras?
7.Executar o movimento — move a peça, remove a saltada
8.Verificar fim do jogo — há movimentos possíveis? quantas peças restam?
9.Mostrar resultado — ganhou ou perdeu, tempo, pontuação
10.Guardar histórico — salvar nome, pontuação e tempo em ficheiro
11.Mostrar histórico — ler e apresentar o ficheiro

resta1/
├── main.c       → menu, loop principal, input do utilizador
├── game.c       → lógica do jogo (tabuleiro, movimentos, validação)
├── game.h       → declarações de game.c
├── score.c      → guardar e ler histórico de pontuações
├── score.h      → declarações de score.c
├── README.md    → documentação em português
├── README.en.md → documentação em inglês
└── LOG.md       → diário de desenvolvimento

## Autor

**Yasmim Silva**  
Formação em Java — IEFP  
[GitHub](https://github.com/SilvaYasmim)