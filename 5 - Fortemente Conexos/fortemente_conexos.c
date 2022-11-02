#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


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

void GRAPHremoveArc(Graph G, vertex v, vertex w)
{

   link p;
   link q;

   if (G == NULL)
      return;
   if (v < 0 || v >= G->V)
      return;
   if (w < 0 || w >= G->V)
      return;

   p = G->adj[v];
   q = p->next;
   while (q != NULL && q->w != w && p->w != w)
   {
      p = q;
      q = q->next;
   }
   if (p->w == w)
   {
      G->adj[v] = q;
      free(p);
      G->A--;
   }
   else if (q != NULL)
   {
      p->next = q->next;
      free(q);
      G->A--;
   }
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
   printf("Vertices: %d Arestas: %d\n", G->V, G->A);

}
//****************************************************
Graph GRAPHreverse( Graph G) 
{
   Graph GR = GRAPHinit( G->V);
   for (vertex v = 0; v < G->V; ++v) 
      for (link a = G->adj[v]; a != NULL; a = a->next)
         GRAPHinsertArc( GR, a->w, v);
   return GR;
}

static void dfsR( Graph GR, vertex v) 
{ 
   pre[v] = cnt++; 
   for (link a = GR->adj[v]; a != NULL; a = a->next)
      if (pre[a->w] == -1) 
         dfsR( GR, a->w); 
   post[v] = cntt++;
}
static void dfsRstrongCompsK( Graph G, vertex v, int *sc, int k) 
{ 
   sc[v] = k;
   for (link a = G->adj[v]; a != NULL; a = a->next)
      if (sc[a->w] == -1) 
         dfsRstrongCompsK( G, a->w, sc, k);
}
int GRAPHstrongCompsK( Graph G, int *sc) 
{
   // fase 1:
   Graph GR = GRAPHreverse( G);
   cnt = cntt = 0;
   vertex v; 
   for (v = 0; v < GR->V; ++v) pre[v] = -1;
   for (v = 0; v < GR->V; ++v) 
      if (pre[v] == -1)
         dfsR( GR, v); 
   for (v = 0; v < GR->V; ++v) 
      vv[post[v]] = v;
   // vv[0..V-1] é permutação de GR em pós-ordem
   //a numeração post[] é transformada na correspondente permutação vv[]

   // fase 2: algoritmo de eliminação iterada de sorvedouros
   //Ao passar de uma etapa da busca para outra, 
   //os vértices são considerados na ordem inversa de vv[]
   for (v = 0; v < G->V; ++v) sc[v] = -1;
   int k = 0;
   for (int i = G->V-1; i >= 0; --i) {
      v = vv[i];
      if (sc[v] == -1) {
         dfsRstrongCompsK( G, v, sc, k);
         k++;
      }
   }
   return k;
}

void GRAPHleitura(Graph G, int m)
{
   int a, b;
   while (m--)
   {
      scanf("%d %d", &a, &b);
      GRAPHinsertArc(G, a, b);
   }
}
