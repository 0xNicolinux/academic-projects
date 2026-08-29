#include <stdio.h>
#include <wchar.h>
#include <locale.h>

// Função para exibir o nome do programa
void exibir_mensagem()
{
    printf("+-----------------------+\n");
    printf("|      Calculadora      |\n");
    printf("+-----------------------+\n");
}

// Função para exibir os operadores aritméticos
void exibir_operador()
{
    wprintf(L"\n[1] - Soma\n[2] - Subtração\n[3] - Multiplicação\n[4] - Divisão\n[0] - Sair do programa...\n");
}

// Função para limpar o buffer
void limpar_buffer()
{
    while (getchar() != '\n');
}

// Função para validar a entrada do usuário e limpar o buffer em caso de erros
float validar_entrada()
{
    float entrada;
    int status;
    do
    {
        status = scanf("%f", &entrada);

        if (status != 1)
        {
            wprintf(L"Entrada inválida! Apenas números são permitidos.\n");
            wprintf(L"Digite um valor numérico: ");
            limpar_buffer();
        }

    } while (status != 1);

    return entrada;
}

// Soma
float soma(float N1, float N2)
{
    float resultado = N1 + N2;
    printf("Resultado: %.2f\n", resultado);
    return resultado;
}

// Subtração
float subtracao(float N1, float N2)
{
    float resultado = N1 - N2;
    printf("Resultado: %.2f\n", resultado);
    return resultado;
}

// Multiplicação
float multiplicacao(float N1, float N2)
{
    float resultado = N1 * N2;
    printf("Resultado: %.2f\n", resultado);
    return resultado;
}

// Divisão
float divisao(float N1, float N2)
{
    // Caso o divisor seja igual a zero, exibe uma mensagem de erro
    if (N2 == 0)
    {
        wprintf(L"Nenhum número pode ser dividido por zero!\n");
        return 0;
    }

    float resultado = N1 / N2;
    printf("Resultado: %.2f\n", resultado);
    return resultado;
}

// Função Principal
int main()
{
    // Thanks, zwol! https://stackoverflow.com/questions/51791649/setlocale-not-working
    setlocale(LC_ALL, "");

    int operador;
    float x, y;
    exibir_mensagem();

    // Laço de repetição, continua enquanto for diferente de zero
    do
    {
        exibir_operador();
        wprintf(L"\nDigite o valor da operação desejada: ");
        scanf("%d", &operador);

        switch (operador)
        {
        case 1:
            printf("Digite o valor de x: ");
            x = validar_entrada();

            printf("Digite o valor de y: ");
            y = validar_entrada();

            soma(x, y);
            break;
        case 2:
            printf("Digite o valor de x: ");
            x = validar_entrada();

            printf("Digite o valor de y: ");
            y = validar_entrada();

            subtracao(x, y);
            break;
        case 3:
            printf("Digite o valor de x: ");
            x = validar_entrada();

            printf("Digite o valor de y: ");
            y = validar_entrada();

            multiplicacao(x, y);
            break;
        case 4:
            printf("Digite o valor de x: ");
            x = validar_entrada();

            printf("Digite o valor de y: ");
            y = validar_entrada();
            
            divisao(x, y);
            break;
        case 0:
            printf("\nSaindo do programa...\n");
            return 0;
        default:
            printf("Digite um valor válido!\n");
            break;
        }
    } while (operador != 0);

    return 0;
}
