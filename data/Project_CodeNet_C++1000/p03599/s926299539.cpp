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
#include <unordered_map>
#include <set>
#include <deque>

int gcd(int n, int m){
  int maxvalue = std::max(n, m);
  int minvalue = std::min(n, m);
  if (minvalue==0) return n;
  return gcd(minvalue, maxvalue%minvalue);
}
int main(){
  int A, B, C, D, E, F;
  scanf("%d", &A);
  scanf("%d", &B);
  scanf("%d", &C);
  scanf("%d", &D);
  scanf("%d", &E);
  scanf("%d", &F);
  double density_max = -1.0;
  int water_ans, sugar_ans;
  std::vector<bool > water_enable(F+4, false);
  std::vector<bool > sugar_enable(F+4, false);
  for (int a=0; a<=3000; a++){
    for (int b=0; b<=3000; b++){
      //printf("=====================\n");
      //printf("a=%d, b=%d\n", a, b);
      int sum_water = 100*A*a+100*B*b;
      //printf("sum_water=%d\n", sum_water);
      if (sum_water>F) continue;
      water_enable[sum_water]=true;
    }
  }
  for (int c=0; c<=3000; c++){
    for (int d=0; d<=3000; d++){
      //printf("=====================\n");
      //printf("c=%d, d=%d\n", c, d);
      int sum_sugar = C*c+D*d;
      //printf("sum_sugar=%d\n", sum_sugar);
      if (sum_sugar>F) continue;
      sugar_enable[sum_sugar]=true;
    }
  }
  for (int i=0; i<=3000; i++){
    if (!water_enable[i]) continue;
    for (int j=0; j<=3000; j++){
      if (!sugar_enable[j]) continue;
      if (i+j>F) continue;
      if (i*E/100 < j) continue;
      if ((double)j/(double)(i+j)>density_max){
	density_max = (double)j/(double)(i+j);
	water_ans = i;
	sugar_ans = j;
      }
    }
  }
  std::cout << water_ans+sugar_ans << " " << sugar_ans << std::endl; 
  return 0;
}