#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "grafo.h"
struct graph
{
   int V;
   int A;
   int **adj;
};
static int **MATRIXint(int r, int c, int val)
{
   vertex i, j;
   int **m = malloc(r * sizeof(int *));
   for (i = 0; i < r; ++i)
      m[i] = malloc(c * sizeof(int));
   for (i = 0; i < r; ++i)
      for (j = 0; j < c; ++j)
         m[i][j] = val;
   return m;
}

Graph GRAPHinit(int V)
{
   Graph G = malloc(sizeof *G);
   G->V = V;
   G->A = 0;
   G->adj = MATRIXint(V, V, 0);
   return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w)
{

   if (G == NULL)
      return;
   if (v < 0 || v >= G->V)
      return;
   if (w < 0 || w >= G->V)
      return;

   if (G->adj[v][w] == 0)
   {
      G->adj[v][w] = 1;
      G->A++;
   }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w)
{
   if (G == NULL)
      return;
   if (v < 0 || v >= G->V)
      return;
   if (w < 0 || w >= G->V)
      return;

   if (G->adj[v][w] != 0)
   {
      G->adj[v][w] = 0;
      G->A--;
   }
}

void GRAPHshow(Graph G)
{
   vertex v, w;
   for (v = 0; v < G->V; v++)
   {
      printf("%d:", v);
      for (w = 0; w < G->V; ++w)
      {
         printf(" %d", G->adj[v][w]);
      }
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

typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct lista{
	No *cabeca;
}Lista;

Lista * criar_lista(){
	Lista *lista;
	lista = (Lista *)malloc(sizeof(Lista));
	if (lista == NULL)
		return NULL;
	lista->cabeca = NULL;
	return lista;	
}

int verifvizinhosList(int m, int vi, int vj){	
  Lista *lista[m];
  int n;
  int valor;
  No *p;
    for(int j = 0; j<m;j++){
       lista[j]=criar_lista();
  }
  
	
  for(int i = 0; i<m;i++){
    printf("Digite a quantidade de vizinhos\npara o vertice v[%i]: ",i);
    scanf("%i", &n);
    system("clear");
    printf("Digite a lista de adjacencia do vertice v[%i]: \n",i);
    for(int j = 0; j<n;j++){
      //verificar se a lista foi criada
	if (lista[i] == NULL){
		printf("A lista nao foi criada.\n");
		exit(0);
	}
  
    scanf("%i", &valor);
	No *novo;
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	novo->prox = NULL;

	if (lista[i]->cabeca == NULL){
		lista[i]->cabeca = novo;
	}else{
		for(p = lista[i]->cabeca; p->prox!=NULL ; p=p->prox);
		p->prox = novo;
	}
    }
    }
  
printf("\nLista de Adjacencia:\n");
   
  for(int i = 0; i<m;i++){
    printf("\n%i: ",i);
  
  	for(p = lista[i]->cabeca; p!=NULL ; p=p->prox){
  		printf("[%i]->", p->dado);
  	}
    printf("NULL");
  }
	
  	for(p = lista[vi]->cabeca; p!=NULL ; p=p->prox){
  		if(p->dado == vj){
        break;
      }
 
  	}
  if(p->dado == vj){
    printf("\n[Os vertices Vi[%i] e Vj[%i] sao vizinhos!]",vi,vj);
  }else{
    printf("\n[Os vertices Vi[%i] e Vj[%i] nao sao vizinhos!]",vi,vj);
  }
  
  
  
	return 1;
}
//-----------------------------------------------------
int verifiqvizinhosMatriz(int vi, int vj, Graph ma){
  if(ma->adj[vi][vj]== 1){
    printf("\n[Os vertices Vi[%i] e Vj[%i] sao vizinhos!]",vi,vj);
  }else{
    printf("\n[Os vertices Vi[%i] e Vj[%i] nao sao vizinhos!]",vi,vj);
    return 0;
  }
  return 1;
}
void conjVizMatriz(int n,int vi,Graph ma){

  printf("\nVizinhos do vertice Vi=[%i]:{ ",vi);
  for(int j = 0; j<n;j++){
      if(ma->adj[vi][j]==1){
        printf("%i, ",j);
      }
  }
  printf("}\n");

}

//-----------------------------------------------------
int conjVizList(int m, int vi){
  Lista *lista[m];
  int n;
  int valor,cont =0;
  No *p;
    for(int j = 0; j<m;j++){
       lista[j]=criar_lista();
  }
  printf("Digite a lista de forma encadeada:\n");

    for(int i = 0; i<m;i++){
    printf("Digite a quantidade de vizinhos\npara o vertice v[%i]: ",i);
    scanf("%i", &n);
    system("clear");
    printf("Digite a lista de adjacencia do vertice v[%i]: \n",i);
    for(int j = 0; j<n;j++){
      //verificar se a lista foi criada
	if (lista[i] == NULL){
		printf("A lista nao foi criada.\n");
		exit(0);
	}
  
    scanf("%i", &valor);
	No *novo;
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	novo->prox = NULL;

	if (lista[i]->cabeca == NULL){
		lista[i]->cabeca = novo;
	}else{
		for(p = lista[i]->cabeca; p->prox!=NULL ; p=p->prox);
		p->prox = novo;
	}
    }
    }
  /*for(int i = 0; i<m;i++){
    for(int j = 0; j<m;j++){
      //verificar se a lista foi criada
	if (lista[i] == NULL){
		printf("A lista nao foi criada.\n");
		exit(0);
	}
  
    scanf("%i", &valor);
	No *novo;
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	novo->prox = NULL;

	if (lista[i]->cabeca == NULL){
		lista[i]->cabeca = novo;
	}else{
		No *p;
		for(p = lista[i]->cabeca; p->prox!=NULL ; p=p->prox);
		p->prox = novo;
	}
    }
    }*/

printf("\nLista de Adjacencia:\n");
   
  for(int i = 0; i<m;i++){
    printf("\n%i: ",i);
  
  	for(p = lista[i]->cabeca; p!=NULL ; p=p->prox){
  		printf("[%i]->", p->dado);
  	}
    printf("NULL");
  }
  
printf("\n\nVizinhos do vertice Vi=[%i]:{ ",vi);
 for(p = lista[vi]->cabeca; p!=NULL ; p=p->prox){
    printf("%i, ",p->dado);
  	}
printf("}\n");
  
	
 
  return 1;
}
//-----------------------------------------------------
int menu(){
    int opc;
    system("clear");
    printf("\n\n\n[0] - Sair.\n");
    printf("[1] - Vizinhos de um vertice em uma matriz\n");
    printf("[2] - Verificar vizinhaca a partir de dois vertices em uma matriz.\n");
    printf("[3] - Vizinhos de um vertice em uma lista.\n");
    printf("[4] - verificar vizinhaca a partir de dois vertes em uma lista.\n");
    printf("Escolha uma opção: ");
    scanf("%i", &opc);
    return opc;
}

int main(void) {
  int opc,n,m,num, vi, vj;
  int ma[m][m];
  Graph G;
  
   while (opc=menu()){
     system("clear");
        switch (opc){
        case 1:
          scanf("%d %d",&n,&m);
          G=GRAPHinit(n);
          GRAPHleitura(G,m);
          GRAPHshow(G);
          printf("Digite o vertices para a encontrar seus vizinhos \n");
          scanf("%i", &vi);
          conjVizMatriz(m,vi,G);
          
            break;
        case 2:
          scanf("%d %d",&n,&m);
          G=GRAPHinit(n);
          GRAPHleitura(G,m);
          GRAPHshow(G);
          printf("Digite dois vertices para a verificacao de adjacencia\n[separado por espaco]: \n");
          scanf("%i %i", &vi,&vj);
          verifiqvizinhosMatriz(vi,vj,G);
            break;
        case 3:
           printf("Digite a quantidade de vertices para preeencher a lista:\n");
          scanf("%i", &m);
          system("clear");
          printf("Digite o vertices para a encontrar seus vizinhos \n");
          scanf("%i", &vi);
          conjVizList(m,vi);
            break;
        case 4:
          printf("Digite a quantidade de vertices para preeencher a lista:\n");
          scanf("%i", &m);
          system("clear");
          printf("Digite dois vertices para a verificacao de adjacencia\n[separado por espaco]: \n");
          scanf("%i %i", &vi,&vj);
            verifvizinhosList(m,vi,vj);
          
          
          break;
        default:
          printf("Opcao invalida.\n");
            break;
        }
        getchar();
        getchar();
    }
  return 0;
}