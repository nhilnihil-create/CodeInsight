#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <deque>

int main(){
  int K, T;
  scanf("%d", &K);
  scanf("%d", &T);
  std::vector<int > a(T);
  int maxval = 0;
  for (int i=0; i<T; i++){
    scanf("%d", &a[i]);
    maxval = std::max(maxval, a[i]);
  }
  int half = (K+1)/2;
  if (K%2==0){
    printf("%d\n", std::max(0, 2*(maxval-half)-1));
  } else {
    printf("%d\n", std::max(0, 2*(maxval-half)));
  }
  
  return 0;
}
