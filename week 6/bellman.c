#include <stdio.h>
#include <stdlib.h> // needed for function atoi()
#define size 5
#define INT_MAX 2147483647

int graph[size][size] = {
                  {0  ,420,175,0  ,0},
                  {420,0  ,0  ,150,0},
                  {175,0  ,0  ,400,0},
                  {0  ,150,400,0  ,100},
                  {0  ,0  ,0  ,100,0}
                  };

int d[size] = {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
int p[size] = {0};
int flag = 1;


void relax(int start, int end){
  if((d[start] + graph[start][end]) < d[end]){
    d[end] = d[start] + graph[start][end];
    p[end] = start;
    flag = 1;
    //printf("relaxing\n");
  }
}

int main()
{
  int start = 0, end = 0; // start at 0 node
  d[start] = 0;

  while(flag != 0){
    flag = 0;
    //printf("inside while\n");
    for(start = 0; start < size; start ++){
      for(end = start; end < size; end++) {
        if(graph[start][end] != 0){
          //printf("%d%d\n",start,end);
          relax(start,end);
        }
      }

    }
  }
  for(int i = 1; i < size; i++)
  printf("distance required %d, can reach from node %d \n",d[i],p[i]);
}
