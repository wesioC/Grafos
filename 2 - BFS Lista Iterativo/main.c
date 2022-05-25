#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "grafo.h"
#define TAM 10

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct desc{
	No *ini, *fim;
}Desc;


int enfileirar(Desc *D, int valor){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	novo->prox = NULL;

	if (D->ini == NULL){
		D->ini = novo;
		D->fim = novo;
	}else{
		D->fim->prox = novo;
		D->fim = novo;
	}
	return 1;
}

int desenfileirar(Desc *D){
	if (D->ini == NULL)
		return 0;

	No *aux;
	aux = D->ini;
	D->ini = aux->prox;
	free(aux);
	if (D->ini == NULL){
		D->fim = NULL;
	}

	return 1;
}

int * primeiro(Desc *D){
	if (D->ini == NULL)
		return NULL;

	return &D->ini->dado;
}
//lista---------------------------------------
struct graph
{
   int V;
   int A;
   link *adj;
};
struct node
{
   vertex w;
   link next;
};
static link NEWnode(vertex w, link next)
{
   link a = malloc(sizeof(struct node));
   a->w = w;
   a->next = next;
   return a;
}

Graph GRAPHinit(int V)
{
   vertex v;
   Graph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = malloc(V * sizeof(link));
   for (v = 0; v < V; ++v)
      G->adj[v] = NULL;
   return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w)
{
   link a;
   if (G == NULL)
      return;
   if (v < 0 || v >= G->V)
      return;
   if (w < 0 || w >= G->V)
      return;
   for (a = G->adj[v]; a != NULL; a = a->next)
      if (a->w == w)
         return;
   G->adj[v] = NEWnode(w, G->adj[v]);
   G->A++;
}
void GRAPHshow(Graph G)
{
   vertex v;
   link a;
   for (v = 0; v < G->V; v++)
   {
      printf("%d:", v);
      for (a = G->adj[v]; a != NULL; a = a->next)
         printf(" %d", a->w);
      printf("\n");
   }
   printf("Vértices: %d Arestas: %d\n", G->V, G->A);

}

void GRAPHleitura(Graph G, int m)
{
   int a, b;
   while (m--)
   {
      scanf("%d %d", &a, &b);
      GRAPHinsertArc(G, a, b);
      GRAPHinsertArc(G, b, a);
   }
}

//-------------------------------------------


int imprimir(Desc *D){
  if (D->ini == NULL)
		return 0;
  No *p;
	for(p=D->ini;p!=D->fim;p=p->prox){
    printf("%i\n", p->dado);
  }
    printf("%i\n", p->dado);
    
  return 1;
}
//n = vertices __
//m = arestas *
int Bfs(int n, Graph G, int s){
  Desc Q;
  Q.ini = NULL;
	Q.fim = NULL;	
	
	int d[n],cor[n], pi[n],u;
	
 	for(u = 0; u<n; u++){
 		//legenda de cores: 0=branco , 1=cinza e 2=preto
 		cor[u]=0;
 		d[u]=999999999;
 		pi[u]=-1;
	 }
	 cor[s]=1;
	 d[s]=0;
	 pi[s]=-1;
	 enfileirar(&Q,s);
	 imprimir(&Q);
	 //bfs visit
	 while (Q.ini!=NULL){
      u = Q.ini->dado;
	 	  desenfileirar(&Q);
	 		for(int v=0;v<n;v++){
	 			if(cor[v]==0){
	 				cor[v] = 1;
	 				d[v]= d[u]+1;
          pi[v]=u;
          printf("\n%i",v);
          enfileirar(&Q,v);
				 }
		 }
     cor[u]=2;
	 }
 	//
	//------------------------------------

  //print ------------------------------
	
	return 1;
}

int main(void) {
  Graph G;
  int n,m;
  scanf("%d %d",&n,&m);
  G=GRAPHinit(n);
  GRAPHleitura(G,m);
  GRAPHshow(G);
  clock_t t;
  t = clock();
  Bfs(n,G,2);
  t = clock() - t;
  printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

}