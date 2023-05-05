#include <stdio.h>
#include<stdlib.h>

const int UM = 1;
void subconjunto(int V[], int qtd_sub );
int uniao(int mA, int mB);
int intersec(int mA, int mB);
void AchaConjunto(int Vet[], int qtd_sub, int procurado);
void imprime(int unitario[], int qtd_conj);

int main(){

  int i,n,qtd_sub;
  
  scanf("%d", &n);
  scanf("%d", &qtd_sub);

  int Vetor[qtd_sub];
  subconjunto(Vetor, qtd_sub);


  int procurado =0;

  for(i=0;i<n;i++)
    procurado = procurado | (UM<<i);
  
  AchaConjunto(Vetor,qtd_sub,procurado);
  
}
void subconjunto(int V[], int qtd_sub )
{
    int qtd_num,num;
    int mask = 0;
    int i;
   for(i=0; i<qtd_sub;i++)
      { 

        scanf("%d", &qtd_num);

        for(int j=0;j<qtd_num;j++)
        {
           scanf("%d",&num);
          mask = mask|(UM <<num);
        }
        V[i] = mask;
        mask = 0;
      }
}

int uniao(int mA, int mB)
{
    return mA | mB;
}

int intersec(int mA, int mB)
{
    return mA & mB;
}

void AchaConjunto(int Vet[], int qtd_sub, int procurado)
{
    int i,j,resultado;
    int unitario[qtd_sub];
    int qtd_conj=0;

    for(j=0;j<(1<<qtd_sub);j++)
    {
      resultado=0;
      for(i=0; i<qtd_sub;i++)
      {
        if(j & (1<<i) && (intersec(resultado,Vet[i]))==0)
        {
          resultado = uniao(resultado, Vet[i]);
          unitario[qtd_conj]=Vet[i];
          qtd_conj++;
        }
      }
     
      if(procurado == resultado)
      {
        
        imprime(unitario, qtd_conj);
        return; 
      }
      qtd_conj = 0;
    }
    
    printf("Insoluvel");
}


void imprime(int unitario[], int qtd_conj)
{

    printf("%d\n",qtd_conj);

    int cont=0;
    int i, j;

    for(i=0; i<qtd_conj;i++)
    {
      for(j=0;j<15;j++)
      {
        if(unitario[i] & (UM<<j))
        cont++;
      }
      printf("%d ",cont);
      cont=0;

      for(j=0; j<15;j++)
      {
        if(unitario[i] & (UM<<j))
        printf("%d ",j);
      }  

      
      printf("\n");

    }
}






