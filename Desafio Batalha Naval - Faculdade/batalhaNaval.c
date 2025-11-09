#include <stdio.h>

int main()
{
    // Declarando variáveis
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // Cria a coluna horizontal do tabuleiro
    int linhas[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                      // Cria a linha vertical do tabuleiro
    int tabuleiro[10][10] = {0};                                           // Cria uma matriz 10x10 e preenche com zeros

    int navio1_pos_linha = 0, navio2_pos_linha = 0, navio3_pos_linha = 0, navio4_pos_linha = 1;     // Posição em y do navio
    int navio1_pos_coluna = 0, navio2_pos_coluna = 4, navio3_pos_coluna = 6, navio4_pos_coluna = 2; // Posição em x do navio

    int cone_pos_linha = 4, cruz_pos_linha = 8, octaedro_pos_linha = 8;    // Posição em y das habilidades
    int cone_pos_coluna = 2, cruz_pos_coluna = 2, octaedro_pos_coluna = 7; // Posição em x das habilidades

    int valor_navio = 3;        // Tamanho do navio
    int colisao_horizontal = 0; // Alerta de colisão
    int colisao_vertical = 0;   // Alerta de colisão
    int colisao_diagonal_p = 0; // Alerta de colisão na diagonal primária
    int colisao_diagonal_s = 0; // Alerta de colisão na diagonal secundária

    int centro_linha_cone = 3 / 2;  // Centro y da matriz do cone
    int centro_coluna_cone = 5 / 2; // Centro x da matriz do cone

    int centro_linha_cruz = 3 / 2;  // Centro y da matriz da cruz
    int centro_coluna_cruz = 5 / 2; // Centro x da matriz da cruz

    int centro_linha_octaedro = 3 / 2;  // Centro y da matriz do octaedro
    int centro_coluna_octaedro = 5 / 2; // Centro x da matriz do octaedro

    // Apresentando o jogo
    printf("==================================\n");
    printf("     || BATALHA NAVAL EM C ||\n");
    printf("==================================\n\n");
    printf(" #"); // Espaço necessário para alinhar corretamente no terminal

    // =====================================================================================================================================
    // Navio horizontal
    // 1. Verifica se o navio ultrapassa os limites do tabuleiro (colunas)
    // 2. Verifica se há colisão com outros navios
    // 3. Se não houver problemas, posiciona o navio no tabuleiro (valor 3)
    if (navio1_pos_coluna + valor_navio > 10)
    {
        printf("Navio horizontal esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            if (tabuleiro[navio1_pos_linha][navio1_pos_coluna + i] != 0)
            {
                colisao_horizontal = 1;
                break;
            }
        }
    }

    if (colisao_horizontal)
    {
        printf("Colisao horizontal!");
    }
    else
    {

        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio1_pos_linha][navio1_pos_coluna + i] = 3;
        }
    }

    // =====================================================================================================================================
    // Navio vertical
    // 1. Verifica se o navio ultrapassa os limites do tabuleiro (colunas)
    // 2. Verifica se há colisão com outros navios
    // 3. Se não houver problemas, posiciona o navio no tabuleiro (valor 3)
    if (navio2_pos_linha + valor_navio > 10)
    {
        printf("Navio vertical esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            if (tabuleiro[navio2_pos_linha + i][navio2_pos_coluna] != 0)
            {
                colisao_vertical = 1;
                break;
            }
        }
    }

    if (colisao_vertical)
    {
        printf("Colisao vertical!");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio2_pos_linha + i][navio2_pos_coluna] = 3;
        }
    }

    // =====================================================================================================================================
    // Navio diagonal primário
    // 1. Verifica se o navio ultrapassa os limites do tabuleiro (colunas)
    // 2. Verifica se há colisão com outros navios
    // 3. Se não houver problemas, posiciona o navio no tabuleiro (valor 3)
    if (navio3_pos_linha + valor_navio > 10 || navio3_pos_coluna + valor_navio > 10)
    {
        printf("Navio diagonal primario esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            if (tabuleiro[navio3_pos_linha + i][navio3_pos_coluna + i] != 0)
            {
                colisao_diagonal_p = 1;
                break;
            }
        }
    }

    if (colisao_diagonal_p)
    {
        printf("Colisao diagonal primaria!");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio3_pos_linha + i][navio3_pos_coluna + i] = 3;
        }
    }

    // =====================================================================================================================================
    // Navio diagonal secundário
    // 1. Verifica se o navio ultrapassa os limites do tabuleiro (colunas)
    // 2. Verifica se há colisão com outros navios
    // 3. Se não houver problemas, posiciona o navio no tabuleiro (valor 3)
    if (navio4_pos_linha + valor_navio > 10 || navio4_pos_coluna - (valor_navio - 1) < 0)
    {
        printf("Navio diagonal secundario esta fora dos limites do tabuleiro.\n");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            if (tabuleiro[navio4_pos_linha + i][navio4_pos_coluna - i] != 0)
            {
                colisao_diagonal_s = 1;
                break;
            }
        }
    }

    if (colisao_diagonal_s)
    {
        printf("Colisao diagonal secundario!");
    }
    else
    {
        for (int i = 0; i < valor_navio; i++)
        {
            tabuleiro[navio4_pos_linha + i][navio4_pos_coluna - i] = 3;
        }
    }

    // =====================================================================================================================================
    // Habilidades
    // Área afetada = 1
    // Água = 0

    int cone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}};

    int cruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}};

    int octaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}};

    // =====================================================================================================================================
    // Cone - percorre a matriz de efeito do cone (3x5).
    // Para cada célula com valor 1 (área afetada), calcula o deslocamento relativo ao centro da matriz
    // e posiciona no tabuleiro como 5, representando a área de efeito. Garante que não saia dos limites do tabuleiro.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cone[i][j] == 1)
            {
                int deslocamento_linha = i - centro_linha_cone;
                int deslocamento_coluna = j - centro_coluna_cone;

                int linha_tabuleiro = cone_pos_linha + deslocamento_linha;
                int coluna_tabuleiro = cone_pos_coluna + deslocamento_coluna;

                if (linha_tabuleiro >= 0 && linha_tabuleiro < 10 &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < 10)
                {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
                }
            }
        }
    }

    // =====================================================================================================================================
    // Cruz - percorre a matriz de efeito da cruz (3x5).
    // Para cada célula com valor 1 (área afetada), calcula o deslocamento relativo ao centro da matriz
    // e posiciona no tabuleiro como 6, representando a área de efeito. Garante que não saia dos limites do tabuleiro.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (cruz[i][j] == 1)
            {
                int deslocamento_linha = i - centro_linha_cruz;
                int deslocamento_coluna = j - centro_coluna_cruz;

                int linha_tabuleiro = cruz_pos_linha + deslocamento_linha;
                int coluna_tabuleiro = cruz_pos_coluna + deslocamento_coluna;

                if (linha_tabuleiro >= 0 && linha_tabuleiro < 10 &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < 10)
                {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 6;
                }
            }
        }
    }

    // =====================================================================================================================================
    // Octaedro - percorre a matriz de efeito do octaedro (3x5).
    // Para cada célula com valor 1 (área afetada), calcula o deslocamento relativo ao centro da matriz
    // e posiciona no tabuleiro como 7, representando a área de efeito. Garante que não saia dos limites do tabuleiro.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (octaedro[i][j] == 1)
            {
                int deslocamento_linha = i - centro_linha_octaedro;
                int deslocamento_coluna = j - centro_coluna_octaedro;

                int linha_tabuleiro = octaedro_pos_linha + deslocamento_linha;
                int coluna_tabuleiro = octaedro_pos_coluna + deslocamento_coluna;

                if (linha_tabuleiro >= 0 && linha_tabuleiro < 10 &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < 10)
                {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 7;
                }
            }
        }
    }

    // =====================================================================================================================================
    // Inicia criando o cabeçalho (Colunas)
    for (int i = 0; i < 10; i++)
    {
        printf(" %c", colunas[i]);
    }

    // Após criar as colunas, o programa irá pular uma linha e criará as linhas verticais, e em seguida o tabuleiro preenchido com os zeros
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d", linhas[i]);
        for (int j = 0; j < 10; j++)
        {
            printf("%2d", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}