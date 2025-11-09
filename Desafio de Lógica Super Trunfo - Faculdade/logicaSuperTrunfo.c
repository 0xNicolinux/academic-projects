#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 3 - Lógica de comparação das Cartas

int main()
{
    // Área para definição das variáveis para armazenar as propriedades das cidades
    char estado1, estado2;
    char nome_cidade1[100], nome_cidade2[100];
    char codigo_cidade1[3], codigo_cidade2[3];

    char *menu[] = {
        "[1] - População",
        "[2] - Área",
        "[3] - PIB",
        "[4] - Pontos turísticos",
        "[5] - Densidade populacional",
        "[6] - PIB per capita",
        "[7] - Super poder",
        "[8] - Sair"};

    unsigned long int populacao1, populacao2;
    int pontos1, pontos2;
    int escolha_jogador1, escolha_jogador2;
    int tamanho_menu = 8;

    float area1, area2, pib1, pib2;
    float densidade1, densidade2, pib_capita1, pib_capita2, super_poder1, super_poder2;

    float valor1_attr1, valor2_attr1;
    float valor1_attr2, valor2_attr2;
    float soma1, soma2;

    int vencedor1, vencedor2;

    // Apresentação do jogo
    printf("\nBem-vindo ao jogo Super Trunfo!\n");
    printf("Para começar, preencha todos os dados solicitados para criar suas cartas.\n");

    // Exemplo ilustrativo para orientar o usuário
    printf(
        "\nExemplo de preenchimento de carta:\n"
        "-----------------------------------\n"
        "Estado: C\n"
        "Código: C01\n"
        "Nome da cidade: Fortaleza\n"
        "População: 180000\n"
        "Área: 155000 \n"
        "PIB: 310000\n"
        "Número de pontos turísticos: 5\n"
        "-----------------------------------\n"
        "Pronto! Agora é só jogar!\n");
    printf("\n=============================\n");

    // Área para entrada de dados da carta 1
    printf("\n=== Primeira Carta ===\n");

    printf("Digite o estado (A até H): ");
    scanf(" %c", &estado1);

    printf("Digite o código da cidade (1 até 4): ");
    scanf(" %2s", codigo_cidade1);

    printf("Digite o nome da cidade: ");
    scanf(" %s", nome_cidade1);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao1);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &area1);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib1);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%i", &pontos1);

    // Cálculo da carta 1
    densidade1 = populacao1 / area1;
    pib_capita1 = pib1 / populacao1;
    super_poder1 = populacao1 + area1 + pib1 + pontos1 + pib_capita1 + 1 / densidade1;

    // Área para entrada de dados da carta 2
    printf("\n=== Segunda Carta ===\n");

    printf("Digite o estado (A até H): ");
    scanf(" %c", &estado2);

    printf("Digite o código da cidade (1 até 4): ");
    scanf(" %2s", codigo_cidade2);

    printf("Digite o nome da cidade: ");
    scanf(" %s", nome_cidade2);

    printf("Digite a população da cidade: ");
    scanf("%lu", &populacao2);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &area2);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib2);

    printf("Digite a quantidade de pontos turísticos: ");
    scanf("%i", &pontos2);

    // Cálculo da carta 2
    densidade2 = populacao2 / area2;
    pib_capita2 = pib2 / populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos2 + pib_capita2 + 1 / densidade2;

    printf("\n === Cadastro concluído! ===\n");

    // Exibição carta 1
    printf("\n=== Dados da Carta 1 ===\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %c%s\n", estado1, codigo_cidade1);
    printf("Cidade: %s\n", nome_cidade1);
    printf("População: %lu Habitantes\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f Bilhões de reais\n", pib1);
    printf("Pontos turísticos: %d\n", pontos1);
    printf("Densidade populacional: %f\n", densidade1);
    printf("PIB per capita: %f\n", pib_capita1);
    printf("Super poder: %f\n", super_poder1);

    // Exibição carta 2
    printf("\n=== Dados da Carta 2 ===\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %c%s\n", estado2, codigo_cidade2);
    printf("Cidade: %s\n", nome_cidade2);
    printf("População: %lu Habitantes\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f Bilhões de reais\n", pib2);
    printf("Pontos turísticos: %d\n", pontos2);
    printf("Densidade populacional: %f\n", densidade2);
    printf("PIB per capita: %f\n", pib_capita2);
    printf("Super poder: %f\n", super_poder2);

    printf("\n=========================================\n");

    // Início da "batalha"
    do
    {
        printf("\nPrepare-se para a batalha!\n");
        printf("Quais atributos você deseja comparar?\n");

        // Mostrar menu completo para jogador 1
        for (int i = 0; i < tamanho_menu; i++)
        {
            printf("%s\n", menu[i]);
        }

        // Escolha jogador 1
        printf("\nDigite o número do primeiro atributo: ");
        scanf("%d", &escolha_jogador1);

        // Mostrar menu para jogador 2 removendo a escolha do jogador 1
        printf("\nEscolha o segundo atributo (opção %d já escolhida):\n", escolha_jogador1);
        for (int i = 0; i < tamanho_menu; i++)
        {
            if (i + 1 != escolha_jogador1)
            { // pula o atributo já escolhido
                printf("%s\n", menu[i]);
            }
        }

        // Escolha jogador 2
        printf("\nDigite o número do segundo atributo: ");
        scanf("%d", &escolha_jogador2);

        // Ajuste: se o jogador 2 digitou a opção do jogador 1, tratar erro
        if (escolha_jogador2 == escolha_jogador1)
        {
            printf("Você não pode escolher o mesmo atributo!\n");
        }
        else
        {
            printf("\n================== RESULTADO ==================\n");
            printf("Carta 1 x Carta 2\n");
            printf("Atributos escolhidos:\n");
            printf("Jogador 1: %s\n", menu[escolha_jogador1 - 1]);
            printf("Jogador 2: %s\n", menu[escolha_jogador2 - 1]);

            switch (escolha_jogador1)
            {
            case 1:
                valor1_attr1 = populacao1;
                valor2_attr1 = populacao2;
                break;
            case 2:
                valor1_attr1 = area1;
                valor2_attr1 = area2;
                break;
            case 3:
                valor1_attr1 = pib1;
                valor2_attr1 = pib2;
                break;
            case 4:
                valor1_attr1 = pontos1;
                valor2_attr1 = pontos2;
                break;
            case 5:
                valor1_attr1 = densidade1;
                valor2_attr1 = densidade2;
                break;
            case 6:
                valor1_attr1 = pib_capita1;
                valor2_attr1 = pib_capita2;
                break;
            case 7:
                valor1_attr1 = super_poder1;
                valor2_attr1 = super_poder2;
                break;
            }

            switch (escolha_jogador2)
            {
            case 1:
                valor1_attr2 = populacao1;
                valor2_attr2 = populacao2;
                break;
            case 2:
                valor1_attr2 = area1;
                valor2_attr2 = area2;
                break;
            case 3:
                valor1_attr2 = pib1;
                valor2_attr2 = pib2;
                break;
            case 4:
                valor1_attr2 = pontos1;
                valor2_attr2 = pontos2;
                break;
            case 5:
                valor1_attr2 = densidade1;
                valor2_attr2 = densidade2;
                break;
            case 6:
                valor1_attr2 = pib_capita1;
                valor2_attr2 = pib_capita2;
                break;
            case 7:
                valor1_attr2 = super_poder1;
                valor2_attr2 = super_poder2;
                break;
            }

            // Calcular soma
            soma1 = valor1_attr1 + valor1_attr2;
            soma2 = valor2_attr1 + valor2_attr2;

            // Mostrar valores individuais e soma
            printf("\nAtributo 1: %.2f x %.2f\n", valor1_attr1, valor2_attr1);
            printf("Atributo 2: %.2f x %.2f\n", valor1_attr2, valor2_attr2);
            printf("Soma dos atributos:\nCarta 1 = %.2f\nCarta 2 = %.2f\n", soma1, soma2);

            // Decidir vencedor
            (soma1 > soma2) ? printf("Carta 1 venceu!\n") : ((soma1 < soma2) ? printf("Carta 2 venceu!\n") : printf("Empate!\n"));
        }

        // O menu continua enquanto nenhum jogador escolher 8 (sair)
    } while (escolha_jogador1 != 8 && escolha_jogador2 != 8);

    printf("\n=========================================\n");

return 0;
}