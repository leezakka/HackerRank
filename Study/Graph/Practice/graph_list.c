#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
int visited[MAX_VERTICES];
typedef struct GraphNode
{
	int vertex;
	struct GraphNode *link;
}
 GraphNode;

typedef struct GraphType
{
	int n;
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

void graph_init(GraphType *g);
void insert_vertex(GraphType *g, int v);
void insert_edge(GraphType *g, int start, int end);
void Graph_Display(GraphType *g);
void dfs_list(GraphType *g, int v);

int main()
{ 
	int i;
	GraphType *g;

	graph_init(g);

	// create adjacent list
	for(int i=0; i<4; i++)
	{
		insert_vertex(g, i);
	}

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);
//	insert_edge(g, 3, 4);
//	insert_edge(g, 4, 3);
//	insert_edge(g, 2, 4);
//	insert_edge(g, 4, 2);
	
	Graph_Display(g);
	//dfs_list(g, 0);

	return 0;
}

void graph_init(GraphType *g)
{
	int v;
	
	g->n=0;
	for(v=0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
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

void insert_edge(GraphType *g, int u, int v) 
{
	GraphNode *node, *vnode;
	if(  u>= g->n || v >= g->n)
	{
		fprintf(stderr, "error of vertex number\n");
		return;
	}
	node = (GraphNode *)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	vnode = (GraphNode *)malloc(sizeof(GraphNode));
	vnode->vertex = u;
	vnode->link = g->adj_list[v];
	g->adj_list[v] = vnode;


}
	
void Graph_Display(GraphType *g)
{
	int i;
	GraphNode *tmp;

	for(i=0; i< g->n; i++)
	{
		printf(" Vertal %d -> Adj List\n", i);

		tmp = g->adj_list[i];
		while(tmp != NULL)
		{
			printf("%d ", tmp->vertex);
			tmp = tmp->link;
		}
		printf("\n");
	}
}
void dfs_list(GraphType *g, int v)
{
	GraphNode *w;
	visited[v] = 1; 
	printf("%d ", v);
	for(w=g->adj_list[v]; w; w=w->link)
		if(!visited[w->vertex])
			dfs_list(g, w->vertex);
}

