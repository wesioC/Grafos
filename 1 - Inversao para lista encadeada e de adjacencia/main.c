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


//----------------------Matriz adjacencia para incidencia-------------------------
void Matrizadj_Inc(int n, Graph ma){
  int qtdvertices = 0;
  int cont = 0;
//-----------------------------------------------------
  //ler matriz de adjacencia
  /*
  printf("Escreva a matriz de adjacência:\n");
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      scanf("%i", &ma[i][j]);
  }
  }
  
  printf("\n matriz de adjacência:");
  printf("\n  ");
  for(int j = 0; j<n;j++){
    printf(" %i",j);
  }
  for(int i = 0; i<n;i++){
    printf("\n%i: ",i);
    for(int j = 0; j<n;j++){
      printf("%i ", ma[i][j]);
  }
    }
  */
//-----------------------------------------------------
//verificar quantidade de vertices
  for (int i = 0; i < ma->V; i++)
        for (int j = 0; j < ma->V; j++) {
            if (i <= j) {
                qtdvertices += ma->adj[i][j];
            }
        }
  printf("\nEsse grafo tem %i arestas\n\n",qtdvertices);
//-----------------------------------------------------
  //zerar matriz
  int mi[ma->V][qtdvertices];
  for(int i = 0; i<n;i++)
    for(int j = 0; j<qtdvertices;j++)
      mi[i][j]=0;
//-----------------------------------------------------
   //tranformar em matriz de incidencia
  for(int i = 0; i<ma->V;i++){
    for(int j = 0; j<ma->V;j++){
      if(i == j && ma->adj[i][j]==1){
        mi[i][cont]=2;
        cont++;
      }
      if(i<j && ma->adj[i][j]==1){
        mi[i][cont]=1;
        mi[j][cont]=1;
        cont++;
      }
    }
  }
  printf("\n matriz de incidência:");
  printf("\n  ");
  for(int j = 0; j<qtdvertices;j++){
    printf(" %i",j);
  }
  for(int i = 0; i<ma->V;i++){
    printf("\n%i: ",i);
    for(int j = 0; j<qtdvertices;j++){
      printf("%i ", mi[i][j]);
  }
    }
}
//----------------------Matriz de incidencia para adjacencia-------------------------
void MatrizInc_Adj(int n, int m){
  int mi[m][n];
  int ma[m][m];
  int x, y, cont=1;

  //-----------------------------------------------------
  //zerar matriz
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            ma[i][j] = 0;
  
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            mi[i][j] = 0;
  //-----------------------------------------------------
    //ler matriz incidencia
  printf("Escreva a matriz de incidência:\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%i", &mi[i][j]);
    
/* 
printf("\n matriz de incidência:");
  printf("\n  ");
  for(int j = 0; j<n;j++){
    printf(" %i",j);
  }
  for(int i = 0; i<m;i++){
    printf("\n%i: ",i);
    for(int j = 0; j<n;j++){
      printf("%i ", mi[i][j]);
  }
    }
*/ 
   //-----------------------------------------------------
    //tranformar matriz
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mi[j][i] == 2){
                x=j;
                y=j;
            }
            if(mi[j][i] == 1 && cont == 1){
                x=j;
                cont = 2;
            }
            if(mi[j][i]==1 && cont == 2){
                y=j;
            }
        }
        ma[x][y] = 1;
        ma[y][x] = 1;
        cont = 1;
    }

    
    printf("\n matriz de adjacência:");
    printf("\n  ");
    for(int j = 0; j<m;j++){
      printf(" %i",j);
    }
    for(int i = 0; i<m;i++){
      printf("\n%i: ",i);
      for(int j = 0; j<m;j++){
        printf("%i ", ma[i][j]);
  }
    }
    
}

//-----------------------------------------------------
typedef struct no{
	int dado;
	struct no *prox;
}No;

typedef struct lista{
	No *cabeca;
}Lista;
//-----------------------------------------------------
Lista * criar_lista(){
	Lista *lista;
	lista = (Lista *)malloc(sizeof(Lista));
	if (lista == NULL)
		return NULL;
	lista->cabeca = NULL;
	return lista;	
}
//-----------------------------------------------------
int inserir_fim(Lista *lista, int valor){	

	//verificar se a lista foi criada
	if (lista == NULL){
		printf("A lista nao foi criada.\n");
		exit(0);
	}

	No *novo;
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL)
		return 0;
	novo->dado = valor;
	novo->prox = NULL;

	if (lista->cabeca == NULL){
		lista->cabeca = novo;
	}else{
		No *p;
		for(p = lista->cabeca; p->prox!=NULL ; p=p->prox);
		p->prox = novo;
	}
	return 1;
}
//-----------------------------------------------------
void mostrar_lista(Lista *lista){

	//verificar se a lista foi criada
	if (lista == NULL){
		printf("A lista nao foi criada.\n");
		exit(0);
	}

	No *p;
	if (lista->cabeca == NULL)
		printf("Lista vazia.\n");
	printf("Lista Encadeada:\n");
	for(p = lista->cabeca; p!=NULL ; p=p->prox){
		printf("[%i]->", p->dado);
	}
  printf("NULL");
}
//-----------------------------------------------------
void listapMatriz(Lista *lista,int m){
  int ma[m][m];
  	//verificar se a lista foi criada
	if (lista == NULL){
		printf("A lista nao foi criada.\n");
		exit(0);
	}

	No *p;
	if (lista->cabeca == NULL)
		printf("Lista vazia.\n");
	
    p = lista->cabeca;
     for(int i = 0; i<m;i++){
      for(int j = 0; j<m;j++){
      ma[i][j] = p->dado;
      p = p->prox;       
  }
  }
	

      printf("\n matriz de adjacência:");
    printf("\n  ");
    for(int j = 0; j<m;j++){
      printf(" %i",j);
    }
    for(int i = 0; i<m;i++){
      printf("\n%i: ",i);
      for(int j = 0; j<m;j++){
        printf("%i ", ma[i][j]);
  }
    }
  
}
//-----------------------------------------------------
void matrizpLista(int m,Lista *lista, Graph ma){
     for(int i = 0; i<ma->V;i++){
      for(int j = 0; j<ma->V;j++){
        inserir_fim(lista,ma->adj[i][j]);
      }
    }
  mostrar_lista(lista);
}
//--------------------------MENU---------------------------
int menu(){
  
    int opc;
    system("clear");
    printf("\n\n\n[0] - Sair.\n");
    printf("[1] - Matriz de adjacência para matriz de incidência.\n");
    printf("[2] - Matriz de incidência para matriz de adjacência.\n");
    printf("[3] - Matriz de adjacência para lista de adjacência e o inverso.\n");
    printf("[4] - Lista de adjacência para matriz de adjacência.\n");
    printf("Escolha uma opção: ");
    scanf("%i", &opc);
    return opc;
}

int main(void) {
  int opc,n,m,num;
  Graph G;
  Lista *a = NULL;
  a=criar_lista();
   while (opc=menu()){
     system("clear");
        switch (opc){
        case 1:
          scanf("%d %d",&n,&m);
          G=GRAPHinit(n);
          GRAPHleitura(G,m);
          GRAPHshow(G);
          Matrizadj_Inc(m,G);
          //->adj[i][j]
            break;
        case 2:
          printf("Digite a quantidade de aresta e vertices: ");
          scanf("%d %d",&n,&m);
          printf("Digite a matriz apenas com 0, 1 e 2 sepada por espaco!\n\n");
          MatrizInc_Adj(n,m);
            break;
        case 3:
          scanf("%d %d",&n,&m);
          G=GRAPHinit(n);
          GRAPHleitura(G,m);
          GRAPHshow(G);
          matrizpLista(m,a,G);
            break;
        case 4:
          free(a);
          a=criar_lista();
          printf("Digite a quantidade de vertices: ");
          scanf("%i", &m);
          system("clear");
          printf("Digite a lista encadeada [1 ou 0]:\n");
          for(int j = 0; j<pow(m,2);j++){
            scanf("%i", &num);
            inserir_fim(a,num);
          }
          mostrar_lista(a);
          listapMatriz(a,m);
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