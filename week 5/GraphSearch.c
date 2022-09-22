#include <stdio.h>
#include "GraphSearch.h"

int main()
{
    /**Graph:
     *  4 - 0 - 1
     *  |   |   |
     *  3 - 2 --
     */
    // this is an undirected graph (symmetric matrix)
    int graph2d[5][5] =
        {{0, 1, 1, 0, 1},
         {1, 0, 1, 0, 0},
         {1, 1, 0, 1, 0},
         {0, 0, 1, 0, 1},
         {1, 0, 0, 1, 0}};

    dfs(0, graph2d);
    bfs(0, graph2d);
}

int dfs(int src, int graph[5][5])
{
    printf("Depth-First-Search");
    // add src to stack
    // for every neighbor of src: add neighbor in stack

    // for every neighbor, if not visited
    List *stack = (List *)malloc(sizeof(List));
    stack->head = 0;
    stack->tail = 1;
    int a[5] = {0, 0, 0, 0, 0};
    int *visited = a;
    // pushing src into stack, increment the tail, marking src as visited
    stack->tail += 1;
    stack->nums[stack->tail] = src;
    printf("push %d \n", src);
    visited[src] = 1;

    // while stack is not empty:
    // pop out a num
    while (stack->head + 1 < stack->tail)
    {
        // pop last added item
        int pop = stack->nums[stack->tail--];
        printf("pop (visit)  %d \n", pop);
        // go to its neighbors
        for (int i = 0; i < 5; i++)
        {
            if (visited[i] == 0 && graph[pop][i] == 1) // if not visted
            {
                stack->tail += 1;
                stack->nums[stack->tail] = i; // add node to stack
                printf("push %d \n", i);
                visited[i] = 1; // marked as visted
            }
        }
    };
    return 0;
};

int bfs(int src, int graph[5][5])
{
    printf("Breath-First-Search");
    // add src to stack
    // for every neighbor of src: add neighbor in stack

    // for every neighbor, if not visited
    List *queue = (List *)malloc(sizeof(List));
    queue->head = 0;
    queue->tail = 1;
    int a[5] = {0, 0, 0, 0, 0};
    int *visited = a;
    // increment the tail, pushing src into stack, marking src as visited
    queue->nums[queue->tail] = src;
    printf("push %d \n", src);
    visited[src] = 1;

    // while stack is not empty:
    // pop out a num
    while (queue->head < queue->tail)
    {
        // pop first added item in queue
        queue->head += 1;
        int pop = queue->nums[queue->head];
        printf("pop  (visit) %d \n", pop);
        // iterate through its neighbors
        for (int i = 0; i < 5; i++)
        {
            if (visited[i] == 0 && graph[pop][i] == 1) // if not visted
            {
                queue->tail += 1;
                queue->nums[queue->tail] = i; // add node to stack
                printf("push %d \n", i);
                visited[i] = 1; // marked as visted
            }
        }
    };
    return 0;
};