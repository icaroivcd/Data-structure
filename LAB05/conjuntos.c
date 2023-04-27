#include <stdio.h>

const int UM = 1;
void subconjunto(int *V, int qtd_sub );

int main(){

  int i,n,qtd_sub;
  

  scanf("%d", &n);
  scanf("%d", &qtd_sub);

  int Vetor[qtd_sub];
  subconjunto(&Vetor, qtd_sub);


      for(i=0; i<qtd_sub; i++)
      {
        printf("%d ", Vetor[i]);
      }

}
  void subconjunto(int *V, int qtd_sub )
{
    int qtd_num,num;
    int mask = 0;
    int i;
   for(i=0; i<qtd_sub;i++)
      { 

        printf("Quantidade de números no conjunto: ");
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