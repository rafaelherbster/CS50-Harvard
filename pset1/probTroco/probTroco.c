#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void){

    int meuCaixa[] = {100,50,20,10,5,2,1};
    int meuTroco;
    int total;

    printf("Digite o valor do troco: ");
    scanf("%d", &meuTroco);

    for (int i = 0; i <= 6; i++){
        while(meuTroco>=meuCaixa[i]){
            int moedas = meuTroco/meuCaixa[i];
            meuTroco -= meuCaixa[i];
            if (meuTroco < 0){
                exit(0);
            }
            if (moedas > 0){
                total = meuCaixa[i];
                printf("%d, ",total);
            }
        }
    }printf("\n");


}
