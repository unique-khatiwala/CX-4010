// adjacency matrix for a graph
#include <stdio.h>
#include <stdbool.h>
#define NODES 5

// print nodes in 1d order
void print1dOrder(int *graphArray1d);
// print nodes in tabular format, so that it looks like the 2d matrix above
void printTabular(int *graphArray1d);
// print a list of ordered pairs (i,j) where there is a node from i to j
void printOrderedPairs(int *graphArray1d);
// for input node basenode, print a list of the nodes where there is an edge from basenode
void printAdjacentNodes(int basenode, int *graphArray1d);
// add an edge from node1 to node2 or give a message if there is already such an edge
void addEdge(int node1, int node2, int *graphArray1d);
// return 1 if there is an edge from node1 to node 2, return 0 otherwise
int areConnected(int node1, int node2, int *graphArray1d);
// return 1 if the graph is undirected (symmetric), return 0 otherwise
int isUndirected(int *graphArray1d);
// return the in-degree of the input node basenode
int inDegree(int basenode, int *graphArray);
// return the in-degree of the input node basenode
int outDegree(int basenode, int *graphArray);

int main()
{
	// this is an undirected graph (symmetric matrix)
	int graph2d[NODES][NODES] =
		{{0, 1, 1, 0, 1},
		 {1, 0, 1, 0, 0},
		 {1, 1, 0, 1, 0},
		 {0, 0, 1, 0, 1},
		 {1, 0, 0, 1, 0}};

	// this is a directed graph
	/*
	int graph2d[NODES][NODES] =
			{ {0, 1, 0, 1, 1},
			  {0, 0, 1, 1, 0},
			  {1, 1, 0, 1, 0},
			  {1, 0, 1, 0, 1},
			  {0, 0, 1, 0, 0} };
	*/

	int graph1d[NODES * NODES];
	int i, j;

	// set up a 1d array from the 2d array to use for the remaining operations
	for (i = 0; i < NODES; i++)
	{
		for (j = 0; j < NODES; j++)
		{
			graph1d[i * NODES + j] = graph2d[i][j];
		}
	}

	// print1dOrder(graph1d); // you'll probably want to comment out this line at some point
	outDegree(0, graph2d);
	inDegree(0, graph2d);
	isUndirected(graph1d);
	return 0;
}

void print1dOrder(int *graphArray1d)
{
	for (int i = 0; i < NODES + 1; i++)
		printf("a[%d] = %d\n", i, graphArray1d[i]);
}

// print nodes in tabular format, so that it looks like the 2d matrix given initially
void printTabular(int * graphArray1d)
{
	for (int i=0; i< NODES*NODES; i++) {
		printf("%d ",graphArray1d[i]);
		if((i+1) % NODES == 0)
			printf("\n");
		}
}

// print a list of ordered pairs (i,j) where there is a node from i to j
void printOrderedPairs(int * graphArray1d)
{

	for(int r = 0;r< NODES; r++){

		for(int c = 0; c<r; c++){

			if(graphArray1d[r*NODES+c] == 1)
				printf("(%d,%d)\n",r,c);

		}
	}
}

// for input node basenode, print a list of the nodes where there is an edge from basenode
void printAdjacentNodes(int basenode, int * graphArray1d)
{
	for(int j = 0; j < NODES; j++){
		if(graphArray1d[basenode*NODES + j] == 1){
			printf("%d\n", j);
		}
	}
}

// add an edge from node1 to node2 or give a message if there is already such an edge
void addEdge(int node1, int node2, int * graphArray1d)
{
	graphArray1d[node1*NODES+node2] = 1;
}

// return 1 if there is an edge from node1 to node 2, return 0 otherwise
int areConnected(int node1, int node2, int * graphArray1d)
{
		return graphArray1d[node1*NODES+node2];
}

// return 1 if the graph is undirected (symmetric), return 0 otherwise
int isUndirected(int *graphArray1d)
{
	int result; // result == false for not undirected, result ==  for undirected
	for (int i = 0; i < NODES; i++)
	{
		for (int j = i + 1; j < NODES; j++)
		{
			if (graphArray1d[i * NODES + j] != graphArray1d[j * NODES + i])
			{
				printf("%s", result ? "" : "");
				result = 0;
				break;
			}
		}
	}
	printf("Graph is %s", result ? "undirected" : "directed");
	return 1;
}

// return the in-degree of the input node basenode
int inDegree(int basenode, int *graphArray)
{
	int count = 0;
	for (int i = 0; i < NODES; i++)
	{
		int ind = i * NODES + basenode;
		if (graphArray[ind] != 0)
			count++;
		printf("%d ", graphArray[ind]);
	}
	printf("outDegree is %d\n", count);
	return count;
}

// return the out-degree of the input node basenode
int outDegree(int basenode, int *graphArray)
{
	int count = 0;
	for (int j = 0; j < NODES; j++)
	{
		int ind = basenode * NODES + j;
		if (graphArray[ind] != 0)
			count++;
		printf("%d ", graphArray[ind]);
	}
	printf("outDegree is %d\n", count);
	return count;
}
