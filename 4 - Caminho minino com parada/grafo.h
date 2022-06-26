#define vertex int
typedef struct graph *Graph;
typedef struct node *link;
static int **MATRIXint(int r, int c, int val);
Graph GRAPHinit(int V);
void GRAPHinsertArc(Graph G, vertex v, vertex w, int p);
void GRAPHremoveArc(Graph G, vertex v, vertex w);
void GRAPHshow(Graph G);
