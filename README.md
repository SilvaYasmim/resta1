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

Planejo implementar o jogo no modo de coordenadas (ex: 2 3 2 5 — linha/coluna de origem e destino) e depois adicionar setas (cima/baixo/esquerda/direita) com ncurses como bónus.

## Estrutura do projeto

## Autor