/*
addEdge should add an edge from specified node 1 to specified node 2
    if there is not an edge currently and should print a message if there is already such an edge.
*/
#include <stdio.h>
#define EDGES 20
#define NODES 5
int size = 0; // the number of edges

void printEdges(int *graphEdges);
// add an edge of node1 and node2
void addEdge(int node1, int node2, int *graphEdges);
// print all nodes that node i is pointin to
void printAdjacentNodes(int node, int *graphEdges);
// print the graph in edge pairs
void printOrderedPairs(int *graphEdges);
// return 1 if the two nodes are connected, 0 otherwise
int areConnected(int node1, int node2, int *graphEdges);

int main()
{
    /* 5 node: 0, 1, 2, 3, 4
        3 <- 4     5
             ^     ^
             \     \
        0 -> 1 ---> 2
    */
    int graphEdges[EDGES * 2];

    for (int i = 0; i < EDGES * 2; i += 2)
    {
        graphEdges[i] = -1;
        graphEdges[i + 1] = -1;
    }

    addEdge(1, 2, graphEdges);
    addEdge(0, 1, graphEdges);
    addEdge(1, 4, graphEdges);
    addEdge(4, 3, graphEdges);
    addEdge(2, 5, graphEdges);

    printOrderedPairs(graphEdges);

    printAdjacentNodes(1, graphEdges);

    printf("is node [%d] connected to [%d]? %s", 1, 5, (areConnected(1, 5, graphEdges) == 1) ? "True" : "False");
}

void printEdges(int *graphEdges)
{
    for (int i = 0; i < EDGES * 2; i += 2)
        if (graphEdges[i] != -1)
            printf("[%d] is connecting [%d]\n", graphEdges[i], graphEdges[i + 1]);
}

// add an edge of node1 and node2
void addEdge(int node1, int node2, int *graphEdges)
{
    graphEdges[size * 2] = node1;
    graphEdges[size * 2 + 1] = node2;
    size++;
}

// printAdjacentNodes should print a list of all nodes j such that there is an edge from
// the specified
void printAdjacentNodes(int node, int *graphEdges)
{
    printf("node[%d] is connecting to: ", node);
    for (int i = 0; i < EDGES * 2; i += 2)
    {
        if (graphEdges[i] == node)
            printf("[%d]", graphEdges[i + 1]);
    }
}

// printOrderedPairs is a function that should print a list of all the ordered pairs (i,j)
// such that there is an edge from node i to node j.
void printOrderedPairs(int *graphEdges)
{
    printf("Graph has pairs: \n");
    for (int i = 0; i < EDGES * 2; i += 2)
    {
        if (graphEdges[i] != -1)
            printf("[%d] and [%d]\n", graphEdges[i], graphEdges[i + 1]);
    }
}

// areConnected should return a value of 1 if there is an edge from specified node 1 to
// specified node 2 and of 0 otherwise.
int areConnected(int node1, int node2, int *graphEdges)
{
    for (int i = 0; i < EDGES * 2; i += 2)
    {
        if (((graphEdges[i] == node1) && (graphEdges[i + 1] == node2)) || ((graphEdges[i] == node2) && (graphEdges[i + 1] == node1)))
            return 1;
    }
    return 0;
}