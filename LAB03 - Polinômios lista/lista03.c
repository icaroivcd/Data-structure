#include <stdlib.h>
#include "polinomio.h"

void inicializa_polinomio(Polinomio * ap_pol) /* Inicializa um polinômio vazio. */
{
    No *novo = (No*)malloc(sizeof(No));

    *ap_pol = novo;

     novo->antec = novo;
     novo->prox = novo;
}

/* Define que o coeficiente de grau grau do polinomio pol eh igual a coef. Deve manter os 
 * coeficientes ordenados por grau. */
void define_coeficiente(Polinomio pol, int grau, int coef)
{
     if (grau >= 0 && coef != 0)
     {
         No *novo = (No *)malloc(sizeof(No));
         No *aux = pol->prox;

         novo->valor.grau = grau;
         novo->valor.coef = coef;

         while (novo->valor.grau > aux->valor.grau)
         {
             if (aux->prox == pol)
             {
                 novo->antec = pol->antec;
                 novo->prox = pol;
                 pol->antec->prox = novo;
                 pol->antec = novo;
                 return;
             }
             aux = aux->prox;
         }

         novo->prox = aux;
         novo->antec = aux->antec;
         aux->antec->prox = novo;
         aux->antec = novo;
     }
}

/* Zera o polinomio, tornando-o um polinomio inicializado, mas igual a zero. Desaloca a memória liberada. */
void zera(Polinomio pol)
{
    No *aux = pol->antec;

    while(aux != pol)
    {
        pol->antec = pol->antec->antec;
        free(aux);
        aux = pol->antec;
    }
    pol->prox = pol;
}

/* Computa a soma dos polinomios a e b colocando o resultado em res. 
 * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */
void soma(Polinomio res, Polinomio a, Polinomio b)
{

    zera(res);
    int soma_coeficiente;
    No *aux_a = a->prox;
    No *aux_b = b->prox;

    while (aux_a != a || aux_b != b)
    {
        if (aux_a->valor.grau == aux_b->valor.grau)
        {
        soma_coeficiente = aux_a->valor.coef + aux_b->valor.coef;
        if (soma_coeficiente != 0)
            define_coeficiente(res, aux_a->valor.grau, soma_coeficiente);

        aux_a = aux_a->prox;
        aux_b = aux_b->prox;
        }
        else if ((aux_a->valor.grau < aux_b->valor.grau) || (aux_b == b && aux_a != a))
        {
        define_coeficiente(res, aux_a->valor.grau, aux_a->valor.coef);
        aux_a = aux_a->prox;
        }
        else if ((aux_b->valor.grau < aux_a->valor.grau) || (aux_a == a && aux_b != b))
        {
        define_coeficiente(res, aux_b->valor.grau, aux_b->valor.coef);
        aux_b = aux_b->prox;
        }
    }
}

    /* Computa a subtracao dos polinomios a e b colocando o resultado em res.
     * Libera a memória anteriormente utilizada pelos nos descartados de res, e sobreescreve res. */

void subtrai(Polinomio res, Polinomio a, Polinomio b)
{
    zera(res);
    int subtrai_coeficiente;
    No *aux_a = a->prox;
    No *aux_b = b->prox;

    while (aux_a != a || aux_b != b)
    {
        if (aux_a->valor.grau == aux_b->valor.grau)
        {
        subtrai_coeficiente = aux_a->valor.coef - aux_b->valor.coef;
        if (subtrai_coeficiente != 0)
            define_coeficiente(res, aux_a->valor.grau, subtrai_coeficiente);

        aux_a = aux_a->prox;
        aux_b = aux_b->prox;
        }
        else if ((aux_a->valor.grau < aux_b->valor.grau) || (aux_b == b && aux_a != a))
        {
        define_coeficiente(res, aux_a->valor.grau, aux_a->valor.coef);
        aux_a = aux_a->prox;
        }
        else if ((aux_b->valor.grau < aux_a->valor.grau) || (aux_a == a && aux_b != b))
        {
        define_coeficiente(res, aux_b->valor.grau, -aux_b->valor.coef);
        aux_b = aux_b->prox;
        }
    }

} 

    /* Imprime o polinomio pol no formato do exemplo abaixo
     * [(0,2),(3,-2),(10,5)]
     * onde este polinomio tem 3 coeficientes, o de grau 0 com valor 2, o de grau 3 com valor -2 e o de
     * grau 10 com valor 5.
     */
    void imprime(Polinomio pol)
    {
        No *ap_atual = pol->prox;

        printf("[");

        while (pol != ap_atual)
        {
        printf("(%d,%d)", ap_atual->valor.grau, ap_atual->valor.coef);
        ap_atual = ap_atual->prox;
        if (ap_atual!= pol)
        printf(",");
        
        }

        printf("]\n");
}



/* Desaloca toda a memória alocada da lista.
 */
void desaloca_polinomio(Polinomio *ap_pol)
{
        No *aux = (*ap_pol)->antec;

        while (aux != (*ap_pol))
        {
        (*ap_pol)->antec = (*ap_pol)->antec->antec;
        free(aux);
        aux = (*ap_pol)->antec;
        }

        free(*ap_pol);

}
