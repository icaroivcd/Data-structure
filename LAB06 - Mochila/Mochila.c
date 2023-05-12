#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int peso;
    int valor;
}Peso_Valor;

int encontra_valor(int tam_vetor, int peso_max, Peso_Valor Vetor[]);
int Verifica(int C1,int C2);

int main()
{
    int tam_vetor;
    int peso_max;
    int i;
    scanf("%d%d",&tam_vetor,&peso_max);

    Peso_Valor *Vetor = malloc(tam_vetor * sizeof(Peso_Valor));

    for(i=0;i<tam_vetor;i++)
        scanf("%d%d",&Vetor[i].peso,&Vetor[i].valor);

   printf("%d\n", encontra_valor(tam_vetor, peso_max, Vetor));
}



int encontra_valor(int tam_vetor, int peso_max, Peso_Valor Vetor[]){
    
    if(tam_vetor == 0)
        return 0;
      
    if(Vetor[tam_vetor-1].peso > peso_max){
        return encontra_valor(tam_vetor-1, peso_max, Vetor);
    }else{
         return Verifica((Vetor[tam_vetor-1].valor + encontra_valor(tam_vetor-1, peso_max - Vetor[tam_vetor-1].peso, Vetor)), encontra_valor(tam_vetor-1, peso_max, Vetor));
        }
}
    
int Verifica(int C1,int C2)
{
    if(C1 > C2){
        return C1;
    }
    else{
        return C2;
    }
    
} 

  
