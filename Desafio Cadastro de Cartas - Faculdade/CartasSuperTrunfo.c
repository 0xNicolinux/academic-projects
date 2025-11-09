#include <stdio.h>

// Desafio Super Trunfo - Países

// Tema 1 - Cadastro das cartas

// Objetivo 1: Criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações. (Feito!)

// Objetivo 2: Lógica para calcular e exibir duas novas propriedades importantes para cada cidade: a densidade populacional e o PIB per capita. (Feito!)

// Objetivo 3: Lógica de comparação entre duas cartas do Super Trunfo, determinando a vencedora de cada atributo e introduzindo o conceito de "Super Poder". (Feito!)

int main()
{
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char estado1; // Letra do estado 1 (ex: 'A')
  char estado2; // Letra do estado 2 (ex: 'B')

  char nome_cidade1[100]; // Nome da cidade 1 (ex: "São Paulo")
  char nome_cidade2[100]; // Nome da cidade 2 (ex: "Campinas")

  char codigo_cidade1[3]; // Código da cidade 1 (ex: "A1")
  char codigo_cidade2[3]; // Código da cidade 2 (ex: "B2")

  unsigned long int populacao1; // População da cidade 1
  unsigned long int populacao2; // População da cidade 2
  int pontos1;    // Pontos da cidade 1
  int pontos2;    // Pontos da cidade 2

  int resultado_populacao; // Armazenar resultado 
  int resultado_area; // Armazenar resultado
  int resultado_pib; // Armazenar resultado
  int resultado_pontos; // Armazenar resultado
  int resultado_densidade; // Armazenar resultado
  int resultado_pibcapita; // Armazenar resultado
  int resultado_super; // Armazenar resultado

  float area1; // Área da cidade 1
  float area2; // Área da cidade 2
  float pib1; // PIB da cidade 1
  float pib2; // PIB da cidade 2
  float densidade1; // Densidade populacional da cidade 1
  float densidade2; // Densidade populacional da cidade 2
  float pib_capita1; // PIB per capita da cidade 1
  float pib_capita2; // PIB per capita da cidade 2
  float super_poder1; // Super poder da carta 1
  float super_poder2; // Super poder da carta 2

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

  //Cálculo da carta 1
  densidade1 = populacao1 / area1;
  pib_capita1 = pib1 / populacao1;
  super_poder1 = populacao1 + area1 + pib1 + pontos1 + pib_capita1 + 1 / densidade1;

  // Área para entrada de dados da carta 2
  printf("\n=== Segunda Carta ===\n");

  printf("Digite o estado (A até H): ");
  scanf(" %c", &estado2);

  printf("Digite o código da cidade (1 até 4): ");
  scanf(" %2s", codigo_cidade2);

  printf(
    "Digite o nome da cidade: ");
  scanf(" %s", nome_cidade2);

  printf("Digite a população da cidade: ");
  scanf("%lu", &populacao2);

  printf("Digite a área da cidade em km²: ");
  scanf("%f", &area2);

  printf("Digite o PIB da cidade: ");
  scanf("%f", &pib2);

  printf("Digite a quantidade de pontos turísticos: ");
  scanf("%i", &pontos2);

  //Cálculo da carta 2
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

  printf("\n================================\n");
  
  // Início da "batalha" e começando a comparar atributos/propriedades 

  printf("\nComparação de cartas:\n");
  printf("Resultado 1 = Carta 1 venceu.\n");
  printf("Resultado 0 = Carta 2 venceu.\n");

  resultado_populacao = populacao1 > populacao2;
  resultado_area = area1 > area2;
  resultado_pib = pib1 > pib2;
  resultado_pontos = pontos1 > pontos2;
  resultado_densidade = densidade1 < densidade2;
  resultado_pibcapita = pib_capita1 > pib_capita2;
  resultado_super = super_poder1 > super_poder2;

  printf("\nPopulação: %d\n", resultado_populacao);
  printf("Área: %d\n", resultado_area);
  printf("PIB: %d\n", resultado_pib);
  printf("Pontos turísticos: %d\n", resultado_pontos);
  printf("Densidade populacional: %d\n", resultado_densidade);
  printf("PIB per capita: %d\n", resultado_pibcapita);
  printf("Super poder: %d\n", resultado_super);

  printf("\n================================\n");

  return 0;
}