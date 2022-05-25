#define vertex int
typedef struct graph *Graph;
typedef struct node *link;
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHshow(Graph G);
void GRAPHleitura(Graph G, int m);