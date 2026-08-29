#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM_CPF 11

void gerarNumero(int cpf[TAM_CPF])
{
    for (int i = 0; i < 9; i++)
    {
        cpf[i] = rand() % 10;
    }
}

void primeiroDigito(int cpf[TAM_CPF])
{
    int soma = 0;

    for (int i = 0, peso = 10; i < 9; i++, peso--)
    {
        soma += cpf[i] * peso;
    }

    int resto = (soma * 10) % 11;

    cpf[9] = (resto == 10) ? 0 : resto;
}

void segundoDigito(int cpf[TAM_CPF])
{
    int soma = 0;

    for (int i = 0, peso = 11; i < 10; i++, peso--)
    {
        soma += cpf[i] * peso;
    }

    int resto = (soma * 10) % 11;

    cpf[10] = (resto == 10) ? 0 : resto;

}

void imprimirNumero(int cpf[TAM_CPF])
{
    for (int i = 0; i < 11; i++)
    {
        printf("%d", cpf[i]);
        
        if (i == 2 || i == 5)
        {
            printf(".");
        }
        else if (i == 8)
        {
            printf("-");
        }
    }
}

void gerarCpfCompleto(int cpf[TAM_CPF])
{
    gerarNumero(cpf);    
    primeiroDigito(cpf); 
    segundoDigito(cpf);  
    imprimirNumero(cpf);
}

int main(void)
{
    srand(time(NULL));
    int cpf[TAM_CPF];

    printf("CPF Gerado: ");
    gerarCpfCompleto(cpf);
    printf("\n");

    return 0;
}