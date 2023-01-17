#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int contLt(string x)
{
    int contl = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (isalpha(x[i]))
        {
            contl += 1;
        }
    }
    return contl;
}
int contPl(string x)
{
    int contP = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (isspace(x[i]))
        {
            contP += 1;
        }
    }
    return contP + 1;
}
int contFr(string x)
{
    int contF = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        if (ispunct(x[i]))
        {
            if (x[i] == '?' || x[i] == '!' || x[i] == '.')
            {
                contF += 1;
            }
            if (x[i-2] == '.' && x[i-1] == '.' && x[i] == '.')
            {
                contF -= 2;
            }
        }
    }
    return contF;
}

int main(void)
{

    int numl, numf, nump;
    float l, s, div, indice;
    string texto;

    texto = get_string("Insira o texto:\n");

    numl = contLt(texto);
    numf = contFr(texto);
    nump = contPl(texto);
    div = nump / 100.00;

    l = numl / div;
    s = numf / div;
    indice = ((0.0588 * l) - (0.296 * s) - 15.8);

    if (indice < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", indice);
    }
    return 0;
}
