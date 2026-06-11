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

long long GCD(long long n, long long m){
  long long maxval = std::max(n, m);
  long long minval = std::min(n, m);
  if (maxval%minval==0){
    return minval;
  } else {
    return GCD(minval, maxval%minval);
  }
}

int main(){
  int N, K;
  scanf("%d", &N);
  scanf("%d", &K);
  std::vector<long long > A(N);
  long long max = -1;
  for (int i=0; i<N; i++){
    scanf("%lld", &A[i]);
    max = std::max(max, A[i]);
  }
  
  long long gcd = A[0];
  for (int i=1; i<N; i++){
    gcd = GCD(gcd, A[i]);
  }
  //printf("max=%lld, gcd=%lld\n", max, gcd);
  if (K>max || K%gcd!=0){
    printf("IMPOSSIBLE\n");
  } else {
    printf("POSSIBLE\n");
  }
  return 0;
}
