#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAM_NOME 30
#define TAM_COR 10

typedef struct
{
    char *missaoAtual;
    char nome[TAM_NOME];
    char cor[TAM_COR];

    int tropas;
    int ataques;
    int conquistas;

} Territorio;

/* ==================================================
   FUNCOES AUXILIARES
   ================================================== */

void limparBuffer()
{
    int caractere;
    while ((caractere = getchar()) != '\n' && caractere != EOF)
        ;
}

/* ==================================================
   FUNCOES DE CADASTRO E EXIBICAO
   ================================================== */
void exibirTerritorios(Territorio *territorios, int quantidadeTerritorios)
{
    printf("\n====================================");
    printf("\n      MAPA DE TERRITORIOS");
    printf("\n====================================\n");

    for (int i = 0; i < quantidadeTerritorios; i++)
    {
        printf("\n----------- TERRITORIO %d -----------\n", i + 1);

        printf("Nome.............: %s\n", territorios[i].nome);
        printf("Cor..............: %s\n", territorios[i].cor);
        printf("Quantidade tropas: %d\n", territorios[i].tropas);
    }
}

void cadastrarTerritorios(Territorio *territorios, int quantidadeTerritorios)
{
    for (int i = 0; i < quantidadeTerritorios; i++)
    {
        printf("\n====================================");
        printf("\n      CADASTRO DO TERRITORIO %d", i + 1);
        printf("\n====================================\n");

        printf("Nome do territorio: ");
        fgets(territorios[i].nome, TAM_NOME, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do territorio: ");
        fgets(territorios[i].cor, TAM_COR, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        limparBuffer();
    }
    printf("\n====================================");
    printf("\n    TERRITORIOS CADASTRADOS!");
    printf("\n====================================\n");

    exibirTerritorios(territorios, quantidadeTerritorios);
}

/* ==================================================
   FUNCOES DE ATAQUE
   ================================================== */

void exibirResultadoAtaque(Territorio *territorioAtacante, Territorio *territorioDefensor, int dadoAtacante, int dadoDefensor)
{
    printf("\n====================================");
    printf("\n         RESULTADO DO ATAQUE");
    printf("\n====================================\n");

    printf("Territorio atacante : %s\n", territorioAtacante->nome);

    printf("Territorio defensor : %s\n", territorioDefensor->nome);

    printf("\nDado do atacante....: %d", dadoAtacante);

    printf("\nDado do defensor....: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor)
    {
        printf("\n>>> O ATAQUE FOI UM SUCESSO!\n");
    }

    if (dadoDefensor > dadoAtacante)
    {
        printf("\n>>> O DEFENSOR RESISTIU AO ATAQUE!\n");
    }

    if (dadoAtacante == dadoDefensor)
    {
        printf("\n>>> O CONFRONTO TERMINOU EM EMPATE!\n");
    }
}

void ataque(Territorio *territorioAtacante, Territorio *territorioDefensor)
{
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    exibirResultadoAtaque(territorioAtacante, territorioDefensor, dadoAtacante, dadoDefensor);
    territorioAtacante->ataques++;

    if (dadoAtacante > dadoDefensor)
    {
        strcpy(territorioDefensor->cor, territorioAtacante->cor);
        territorioDefensor->tropas = territorioAtacante->tropas / 2;
        territorioAtacante->tropas = territorioAtacante->tropas / 2;

        territorioAtacante->conquistas++;
    }

    if (dadoDefensor > dadoAtacante)
    {
        territorioAtacante->tropas = territorioAtacante->tropas - 1;
    }
}

/* ==================================================
   MISSOES
   ================================================== */

void exibirMissao(char *missaoJogador)
{
    printf("\n====================================\n");
    printf("          MISSÃO DO JOGADOR\n");
    printf("====================================\n");
    printf("Objetivo: %s\n", missaoJogador);
    printf("====================================\n");
}

void sortearMissao(char *destino, char *listaMissao[], int totalMissoes)
{
    int dadoMissao = rand() % totalMissoes;
    strcpy(destino, listaMissao[dadoMissao]);
}

/* ==================================================
   CONDIÇOES DE VITORIA
   ================================================== */

int contarCor(Territorio *jogador, char *cor, int quantidadeTerritorios)
{
    int contador = 0;

    for (int i = 0; i < quantidadeTerritorios; i++)
    {
        if (strcmp(jogador[i].cor, cor) == 0)
        {
            contador++;
        }
    }

    return contador;
}

int verificarMissao(Territorio *jogador, Territorio *mapa, int tamanho)
{
    if (strcmp(jogador->missaoAtual, "Conquiste 1 territorio inimigo") == 0)
        return jogador->conquistas >= 1;

    if (strcmp(jogador->missaoAtual, "Realize 3 ataques") == 0)
        return jogador->ataques >= 3;

    if (strcmp(jogador->missaoAtual, "Conquiste o primeiro territorio do jogo") == 0)
        return jogador->conquistas >= 1;

    if (strcmp(jogador->missaoAtual, "Conquiste 2 territorios inimigos") == 0)
        return jogador->conquistas >= 2;

    if (strcmp(jogador->missaoAtual, "Controle 2 territorios com a mesma cor") == 0)
    {
        if (contarCor(mapa, jogador->cor, tamanho) >= 2)
            return 1;
    }

    return 0;
}

/* ==================================================
   FUNCAO PRINCIPAL
   ================================================== */

int main()
{
    srand(time(NULL));

    int menuJogador = -1;
    int quantidadeTerritorios;
    int indiceAtacante;
    int indiceDefensor;
    int tamanhoMissao;
    int indiceMissao;
    int resultado;
    int fimJogo = 0;

    char *listaMissoes[] = {
        "Conquiste 1 territorio inimigo",
        "Realize 3 ataques",
        "Conquiste o primeiro territorio do jogo",
        "Conquiste 2 territorios inimigos",
        "Controle 2 territorios com a mesma cor"};

    tamanhoMissao = sizeof(listaMissoes) / sizeof(listaMissoes[0]);

    printf("====================================\n");
    printf("            WAR - C\n");
    printf("      War... war never changes\n");
    printf("====================================\n");

    printf("\nQuantidade de territorios: ");
    scanf("%d", &quantidadeTerritorios);
    limparBuffer();

    Territorio *territorios = calloc(quantidadeTerritorios, sizeof(Territorio));
    cadastrarTerritorios(territorios, quantidadeTerritorios);

    for (int i = 0; i < quantidadeTerritorios; i++)
    {
        territorios[i].missaoAtual = calloc(100, sizeof(char));

        sortearMissao(territorios[i].missaoAtual, listaMissoes, tamanhoMissao);
    }

    do
    {
        printf("\n====================================\n");
        printf("               MENU\n");
        printf("====================================\n");
        printf("1 - Cadastrar territorios\n");
        printf("2 - Verificar missao\n");
        printf("3 - Atacar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &menuJogador);
        limparBuffer();

        switch (menuJogador)
        {
        case 1:
            cadastrarTerritorios(territorios, quantidadeTerritorios);
            break;

        case 2:
            printf("Escolha um territorio (1 a %d) para ver a missao: ", quantidadeTerritorios);
            scanf("%d", &indiceMissao);
            limparBuffer();

            if (indiceMissao >= 1 && indiceMissao <= quantidadeTerritorios)
            {
                exibirMissao(territorios[indiceMissao - 1].missaoAtual);

                resultado = verificarMissao(&territorios[indiceMissao - 1], territorios, quantidadeTerritorios);

                if (resultado == 1)
                {
                    printf("\nVITÓRIA! O território %s completou sua missão!\n", territorios[indiceMissao - 1].nome);
                    fimJogo = 1;
                }
                else
                {
                    printf("\nMissao ainda nao concluida.\n");
                }
            }

            break;

        case 3:
            printf("\n====================================");
            printf("\n         INICIAR ATAQUE");
            printf("\n====================================\n");

            printf("Escolha o territorio atacante: ");
            scanf("%d", &indiceAtacante);

            printf("Escolha o territorio defensor: ");
            scanf("%d", &indiceDefensor);
            limparBuffer();

            if (indiceAtacante < 1 || indiceAtacante > quantidadeTerritorios ||
                indiceDefensor < 1 || indiceDefensor > quantidadeTerritorios)
            {
                printf("Indice invalido!\n");
            }
            else if (indiceAtacante == indiceDefensor)
            {
                printf("Nao pode atacar o proprio territorio!\n");
            }
            else
            {
                ataque(&territorios[indiceAtacante - 1],
                       &territorios[indiceDefensor - 1]);

                exibirTerritorios(territorios, quantidadeTerritorios);
            }

            break;

        case 0:
            printf("\nSaindo do jogo...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
        }

    } while (menuJogador != 0 && fimJogo == 0);

    for (int i = 0; i < quantidadeTerritorios; i++)
    {
        free(territorios[i].missaoAtual);
    }

    free(territorios);

    return 0;
}