#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

int main(void)
{
    int i, n, j;

    do
    {
        n = get_int("Digite a altura da escada: ");

    } while ( n < 1 || n > 8);

    for (i = 1; i <= n; i++){
        for (j = n - i; j >= 1; j--)
        {
            printf(" ");// imprime os espaços
        }
        for (j = 1; j <= i; j++)
        {
            printf("#");// imprime os '#'
        }
        printf("  ");
        for (j = 1; j <= i; j++)
        {
            printf("#");// imprime os '#'
        }
            printf("\n");
    }
}