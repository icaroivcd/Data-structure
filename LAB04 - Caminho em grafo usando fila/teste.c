#include<stdio.h>
#include<stdlib.h>

typedef struct aux{
	int valor;
	struct aux *prox;
	struct aux *antec;
} No;

typedef No *Lista;  // lista interna (lista dos vizinhos)

typedef struct{
	int n_vert, n_aresta;
	Lista *adj;  // vetor de listas (lista dos vértices)
} grafo;

Lista * inicializa_lista_adj (int M);
void le_grafo(Lista *adj, int v1, int v2);
int menor_distancia(grafo G, Lista * ap_fila, int ini, int fim);
void insere_inicio(Lista ap_fila, int val);
int remove_fim(Lista ap_fila);

int main(){

	grafo G;
	int N;
	int M;
	int ini, fim;

	printf("Numero de vertices e arestas: ");
	scanf("%d %d", &M, &N);

	G.n_vert = M;
	G.n_aresta = N;
	G.adj = inicializa_lista_adj(M);  // atribui o vetor à G.adj

	int v1;
	int v2;
	for(int i=0; i<N; i++){
	scanf("%d %d", &v1, &v2);
	le_grafo(G.adj, v1, v2);
	}
  
	scanf("%d %d", &ini, &fim);		
	Lista fila;
	int menor = menor_distancia(G, &fila, ini, fim);
	if(menor != -1)
		printf("%f ", (float) menor);
	else	
		printf("infinito");
	
  // Imprime lista de adjacencia   TA DANDO ERRO AQUI QUANDO CHAMA menor_distancia()
	// printf("\n");
	// for(int i=0; i<M; i++){
	// 	printf("vertice %d: ",i);
	// 	while(G.adj[i] != NULL){
	// 		printf("%d ", G.adj[i]->valor);
	// 		G.adj[i] = G.adj[i]->prox;
	// 	}
	// 	printf("\n");
	// }
}

// cada posição do vetor é uma nova lista sem nó cabeça
Lista * inicializa_lista_adj (int M){  // aloca e retorna o ponteiro do vetor

	Lista *ap_lista = (Lista *) malloc(M * sizeof(Lista));
	for(int i=0; i<M; i++)
		ap_lista[i] = NULL;	

	return ap_lista;
}

void le_grafo(Lista *adj, int v1, int v2){
	No *vert_vizinho = (No *) malloc(sizeof(No));
	vert_vizinho->valor = v2;
	vert_vizinho->prox = adj[v1];
	adj[v1] = vert_vizinho;
  
	if(v1 == v2)
		return;

	No *vert_vizinho2 = (No *) malloc(sizeof(No));
	vert_vizinho2->valor = v1;
	vert_vizinho2->prox = adj[v2];
	adj[v2] = vert_vizinho2;
}

/*remove da fila
olha os vizinhos
vai em um vizinho
olha e muda a cor
add 1 distância
add na fila
*/
int menor_distancia(grafo G, Lista * ap_fila, int ini, int fim){

	int dist[G.n_vert];  // vetor de distância da origem até cada vértice
	int cor[G.n_vert];  // vetor de vértices visitados

	for(int i=0; i<G.n_vert; i++){  // zera a lista de cor (0 não visitado, 1 na lista ou visitado) OK
		if(i == ini) // vert ini cor 1
			cor[i] = 1;
		else
			cor[i] = 0;
	}

	for(int i=0; i<G.n_vert; i++)  // inicia as distâncias em 0  OK
		dist[i] = 0;

	No * no_cab = (No *) malloc(sizeof(No));  // aloco fila e nó cabeça  OK
	*ap_fila = no_cab;

	No * vert_ini = (No *) malloc(sizeof(No));  // OK
	vert_ini->valor = ini;
	vert_ini->prox = no_cab;
	vert_ini->antec = no_cab;
	no_cab->prox = vert_ini;
	no_cab->antec = vert_ini;

	int val_fila;  // valor removido da fila
	int viz;

	while(no_cab->prox != no_cab){
		val_fila = remove_fim(*ap_fila);  // tá removendo e retornando
		while(G.adj[val_fila] != NULL){
			viz = G.adj[val_fila]->valor;  // viz OK
			if(cor[viz] == 0){
				cor[viz] = 1;
				dist[viz] = dist[val_fila] + 1;  // olhar isso aqui
				if(viz == fim)  //distância encontrada
					return dist[fim];
				insere_inicio(*ap_fila, viz);
			}
			G.adj[val_fila] = G.adj[val_fila]->prox;
		}
	}
	return -1;
}

void insere_inicio(Lista ap_fila, int val){

	No * novo_no = (No *) malloc(sizeof(No));
	novo_no->valor = val;
	novo_no->prox = ap_fila->prox;
	novo_no->antec = ap_fila;
	ap_fila->prox = novo_no;
	novo_no->prox->antec = novo_no;
}

int remove_fim(Lista ap_fila){

	int val_removido;
	if(ap_fila->prox != ap_fila){  // fila não vazia
		No * no_aux = ap_fila->antec;
		val_removido = no_aux->valor;
		no_aux->antec->prox = ap_fila;
		ap_fila->antec = no_aux->antec;
		free(no_aux);
	}
	return val_removido;
}