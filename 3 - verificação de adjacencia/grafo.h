#define vertex int
typedef struct graph *Graph;
static int **MATRIXint(int r, int c, int val);
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHshow(Graph G);
void GRAPHleitura(Graph G, int m);