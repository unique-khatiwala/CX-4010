#include <stdio.h>

double maxNum(double tempList[10]);
int maxInd(double tempList[10]);
double *getMaxnInd(double tempList[10]);


int main() {
  double list[10] = {11,345,3245,76,5,6,756,345,767,44};
  // printf("Max index is %d\nMax number is %f", maxInd(list), maxNum(list));
  //double *a = getMaxnInd(list);
  //printf("Max index is %d\nMax number is %f", (int)*a, *(a+1));
  return 0;
}

int maxInd(double tempList[10]) {
  int index = 0;
  double max = tempList[0];

  for(int i = 0; i < 9; i++) {
    if(tempList[i] > max) {
      index = i;
      max = tempList[i];
    }

  }
  return index;
}

double maxNum(double tempList[10]) {
  return tempList[maxInd(tempList)];
}

double *getMaxnInd(double tempList[10]){
  int index = maxInd(tempList);
  double maxVal = maxNum(tempList);
  double values[2] = {(double)index, maxVal};
  // return values;
  return 0.0;
}
