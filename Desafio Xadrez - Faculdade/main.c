#include "stdio.h"

void Torre(int casas) {
    if (casas > 0)
    {
        printf("Direita!\n");
        Torre(casas - 1);
    }
}

void Bispo(int casas_vert, int casas_hor) {
    if (casas_vert > 0) {
        for (int j = 0; j < casas_hor; j++) {
            printf("Cima, Direita!\n");
        }
        Bispo(casas_vert - 1, casas_hor);
    }
}


void Rainha(int casas) {
    if (casas > 0)
    {
        printf("Esquerda!\n");
        Rainha(casas - 1);
    }

}


void Cavalo() {
    for (int movimento = 1; movimento <= 1; movimento++) {
        int cima = 0;
        while (cima < 2) {
            printf("Cima!\n");
            cima++;
        }
        for (int direita = 0; direita < 1; direita++) {
            printf("Direita!\n");
        }
    }
}


int main()
{   
    printf("Movimento da torre\n");
    Torre(5);
    printf("\n");
    printf("Movimento do bispo\n");
    Bispo(5,1);
    printf("\n");
    printf("Movimento da rainha\n");
    Rainha(8);
    printf("\n");
    printf("Movimento do cavalo\n");
    Cavalo();

    return 0;
}