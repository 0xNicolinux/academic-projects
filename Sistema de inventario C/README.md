# 🎮 Sistema de Inventário - Jogo de Sobrevivência (C)

Este projeto faz parte de um desafio de programação em C, onde foi desenvolvido um sistema simples de inventário inspirado em jogos de sobrevivência.

O jogador pode armazenar, organizar e gerenciar itens coletados após o pouso em uma ilha, como armas, munições, kits médicos e ferramentas.

---

## 🎯 Objetivo

Simular uma mochila de loot inicial de um jogador, utilizando:

- Structs para representar itens
- Vetores estáticos
- Funções para modularização
- Busca e manipulação de dados em lista sequencial

---

## 🧱 Estrutura do Item

Cada item do inventário é representado pela struct:

```c
typedef struct Item {
    char nome[30];      // Nome do item (ex: AK-47, Bandagem)
    char tipo[20];      // Tipo do item (arma, munição, cura, ferramenta)
    int quantidade;    // Quantidade disponível
} Item;