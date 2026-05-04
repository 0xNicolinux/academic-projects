#include <stdio.h>

void ex1() {
    int x = 15;
    int *ponteiro = &x;

    printf("%d\n", x);
    printf("%p\n", &x);
    printf("%p\n", ponteiro);
    printf("%d\n", *ponteiro);
}

void ex2() {
    int v[3] = {10, 20, 30};
    int *p = v;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(p + i));
    }
    
}

void ex3() {
    int v[3] = {10, 20, 30};
    int *p = v;

    for (int i = 0; i < 3; i++)
    {
        printf("%d\n", *(p + i) = *(p + i) * 2);
    }

}

int main() {
   //ex1();
   //ex2();
   ex3();

    return 0;
}