#include <stdio.h>

typedef struct{
    int peso;
    int valor;
}Peso_Valor;


int main()
{
    int tam_vetor;
    int peso_max;
    int i;
    scanf("%d%d",&tam_vetor,&peso_max);

    Peso_Valor *Vetor = (Peso_Valor*)malloc(tam_vetor * sizeof(Peso_Valor));

    for(i=0;i<tam_vetor;i++)
        scanf("%d%d",&Vetor[i].peso,&Vetor[i].valor);

   for(i=0;i<tam_vetor;i++){
   printf("%d ",Vetor[i].peso);
   printf("%d\n",Vetor[i].valor);
}
}


int encontra_valor(int Vetor[],int tam_vetor,int peso_max){

    int soma_peso, soma_valor;

    if(peso_max != 0)
        return 0;
    else{
        for(int i=0; i<tam_veto)

    }


