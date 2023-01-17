#include<stdio.h>
#include<stdbool.h>
#include<math.h>
#include<cs50.h>

int main(void)
{

    int meuCaixa[4] = {25,10,5,1};
    int total = 0;
    int moedas;

    while(true)
    {

        float meuTroco = get_float("Digite seu troco: ");

        if (meuTroco < 0)
        {
            printf("\n");
            continue;
        }

        int centavos = round(meuTroco*100);

        for (int i = 0; i <= 3; i++)
        {
            while (centavos >= meuCaixa[i])
            {
                moedas = centavos / meuCaixa[i];
                centavos -= moedas*meuCaixa[i];
                total += moedas;
            }
        }

        break;
    }
    printf("%d\n",total);
    return 0;
}

