#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

int ** ler(n,m){
  int **G;
  int a,b;
  G = (int**)malloc(sizeof(int*)*n);
	for(int i = 0; i<n;i++)
    G[i] = (int*)malloc(sizeof(int*)*n);
    	
	for(int i = 0; i<n;i++)
    	for(int j = 0; j<n;j++)
      		G[i][j]=0;
		for(int i = 0; i<m;i++){
		scanf("%i %i", &a, &b);
		G[a][b]=1;
		G[b][a]=1;
}
  return  G;
  }
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
int bfs(int n, int **G, int s){
  Desc Q;
  Q.ini = NULL;
	Q.fim = NULL;	
	clock_t t;
	int d[n],cor[n], pi[n],u;
	t = clock();
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
	 //bfs visit
	 while (Q.ini!=NULL){
      u = Q.ini->dado;
	 	  desenfileirar(&Q);
	 		for(int v=0;v<n;v++){
	 			if(cor[v]==0 && G[u][v]==1){
	 				cor[v] = 1;
	 				d[v]= d[u]+1;
          pi[v]=u;
          printf("%i",v);
          enfileirar(&Q,v);
				 }
		 }
     cor[u]=2;
	 }
 	t = clock() - t;
	//-----------------------------------------------------------

	//printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

  //print ------------------------------
	
	return 1;
}

int main(void) {
	int m,n,s,**G;

 
  scanf("%i %i", &n, &m);
   G = ler(n,m);
  printf("\n matriz de adjacência:");
    printf("\n  ");
    for(int j = 0; j<n;j++){
      printf(" %i",j);
    }
    for(int i = 0; i<n;i++){
      printf("\n%i: ",i);
      for(int j = 0; j<n;j++){
        printf("%i ", G[i][j]);
  }
    }
  printf("\n  ");
  clock_t t;
  t = clock();
  bfs(n,G,2);
    t = clock() - t;
  printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));


}