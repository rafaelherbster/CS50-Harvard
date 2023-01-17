#include<stdio.h>
#include<cs50.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./ chave de substituição\n");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("A chave deve ter 26 caracteres.\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Chave for inválida por conter caractere  não alfabético.\n");
            return 1;
        }

       for (int j = 0; j < strlen(argv[1]); j++)
       {
            if (j == i){
                continue;
            }

            if (argv[1][j] ==  argv[1][i])
            {
                printf("Chave for inválida por conter caractere repetido.\n");
                return 1;
            }
       }
    }
    string str = get_string("plaintext:");
    printf("ciphertext:");

    for (int n = 0; n < strlen(str); n++)
    {
        if (!isalpha(str[n]))
        {
            printf("%c", str[n]);
        }
        else
        {
            if (isupper(str[n]))
            {
                int k = (int)str[n];
                if (k % 26 >= 13)
                {
                    printf("%c",toupper(argv[1][(k % 26) - 13]));
                }
                else if (k % 26 <=12)
                {
                    printf("%c", toupper(argv[1][(k % 26) + 13]));
                }
            }
            else if (islower(str[n]))
            {
                int k = (int)str[n];
                if (k % 26 >= 19)
                {
                    printf("%c",tolower(argv[1][(k % 26) - 19]));
                }
                else if (k % 26 <=18)
                {
                    printf("%c", tolower(argv[1][(k % 26) + 7]));
                }
            }
        }
    }
    printf("\n");
    return 0;
}
