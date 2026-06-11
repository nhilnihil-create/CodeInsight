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
  int N;
  scanf("%d", &N);
  std::vector<long long > A(N);
  std::vector<long long > sum(N);// i番目までの和
  for (int i=0; i<N; i++){
    scanf("%lld", &A[i]);
  }
  std::sort(A.begin(), A.end());
  sum[0]=A[0];
  for (int i=0; i<N-1; i++){
    sum[i+1] = sum[i]+A[i+1];
  }
  std::vector<bool > can(N, false);
  for (int i=0; i<N-1; i++){
    if (sum[i]*2>=A[i+1]){
      can[i]=true;
    } else {
      can[i]=false;
    }
  }
  can[N-1]=true;
  int ans = 0;
  int index = N-1;
  while(index>=0){
    if (can[index]){
      ans++;
    } else {
      break;
    }
    index--;
  }
  printf("%d\n", ans);
  return 0;
}
