#include <stdlib.h>
#include "lista.h"


void inicializa_lista(Lista * ap_lista)
{
    *ap_lista = NULL;
}

void insere_fim(Lista *ap_lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    Lista *ap_recente = ap_lista;

    novo->valor = valor;
    novo->proximo = NULL;

    while (*ap_recente != NULL)
    {
        ap_recente = &((*ap_recente)->proximo);
    }

    *ap_recente = novo;
}

void insere_inicio(Lista * ap_lista, int valor)
{
    No *novo = (No*)malloc(sizeof(No)); //cria um no
    novo->valor=valor;
    novo->proximo= *ap_lista;
    *ap_lista=novo;
}

int remove_fim(Lista * ap_lista)
{
   int valor_ultimo;
    Lista *ap_recente = ap_lista;

    while((*ap_recente)->proximo != NULL)
    {
        ap_recente = &((*ap_recente)->proximo);
        
    }

    valor_ultimo=(*ap_recente)->valor;
    free(*ap_recente);
    *ap_recente=NULL;
    
    return valor_ultimo;
}

int remove_inicio(Lista * ap_lista)
{

      if (*ap_lista == NULL) {
        return;
    }

    int valor = (*ap_lista)->valor;
    Lista *segundo = (*ap_lista)->proximo;

    free(*ap_lista);
    *ap_lista = segundo;

    return valor;
}

int remove_ocorrencias(Lista *ap_lista, int valor)
{

    int contador = 0;
    if (!ap_lista)
        return contador;

    Lista *ap_atual = ap_lista;
    Lista remove;

    while ((*ap_atual)->proximo != NULL)
    {
        if ((*ap_atual)->valor == valor)
        {
            contador++;
            remove = *ap_atual;
            *ap_atual = (*ap_atual)->proximo;
            free(remove);
        }
        else
        {
            ap_atual = &((*ap_atual)->proximo);
        }
    }
    if ((*ap_atual)->valor == valor)
    {
        remove_fim(ap_lista);
        contador++;
    }
    return contador;
}

int busca(Lista lista, int valor)
{
    
    int posicao = 0;
    while (lista->proximo)
    {
        if (valor == lista->valor)
            return posicao;
        else{
            lista = lista->proximo;
            posicao=posicao+1;
        }
    }

    if (lista->proximo == NULL && lista->valor == valor)
        return posicao;
        
    

    return -1;
}

void imprime(Lista lista)
{
    printf("(");
     while(lista){
        if(lista->proximo != NULL)
        printf("%d, ", lista->valor);
        else
         printf("%d",lista->valor);

        lista= lista->proximo;
     }
    printf(")");
    
}

void desaloca_lista(Lista *ap_lista)
{
    Lista *ap_atual = *ap_lista;
    while (ap_atual != NULL) {
        Lista *temporario = (*ap_atual)->proximo;
        free(ap_atual);
        ap_atual = temporario;    
    }
    *ap_lista = NULL;
}



