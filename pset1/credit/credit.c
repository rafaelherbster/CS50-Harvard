#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<cs50.h>

int main(void)
{
    int soma = 0, dado1, dado2;
    char cc[256];
    //solicite ao usuário um número de cartão de crédito.
    long numCartao = get_long("Digite o numero do cartao: ");
    //sprintf permite que vc preencha um array com o valor de uma variavel qualquer.
    //sprintf(arg1,arg2,arg3) sendo arg1 o array a ser preenchido, arg2 o tipo da variavel e arg3 a variavel.
    sprintf(cc, "%ld", numCartao);

    //este laço vai passar pelo numero do cartão a partir do ultimo numero do cartao.
    //a leitura dos caracteres é feita da direita para a esquerda.
    //encerra o laço quando o indice i for menor que 0.
    for (int i = strlen(cc) - 1; i >= -1; i = i - 2){
        if (i >= 0){
            // coerção: força a mudando do tipo de variavel, no caso de char para int.
            dado1 = (int)cc[i] - '0';
            //soma cada um dos caracteres numerico pulando um numero
            soma += dado1;
        }
    }
    //este laço vai passar pelo numero do cartão a partir do penultimo numero do cartao.
    //a leitura dos caracteres é feita da direita para a esquerda.
    //encerra o laço quando o indice i for menor que 0.
    for (int i = strlen(cc) - 2; i >= -1; i = i - 2){
        if (i >= 0){
            //cada caractere desse laço sera multiplicado por 2.
            dado2 = ((int)cc[i] - '0') * 2;
            //se o resultado for maior que 9, some os algarismos.
            if (dado2 > 9)
            {
                int a = dado2/10;//dezena
                int b = dado2 - a * 10;//unidade
                dado2 = a + b;
            }
            //incremente o valor final obtido ao somatorio
            soma += dado2;
        }
    }
    //se o resto da divisao entre o somatorio e 10 for 0 e
    //o tamanho do num do cartao de credito estiver entre 13 e 16
    //identifique qual a marca do cartao.
    //as outras restrições de identificação estão no enunciado do exercicio.
    if (soma % 10 == 0 && (strlen(cc) >= 13 && strlen(cc) <= 16))
    {
        //se iniciar com digito 3
        if (cc[0] =='3')
        {
            for (int i = 0; i < 2; i++)
            {
                char listaA[2]={'4','7'};
                //se listaA contem o segundo digito
                if(cc[1] == listaA[i])
                {
                    printf("AMEX\n");
                    return 0;
                }
            }
        }
        //se iniciar com digito 4
        else if (cc[0] == '4')
        {
            printf("VISA\n");
            return 0;
        }
        //se iniciar com digito 5
        else if (cc[0] == '5')
        {
            for (int i = 0; i < 5; i++)
            {
                char listaM[5]={'1','2','3','4','5'};
                //se listaM contem o segundo digito
                if (cc[1] == listaM[i])
                {
                    printf("MASTERCARD\n");
                    return 0;
                }
            }
        }
        printf("INVALID\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}