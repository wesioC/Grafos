#include "grafo.h"
#include <math.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define INFINITY 9999
#define MAX 10

struct graph {
  int V;
  int A;
  int **adj;
};



static int **MATRIXint(int r, int c, int val) {
  vertex i, j;
  int **m = malloc(r * sizeof(int *));
  for (i = 0; i < r; ++i)
    m[i] = malloc(c * sizeof(int));
  for (i = 0; i < r; ++i)
    for (j = 0; j < c; ++j)
      m[i][j] = val;
  return m;
}
Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof *G);
  G->V = V;
  G->A = 0;
  G->adj = MATRIXint(V, V, 0);
  return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w, int p) {

  if (G == NULL)
    return;
  if (v < 0 || v >= G->V)
    return;
  if (w < 0 || w >= G->V)
    return;

  if (G->adj[v][w] == 0) {
    G->adj[v][w] = p;
    G->A++;
  }
}

void GRAPHremoveArc(Graph G, vertex v, vertex w) {
  if (G == NULL)
    return;
  if (v < 0 || v >= G->V)
    return;
  if (w < 0 || w >= G->V)
    return;

  if (G->adj[v][w] != 0) {
    G->adj[v][w] = 0;
    G->A--;
  }
}

void GRAPHshow(Graph G) {
  vertex v, w;
  for (v = 0; v < G->V; v++) {
    printf("%d:", v);
    for (w = 0; w < G->V; ++w) {
      printf(" %d", G->adj[v][w]);
    }
    printf("\n");
  }
  printf("Vértices: %d\nArestas: %d\n", G->V, G->A);
}

void GRAPHleitura(Graph G, int m) {
  int a, b, w;
  while (m--) {
    scanf("%d %d %d", &a, &b, &w);
    GRAPHinsertArc(G, a, b, w);
    //GRAPHinsertArc(G, b, a, w);
  }
}
int Dijkstra(Graph G, int s, int sp) {
  int *d;
  d = (int *) malloc(G->V * sizeof(int));
  int cost[G->V][G->V], pi[G->V],visit[G->V], cont, mind, prox, i, j;
  //inicializacao da matriz
  for (i = 0; i < G->V; i++)
    for (j = 0; j < G->V; j++)
      if (G->adj[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = G->adj[i][j];

  for (i = 0; i < G->V; i++) {
    d[i] = cost[s][i];
    pi[i] = s;
    visit[i] = 0;
  }

  d[s] = 0;
  visit[s] = 1;
  cont = 1;

  //incio do calculo de distancia minima
  while (cont < G->V - 1) {
    mind = INFINITY;

    for (i = 0; i < G->V; i++)
      if (d[i] < mind && !visit[i]) {
        mind = d[i];
        prox = i;
      }
    visit[prox] = 1;
    for (i = 0; i < G->V; i++)
      if (!visit[i])
        if (mind + cost[prox][i] < d[i]) {
          d[i] = mind + cost[prox][i];
          pi[i] = prox;
        }
    cont++;
  }
  return d[sp];
}
int Dijkstra2(Graph G, int v, int w, int t){
  int result = 0;
  result = Dijkstra(G,v,t) + Dijkstra(G,t,w);
  return result;
}
int main(void) {
  int n,m,v,w,t;
  Graph G;
  scanf("%d %d", &n, &m);
  G = GRAPHinit(n);
  GRAPHleitura(G, m);
  GRAPHshow(G);
  printf("\nEntre com a origem, o destino e a parada:\n");
  scanf("%d %d %d", &v, &w, &t);
  printf("\nCaminho minimo com parada = %i",Dijkstra2(G,v,w,t));
}