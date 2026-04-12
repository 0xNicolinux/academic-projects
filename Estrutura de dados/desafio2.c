// Bibliotecas necessárias
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define TAM_NOME 50
#define TAM_COR 20

// Definição da struct
typedef struct Territorio
{
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;

} Territorio;

// Limpa o buffer ;-;
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// Função para entrada dos dados
void cadastro(Territorio *t)
{
    printf("Nome do territorio: ");
    fgets(t->nome, TAM_NOME, stdin);
    t->nome[strcspn(t->nome, "\n")] = '\0';

    printf("Cor do exercito: ");
    fgets(t->cor, TAM_COR, stdin);
    t->cor[strcspn(t->cor, "\n")] = '\0';

    printf("Quantidade de tropas: ");
    scanf("%d", &t->tropas);
    limparBuffer();
}

// Função para exibir os territórios cadastrados
void mostrar(Territorio *t)
{
    printf("Nome: %s\n", t->nome);
    printf("Cor: %s\n", t->cor);
    printf("Tropas: %d\n", t->tropas);
}

// Lógica de ataque
void atacar(Territorio *atacante, Territorio *defensor)
{
    int t_atacante = rand() % 6 + 1;
    int t_defesa = rand() % 6 + 1;

    if (t_atacante > t_defesa)
    {
        printf("O atacante ganhou!\n");

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas = atacante->tropas / 2;
    }
    else if (t_atacante < t_defesa)
    {
        printf("A defesa ganhou!\n");

        if (atacante->tropas > 1)
        {
            atacante->tropas = atacante->tropas - 1;
        }
    }
    else
    {
        printf("Empate!\n");
    }
}

// Libera a memória ;-;
void liberarMemoria(Territorio *mapa)
{
    free(mapa);
}

// Função principal
int main()
{
    // Inicializador
    srand(time(NULL));

    // Variáveis
    int choice;   // Escolhe se quer continuar jogando ou não
    int atacante; // Escolhe o atacante
    int defensor; // Escolhe o defensor
    int map;      // Tamanho do mapa

    // Tamanho do mapa definido pelo usuário
    printf("Defina o tamanho do mapa: ");
    scanf("%d", &map);
    limparBuffer();

    // Declaração de vetor de structs
    Territorio *mapa;

    // Memória dinâmica para o tamanho do mapa
    mapa = calloc(map, sizeof(Territorio));

    // Loop para realizar o cadastro dos territórios
    for (int i = 0; i < map; i++)
    {
        printf("-- Cadastrar Territorio %d --\n", i + 1);
        cadastro(&mapa[i]);
    }

    // Exibição
    printf("\n===== TERRITORIOS CADASTRADOS! =====\n");

    // Loop para exibir o cadastro dos territórios
    for (int i = 0; i < map; i++)
    {
        printf("\n-- Territorio %d --\n", i + 1);
        mostrar(&mapa[i]);
    }

    // Jogo...

    do
    {
        printf("\n==============================\n");
        printf("        FASE DE ATAQUE       \n");
        printf("==============================\n");

        printf("1 - Realizar ataque\n");
        printf("0 - Sair do jogo\n");
        printf("------------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int validar = 1; // Tudo ok

            printf("\n--- ESCOLHA DO ATAQUE ---\n");

            printf("Escolha o ATACANTE (1 a %d): ", map);
            scanf("%d", &atacante);
            limparBuffer();

            printf("Escolha o DEFENSOR (1 a %d): ", map);
            scanf("%d", &defensor);
            limparBuffer();

            if (atacante < 1 || atacante > map || defensor < 1 || defensor > map)
            {
                validar = 0;
                printf("\n[ERRO] Escolha invalida! Os territorios devem estar entre 1 e %d.\n", map);
            }

            if (atacante == defensor)
            {
                validar = 0;
                printf("\n[ERRO] Nao e permitido atacar o proprio territorio!\n");
            }

            if (validar == 1)
            {
                printf("\n>>> EXECUTANDO ATAQUE...\n\n");

                atacar(&mapa[atacante - 1], &mapa[defensor - 1]); // O -1 serve para acessar o índice correto

                printf("\n>>> ATAQUE FINALIZADO\n");

                for (int i = 0; i < map; i++)
                {
                    printf("\n-- Territorio %d --\n", i + 1);
                    mostrar(&mapa[i]);
                }
            }
        }

    } while (choice != 0);

    liberarMemoria(mapa); // Libera a memória

    return 0;
}