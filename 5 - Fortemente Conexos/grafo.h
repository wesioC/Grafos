#define vertex int
static int cnt, pre[1000];
static int cntt, post[1000];
static vertex vv[1000];
typedef struct graph *Graph;
typedef struct node *link;
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHshow(Graph G);
void GRAPHleitura(Graph G, int m);
Graph GRAPHreverse(Graph G);
static void dfsR( Graph GR, vertex v);
static void dfsRstrongCompsK( Graph G, vertex v, int *sc, int k);
int GRAPHstrongCompsK( Graph G, int *sc);