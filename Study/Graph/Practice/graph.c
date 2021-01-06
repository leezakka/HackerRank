#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n; // count of vertices
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g);
void insert_vertex(GraphType *g, int v);
void insert_edge(GraphType *g, int start, int end);

int main()
{





	return 0;
}

void graph_init(GraphType *g)
{
	int r,c;
	g->n = 0;

	for(r=0; r<MAX_VERTICES; r++)
	{
		for(c=0; c<MAX_VERTICES; c++)
		{
			g->adj_mat[r][c]=0;
		}
	}
}

void insert_vertex(GraphType *g, int v)
{
	if( ((g->n)+1) > MAX_VERTICES)
	{
		fprintf(stderr, "exceed of MAX_VERTICES\n");
		return ;
	}
	g->n++;
}

void insert_edge(GraphType *g, int start, int end)
{
	if( start >= g->n || end >= g->n)
	{
		fprintf(stderr, "error of vertex number\n");
		return;
	}

	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}


