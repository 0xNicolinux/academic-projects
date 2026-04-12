// ==============================
// BIBLIOTECAS NECESSÁRIAS
// ==============================

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ==============================
// CONSTANTES DO PROJETO
// ==============================

#define TAM_NOME 50
#define TAM_COR 20

// ==============================
// ESTRUTURA DO TERRITÓRIO
// ==============================

typedef struct Territorio
{
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

// ==============================
// FUNÇÕES UTILITÁRIAS
// ==============================

// Limpa o buffer do teclado (evita problemas com scanf/fgets)
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Cadastra os dados de um território
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

// Exibe as informações de um território
void mostrar(Territorio *t)
{
    printf("Nome: %s\n", t->nome);
    printf("Cor: %s\n", t->cor);
    printf("Tropas: %d\n", t->tropas);
}

// Modificada para receber e alterar a pontuação
void atacar(Territorio *atacante, Territorio *defensor, int *pontuacao)
{
    int t_atacante = rand() % 6 + 1;
    int t_defesa = rand() % 6 + 1;

    printf("\n%s atacou causando %d pontos de dano!\n", atacante->nome, t_atacante);
    printf("%s defendeu bloqueando %d pontos de dano!\n", defensor->nome, t_defesa);

    if (t_atacante > t_defesa)
    {
        printf("\n%s venceu a batalha! (+10 Pontos)\n", atacante->nome);
        printf("%s recua para se reagrupar!\n", defensor->nome);

        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas = atacante->tropas / 2;
        
        *pontuacao += 10; // Soma 10 pontos na vitória
    }
    else if (t_atacante < t_defesa)
    {
        printf("\n%s defendeu com sucesso!\n", defensor->nome);
        printf("%s perde uma tropa!\n", atacante->nome);

        if (atacante->tropas > 1)
        {
            atacante->tropas--;
        }
    }
    else
    {
        printf("\nEmpate! Nenhum território sofreu alterações. (+5 Pontos)\n");
        *pontuacao += 5; // Soma 5 pontos no empate
    }
}

void atribuirMissao(char *destino, char *missoes[], int totalMissoes)
{
    int numeroSorteado = rand() % totalMissoes;
    strcpy(destino, missoes[numeroSorteado]);
}

int verificarMissao(char *missao, Territorio *mapa, int tamanho)
{
    if (strcmp(missao, "Conquistar 2 territorios") == 0)
    {
        int contador = 0;
        for (int i = 0; i < tamanho; i++)
        {
            if (strcmp(mapa[i].cor, mapa[0].cor) == 0)
            {
                contador++;
            }
        }
        if (contador >= 2) return 1;
        return 0;
    }
    else if (strcmp(missao, "Ter pelo menos 15 tropas em um territorio") == 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (mapa[i].tropas >= 15) return 1;
        }
        return 0;
    }
    else if (strcmp(missao, "Conquistar todos os territorios") == 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (strcmp(mapa[i].cor, mapa[0].cor) != 0) return 0;
        }
        return 1;
    }
    else if (strcmp(missao, "Reduzir um territorio inimigo para 1 tropa") == 0)
    {
        for (int i = 0; i < tamanho; i++)
        {
            if (strcmp(mapa[i].cor, mapa[0].cor) != 0)
            {
                if (mapa[i].tropas == 1) return 1;
            }
        }
        return 0;
    }
    else if (strcmp(missao, "Conquistar 3 territorios") == 0)
    {
        int contador = 0;
        for (int i = 0; i < tamanho; i++)
        {
            if (strcmp(mapa[i].cor, mapa[0].cor) == 0)
            {
                contador++;
            }
        }
        if (contador >= 3) return 1;
        return 0;
    }
    return 0;
}

void exibirMissao(char *missao)
{
    printf("\n==============================\n");
    printf("      MISSÃO CONCLUÍDA!       \n");
    printf("==============================\n");
    printf("%s\n", missao);
    printf("==============================\n");
}

// Modificada para exibir as duas missões e a pontuação atual
void statusMissoes(char *principal, char *secundaria, int secConcluida, int pontuacao)
{
    printf("\n==============================\n");
    printf(" PONTUAÇÃO ATUAL: %d\n", pontuacao);
    printf("==============================\n");
    printf(" Missão Principal: \n -> %s\n\n", principal);
    
    printf(" Missão Secundária: \n -> %s ", secundaria);
    if (secConcluida) {
        printf("[CONCLUÍDA!]\n");
    } else {
        printf("[Em andamento]\n");
    }
    printf("==============================\n");
}

// Libera a memória alocada dinamicamente para o mapa
void liberarMemoriaMapa(Territorio *mapa)
{
    free(mapa);
}

// ==============================
// FUNÇÃO PRINCIPAL
// ==============================

int main()
{
    srand(time(NULL));

    int choice;   // Opção do menu principal
    int atacante; // Índice do território atacante
    int defensor; // Índice do território defensor
    int map;      // Tamanho do mapa (quantidade de territórios)
    
    // Novas variáveis de jogo
    int pontuacao = 0;
    int statusSecundaria = 0; // 0 = Não concluída, 1 = Concluída
    char missaoPrincipal[] = "Conquistar todos os territorios";

    // Removida a missão principal do array de aleatórias
    char *missoesSecundarias[] = {"Conquistar 2 territorios",
                                  "Ter pelo menos 15 tropas em um territorio",
                                  "Reduzir um territorio inimigo para 1 tropa",
                                  "Conquistar 3 territorios"};

    char *missaoSecundaria;
    missaoSecundaria = calloc(100, sizeof(char));

    // Define o tamanho do mapa
    printf("Defina o tamanho do mapa: ");
    scanf("%d", &map);
    limparBuffer();

    // Alocação dinâmica do mapa de territórios
    Territorio *mapa = calloc(map, sizeof(Territorio));

    // Cadastro dos territórios
    for (int i = 0; i < map; i++)
    {
        printf("-- Cadastrar Territorio %d --\n", i + 1);
        cadastro(&mapa[i]);
    }

    // Exibição dos territórios cadastrados
    printf("\n===== TERRITORIOS CADASTRADOS! =====\n");

    for (int i = 0; i < map; i++)
    {
        printf("\n-- Territorio %d --\n", i + 1);
        mostrar(&mapa[i]);
    }

    // Sorteia apenas a missão secundária (4 opções agora)
    atribuirMissao(missaoSecundaria, missoesSecundarias, 4);

    // Loop principal do jogo
    do
    {
        printf("\n==============================\n");
        printf("        FASE DE ATAQUE       \n");
        printf("==============================\n");

        printf("Pontuação: %d pts\n\n", pontuacao);
        printf("1 - Realizar ataque\n");
        printf("2 - Verificar missões e status\n");
        printf("0 - Sair do jogo\n");
        printf("------------------------------\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int validar = 1;

            printf("\n--- ESCOLHA DO ATAQUE ---\n");

            printf("Escolha o ATACANTE (1 a %d): ", map);
            scanf("%d", &atacante);
            limparBuffer();

            printf("Escolha o DEFENSOR (1 a %d): ", map);
            scanf("%d", &defensor);
            limparBuffer();

            // Validação de entrada
            if (atacante < 1 || atacante > map || defensor < 1 || defensor > map)
            {
                validar = 0;
                printf("\n[ERRO] Território inválido! Escolha valores entre 1 e %d.\n", map);
            }
            else if (strcmp(mapa[atacante - 1].cor, mapa[defensor - 1].cor) == 0)
            {
                validar = 0;
                printf("\n[ERRO] Não é permitido atacar o próprio território!\n");
            }

            // Execução do ataque
            if (validar == 1)
            {
                printf("\n>>> EXECUTANDO ATAQUE...\n");

                // Passa o endereço de memória da pontuação para ela ser alterada lá dentro
                atacar(&mapa[atacante - 1], &mapa[defensor - 1], &pontuacao);

                printf("\n>>> ATAQUE FINALIZADO!\n");

                // Exibe estado atualizado do mapa
                for (int i = 0; i < map; i++)
                {
                    printf("\n-- Territorio %d --\n", i + 1);
                    mostrar(&mapa[i]);
                }
                
                // Verifica a Missão Secundária (avisa apenas se bateu a meta e não havia batido antes)
                if (statusSecundaria == 0 && verificarMissao(missaoSecundaria, mapa, map) == 1)
                {
                    printf("\n*** PARABÉNS! VOCÊ CONCLUIU A MISSÃO SECUNDÁRIA! ***\n");
                    exibirMissao(missaoSecundaria);
                    statusSecundaria = 1; 
                }

                // Verifica a Missão Principal (Finaliza o jogo)
                if (verificarMissao(missaoPrincipal, mapa, map) == 1)
                {
                    printf("\n*** VITÓRIA SUPREMA! MISSÃO PRINCIPAL CONCLUÍDA! ***\n");
                    exibirMissao(missaoPrincipal);
                    printf("Sua pontuação final foi de: %d pts!\n", pontuacao);
                    break;
                }
            }
        }
        else if (choice == 2)
        {
            statusMissoes(missaoPrincipal, missaoSecundaria, statusSecundaria, pontuacao);
        }

    } while (choice != 0);

    // Liberação de memória
    liberarMemoriaMapa(mapa);
    free(missaoSecundaria);

    return 0;
}