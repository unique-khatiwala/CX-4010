#include <stdio.h>
#include <stdlib.h>
#define NODES 50

typedef struct List
{
    int nums[NODES];
    int head;
    int tail;
    /**
     * for stack:
     * increment then push into tail
     * pop from tail, decrement tail
     * last added number is stored at tail, head is kept empty
     *
     *
     * for queue:
     * increment then push into tail
     * increment and pop from head
     * pop is left blank, only marking the beginning of the queue
     */

} List;

int dfs(int src, int graph[5][5]);

int bfs(int src, int graph[5][5]);
