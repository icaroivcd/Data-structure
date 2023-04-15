#include <stdio.h>

int soma_divisores(int a)
{
    int contador,soma=0;

    for(contador=1;contador<a;contador++)
    {
       if((acontador==0))
          soma=soma+contador;
    }

    return soma;


}

int amigos(int a, int b)
{
   int resultado;

    resultado = soma_divisores(a);

    if(resultado == b)
    return 1;

    return 0;

}

int main()
{

  int num1, num2;

  printf("Digite os numeros: ");
  scanf("%d",&num1);
  scanf("%d",&num2);


  soma_divisores(num1);

    amigos(num1,num2);

    if(amigos(num1,num2)==0)
    {
        printf("nao amigos\n");
    }
    else
    {
        printf("amigos");
    }







  return 0;
}
