#include<stdio.h>
#include<cs50.h>

int main (void)
{
    string name = get_string("Qual seu nome?");
    printf("Hello %s",name);

    return 0;
}