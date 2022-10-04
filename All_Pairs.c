#include <stdio.h> 
#define max 2000

int graph[5][5] = {{0, 25, 15, max, max}, {12, 0, max, 55, max}, {max, max, 0, max, max},
 {max, max, 45, 0, 60}, {max, max, 20, max, 0}};
int update[5][5];

int main(void) {
    int min = max;
    int new_min;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            min = max;
            for(int k =0; k < 5; k++) {
                 new_min = graph[i][k] + graph[k][j];
                if (new_min < min)
                    min = new_min;
            }
            update[i][j] = min;
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ",update[i][j]);
        }
        printf("\n");
    }

}

