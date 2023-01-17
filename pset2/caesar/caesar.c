#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<cs50.h>

int main (int argc, string argv[]){
    int k;
    //1- Verifique se o programa foi executado com um argumento de linha de comando;
    if (argc != 2)
    {
        printf("Usage ./caesar key");
        return 1;
    }
    //2- Repita o argumento fornecido para garantir que todos os caracteres sejam dígitos;
    for (int i =0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))//"!" no começo é o mesmo que falsy
        {
            printf("Usage ./caesar key");
            return 1;
        }
    }
        //3- Converta o argumento da linha de comando de uma string para int
        k = atoi(argv[1]);

        //4- Solicite plaintext: (texto simples) ao usuário
        string str = get_string("plaintext:");
        printf("ciphertext:");

        //5- Repita/Itere para cada caractere do plaintext: (texto simples)
        for (int j = 0; j < strlen(str); j++)
        {
            /*1- Se é uma letra maiuscula, rotacione-a, preservando capitalização,
             e então imprima o caractere rotacionado*/
            if (isupper(str[j]))
            {
                //c i = (p i + k)% 26
                printf("%c", (str[j] + k - 65)%26 +65);
            }
            /*2- Se é uma letra minúscula, rotacione-a, preservando capitalização,
              e então imprima o caractere rotacionado*/
            else if (islower(str[j]))
            {
                //c i = (p i + k)% 26
                printf("%c", (str[j] + k - 97)%26 + 97);
            }
            /*3-  Se não for nenhum, imprima o caractere como está*/
            else
            {
                //c i = (p i + k)% 26
                printf("%c", str[j]);
            }
        }
        //6- Imprimir uma nova linha
        printf("\n");
    return 0;
}