#include <stdio.h>
#include <stdlib.h>

typedef struct aux
{
  int valor;
  struct aux *prox;
  struct aux *antec;
} No;

typedef No *Lista; // lista de dentro

typedef struct
{
  int vertice, aresta;
  Lista *adj; // lista dos vértices
} Grafo;

void *inicializa_lista(int vertice);
void cria_grafo(Lista *adj, int vertice1, int vertice2);
int menor_caminho(Grafo G, Lista *ap_fila, int inicio, int fim);
void insere_inicio_fila(Lista ap_fila, int valor);
int remove_fim_fila(Lista ap_fila);

int main()
{

  Grafo L;
  int Vert1, Vert2;
  int inicio, fim;
  int dist;

  
  scanf("%d%d", &L.vertice, &L.aresta);

  L.adj = inicializa_lista(L.vertice);

  for (int i = 0; i < L.aresta; i++)
  {
    scanf("%d%d", &Vert1, &Vert2);
    cria_grafo(L.adj, Vert1, Vert2);
  }

  scanf("%d%d", &inicio, &fim);

  Lista fila;
  dist = menor_caminho(L, &fila, inicio, fim);

  if(dist == 0)
      printf("infinito");
  else  
    printf("%.f", (float)dist);

}

void *inicializa_lista(int vertices) // inicializa os vertices
{

  Lista *ap_lista = (Lista *)malloc(vertices * sizeof(Lista));
  for (int i = 0; i < vertices; i++)
    ap_lista[i] = NULL;

  return ap_lista;
}

void cria_grafo(Lista *adj, int vertice1, int vertice2) // aloca valor aos vertices
{
  No *vizinho_1 = (No *)malloc(sizeof(No));

  vizinho_1->valor = vertice2;
  vizinho_1->prox = adj[vertice1];
  adj[vertice1] = vizinho_1;

  No *vizinho_2 = (No *)malloc(sizeof(No));

  vizinho_2->valor = vertice1;
  vizinho_2->prox = adj[vertice2];
  adj[vertice2] = vizinho_2;
}

int menor_caminho(Grafo G, Lista *ap_fila, int inicio, int fim)
{
  No *no_cabeca = (No *)malloc(sizeof(No));
  *ap_fila = no_cabeca;
  no_cabeca->prox = no_cabeca;
  no_cabeca->antec = no_cabeca;

  int i, remove, vizinho;

  int distancia[G.vertice];
  int cor[G.vertice];

  for (i = 0; i < G.vertice; i++)
    distancia[i] = 0;

  for (i = 0; i < G.vertice; i++)
  {
    if (inicio == i)
      cor[i] = 1; // 1 - visitado

    else
      cor[i] = 0; // 0 - não visitado
  }

  No *novo = (No *)malloc(sizeof(No));
  novo->valor = inicio;
  novo->prox = no_cabeca;
  novo->antec = no_cabeca;
  no_cabeca->antec = novo;
  no_cabeca->prox = novo;

  while (no_cabeca->prox != no_cabeca)
  {
    remove = remove_fim_fila(*ap_fila);
    while (G.adj[remove] != NULL)
    {
      vizinho = G.adj[remove]->valor;
      if (cor[vizinho] == 0)
      {
        cor[vizinho] = 1; //visitado
        distancia[vizinho] = distancia[remove] + 1;
        if (vizinho == fim)
          return distancia[fim];

        insere_inicio_fila(*ap_fila, vizinho);
      }
      G.adj[remove] = G.adj[remove]->prox;
    }
  }
  return 0;
}

void insere_inicio_fila(Lista ap_fila, int valor)
{
  No *novo = (No *)malloc(sizeof(No));

  novo->valor = valor;
  novo->antec = ap_fila;
  novo->prox = ap_fila->prox;
  ap_fila->prox = novo;
  novo->prox->antec = novo;
}

int remove_fim_fila(Lista ap_fila)
{
  No *aux = ap_fila->antec;
  int valor_remover;
  if (ap_fila->prox != ap_fila)
  {
    valor_remover = aux->valor;
    aux->antec->prox = ap_fila;
    ap_fila->antec = aux->antec;
    free(aux);
  }
  return valor_remover;
}