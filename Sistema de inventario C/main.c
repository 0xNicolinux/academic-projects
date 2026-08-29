#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NOME_TAM 30
#define TIPO_TAM 20

typedef struct Item
{
    char nome[NOME_TAM];
    char tipo[TIPO_TAM];
    int quantidade;
} Item;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void inserirItem(Item item[], int *tamanho)
{
    int qtd;

    printf("Digite a quantidade de itens a serem cadastrados: ");
    scanf("%d", &qtd);
    limparBuffer();

    if (*tamanho + qtd > 10)
    {
        printf("Inventário cheio!\n");
        return;
    }
    else
    {
        for (int i = 0; i < qtd; i++)
        {
            printf("\nNome: ");
            fgets(item[*tamanho].nome, NOME_TAM, stdin);
            item[*tamanho].nome[strcspn(item[*tamanho].nome, "\n")] = '\0';

            printf("Tipo: ");
            fgets(item[*tamanho].tipo, TIPO_TAM, stdin);
            item[*tamanho].tipo[strcspn(item[*tamanho].tipo, "\n")] = '\0';

            printf("Quantidade: ");
            scanf("%d", &item[*tamanho].quantidade);
            limparBuffer();
            (*tamanho)++;
        }

    }
}

void exibirItem(Item item[], int *tamanho)
{
    printf("== Mochila ==\n");

    for (int i = 0; i < *tamanho; i++)
    {
        printf("\nNome: %s\n", item[i].nome);
        printf("Tipo: %s\n", item[i].tipo);
        printf("Quantidade: %d\n", item[i].quantidade);
    }
}

void removerItem(Item item[], int *tamanho)
{
    char remove[NOME_TAM];

    printf("Qual item deseja remover? ");
    fgets(remove, NOME_TAM, stdin);
    remove[strcspn(remove, "\n")] = '\0';

    for (int i = 0; i < *tamanho; i++)
    {
        if (strcmp(remove, item[i].nome) == 0)
        {

            for (int j = i; j < *tamanho - 1; j++)
            {
                item[j] = item[j + 1];
            }

            (*tamanho)--;
            break;
        }
    }
}

void buscarItem(Item item[], int *tamanho)
{
    char itemMochila[NOME_TAM];

    printf("Qual item deseja buscar? ");
    fgets(itemMochila, NOME_TAM, stdin);
    itemMochila[strcspn(itemMochila, "\n")] = '\0';

    for (int i = 0; i < *tamanho; i++)
    {
        if (strcmp(itemMochila, item[i].nome) == 0)
        {
            printf("Nome: %s\n", item[i].nome);
            printf("Tipo: %s\n", item[i].tipo);
            printf("Quantidade: %d\n", item[i].quantidade);
        }
    }
}

int main(void)
{
    Item item[10];
    int opcaoUsuario = -1;
    int tamanho = 0;

    do
    {
        printf("\n============================\n");
        printf("        INVENTÁRIO          \n");
        printf("============================\n");

        printf("\n1 - Inserir item");
        printf("\n2 - Remover item");
        printf("\n3 - Listar itens");
        printf("\n4 - Procurar item");
        printf("\n0 - Sair");

        printf("\n\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuario);
        limparBuffer();

        printf("\n----------------------------\n");

        switch (opcaoUsuario)
        {
        case 1:
            printf(">>> INSERIR ITEM\n\n");
            inserirItem(item, &tamanho);
            break;

        case 2:
            printf(">>> REMOVER ITEM\n\n");
            removerItem(item, &tamanho);
            break;

        case 3:
            printf(">>> LISTA DE ITENS\n\n");
            exibirItem(item, &tamanho);
            break;

        case 4:
            printf(">>> PROCURAR ITEM\n\n");
            buscarItem(item, &tamanho);
            break;

        case 0:
            printf("Saindo do sistema...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }

    } while (opcaoUsuario != 0);

    return 0;
}