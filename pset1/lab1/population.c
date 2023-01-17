#include<stdio.h>
#include<cs50.h>

int main(void){

    int ano = 0, acres, decres, inicial, final;

    // TODO: Solicite o valor inicial ao usuário maior ou igual a 9
    do
    {
        inicial = get_int("Digite o valor inicial da população: ");
    } while (inicial < 9);

     // TODO: Solicite o valor final ao usuário maior que o inicial
     do
     {
        final = get_int("Digite o valor final da população: ");
     } while (final < inicial);

     // TODO: Calcule o número de anos até o limite
     // restrição para inicio e final com mesmos valores
     if (inicial != final)
     {
        do
        {
            acres = (inicial/3);
            decres = (inicial/4);
            inicial = inicial + acres - decres;
            ano += 1;

        } while (inicial < final);

        // TODO: Imprima o número de anos
        printf("Years: %i", ano);
     }
     else
     {
        printf("Years: 0");
     }

    return 0;
}