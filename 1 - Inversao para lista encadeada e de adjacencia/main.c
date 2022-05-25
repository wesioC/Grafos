#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//----------------------Matriz adjacencia para incidencia-------------------------
void Matrizadj_Inc(int n){
  int ma[n][n];
  int qtdvertices = 0;
  int cont = 0;
//-----------------------------------------------------
  //ler matriz de adjacencia
  printf("Escreva a matriz de adjacência:\n");
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      scanf("%i", &ma[i][j]);
  }
  }
  /*
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
  for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                qtdvertices += ma[i][j];
            }
        }
  printf("\nEsse grafo tem %i arestas\n\n",qtdvertices);
//-----------------------------------------------------
  //zerar matriz
  int mi[n][qtdvertices];
  for(int i = 0; i<n;i++)
    for(int j = 0; j<qtdvertices;j++)
      mi[i][j]=0;
//-----------------------------------------------------
   //tranformar em matriz de incidencia
  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      if(i == j && ma[i][j]){
        mi[i][cont]=2;
        cont++;
      }
      if(i<j && ma[i][j]==1){
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
  for(int i = 0; i<n;i++){
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
void matrizpLista(int m,Lista *lista){
  int ma[m][m];
    printf("Escreva a matriz de adjacência:\n");
    for(int i = 0; i<m;i++){
      for(int j = 0; j<m;j++){
        scanf("%i", &ma[i][j]);
      }
    }
     for(int i = 0; i<m;i++){
      for(int j = 0; j<m;j++){
        inserir_fim(lista,ma[i][j]);
      }
    }
  mostrar_lista(lista);
}
//--------------------------MENU---------------------------
int menu(){
  
    int opc;
    system("clear");
    printf("A matriz deve ser preenchida desta forma:");
    printf("\n0 1 0 1 1\n1 0 1 1 1\n0 1 0 1 0\n1 1 1 0 1 \n1 1 0 1 0\n\n");
    printf("A lista deve ser preenchida desta forma:");
    printf("\n0\n1\n0\n1\n1\n1\n0\n1\n1\n1\n0\n1\n0\n1\n0\n1\n1\n1\n0\n1 \n1\n1\n0\n1\n0");
    printf("\n\n\n[0] - Sair.\n");
    printf("[1] - Matriz de adjacência para matriz de incidência.\n");
    printf("[2] - Matriz de incidência para matriz de adjacência.\n");
    printf("[3] - Matriz de adjacência para lista de adjacência e o inverso.\n");
    printf("[4] - Lista de adjacência para matrizde adjacência.\n");
    printf("Escolha uma opção: ");
    scanf("%i", &opc);
    return opc;
}

int main(void) {
  int opc,n,m,num;
  int ma[m][m];
  Lista *a = NULL;
  a=criar_lista();
   while (opc=menu()){
     system("clear");
        switch (opc){
        case 1:
          printf("Digite a quantidade de vertices: ");
          scanf("%i", &m);
          printf("Digite a matriz sepada por espaco!\n\n");
          Matrizadj_Inc(m);
            break;
        case 2:
          printf("Digite a quantidade de vertices: ");
          scanf("%i", &m);
          printf("Digite a quantidade de aresta: ");
          scanf("%i", &n);
          printf("Digite a matriz sepada por espaco!\n\n");
          MatrizInc_Adj(n,m);
            break;
        case 3:
          printf("Digite a quantidade de vertices: ");
          scanf("%i", &m);
          matrizpLista(m,a);
            break;
        case 4:
          free(a);
          a=criar_lista();
          printf("Digite a quantidade de vertices: ");
          scanf("%i", &m);
          system("clear");
          printf("Digite a lista de forma encadeada:\n");
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