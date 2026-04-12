// Bibliotecas necessárias
#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_COR 20

// Definição da struct
typedef struct Territorio
{
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;

} Territorio;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
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

int main()
{
    // Declaração de vetor de structs
    Territorio mapa[5];

    // Loop para realizar o cadastro dos territórios
    for (int i = 0; i < 5; i++)
    {
        printf("-- Cadastrar Territorio %d --\n", i + 1);
        cadastro(&mapa[i]);
    }

    // Exibição
    printf("\n===== TERRITORIOS CADASTRADOS =====\n");

    // Loop para exibir o cadastro dos territórios
    for (int i = 0; i < 5; i++)
    {
        printf("\n-- Territorio %d --\n", i + 1);
        mostrar(&mapa[i]);
    }

    // Jogo...

    return 0;
}