#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX_SIZE 10
typedef struct gNode
{
	int vertex;
	struct gNode *link;
} gNode;

typedef struct graph
{
	int vertexNum;
	gNode *adj[MAX_VERTEX_SIZE];
} graph;

void initGraph(graph *g);
void setVertex(graph *g, int n);
void connectEdge(graph *g, int A, int B);
void printGraph(graph *g);
void dfsTraversal(graph *g, int v);

int visited[MAX_VERTEX_SIZE];

int main()
{
	graph *g;

	initGraph(g);

	setVertex(g, 4);

	connectEdge(g, 0, 1);
	connectEdge(g, 0, 2);
	connectEdge(g, 0, 3);
	connectEdge(g, 1, 2);
	connectEdge(g, 2, 3);

	printGraph(g);

	dfsTraversal(g, 0);

	return 0;
}

void initGraph(graph *g)
{
	// Init Graph g
	g->vertexNum = 0;

	for(int i=0; i<MAX_VERTEX_SIZE; i++)
	{
		g->adj[i] = NULL;
		visited[i] = 0; 
	}
}

void setVertex(graph *g, int n)
{	// Set vertext Count;
	g->vertexNum = n;
}

void connectEdge(graph *g, int A, int B)
{
	gNode *node = (gNode*)malloc(sizeof(gNode));

	node->vertex = A;
	node->link = g->adj[B];
	g->adj[B] = node;

	gNode *vnode = (gNode*)malloc(sizeof(gNode));
	
	vnode->vertex = B;
	vnode->link = g->adj[A];
	g->adj[A] = vnode;
}


void dfsTraversal(graph *g, int v)
{
	gNode *node;
	visited[v] = 1;
	printf("%d ", v);

	for( node = g->adj[v]; node; node=node->link)
	{
		if( !visited[node->vertex])
		{
			dfsTraversal(g, node->vertex);
		}
	}
}


void printGraph(graph *g)
{
	int i;


	for(i=0; i<g->vertexNum; i++)
	{
		gNode *temp = g->adj[i];
		
		printf(" %dth adj : ", i);
		while(temp != NULL)
		{
			printf("%d -> ",temp->vertex);
			temp = temp->link;
		}
		printf("NULL\n");
	}
}



