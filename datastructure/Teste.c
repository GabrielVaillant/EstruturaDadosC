#include <stdio.h>
#include <stdlib.h>

int main_comentado()
{
    int i;
    char nome_cliente[30] = "Guilherme";
    char sexo= 'M';
    char cor_olhos='A';
    char altura[4]="1,89";
    char peso[5]="90,0";
    char dados_modelos[43];
    for(i=0; i<=31; i++)
    {
        dados_modelos[i+1]=nome_cliente[i];
    }
    
    fflush(stdout);
    dados_modelos[31]=sexo;
    dados_modelos[32]=cor_olhos;
    for(i=0; i<=3; i++)
    {
        dados_modelos[34+i]=altura[i];
    }
    for(i=0; i<=4; i++)
    {
        dados_modelos[39+i]=peso[i];
    }
    
    for (i=0; i<44; i++)
    {
        printf("Valor do elemento %d da string = %c\n",i, dados_modelos[i]);
    }
    
    
    
    return 0;
}
