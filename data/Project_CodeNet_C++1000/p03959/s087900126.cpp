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
#include <utility>

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N), T(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  for (int i=0; i<N; i++){
    scanf("%d", &T[i]);
  }
  std::vector<int > fix(N, -1);
  std::vector<int > max(N, 1001001004);
  fix[0]=A[0];
  for (int i=1; i<N; i++){
    if (A[i]>A[i-1]){
      fix[i]=A[i];
    } else {
      max[i]=A[i];
    }
  }
  if (fix[N-1]!=-1 && fix[N-1]!=T[N-1]){
    printf("0\n");
    return 0;
  }
  fix[N-1]=T[N-1];
  for (int i=N-2; i>=0; i--){
    if (T[i]>T[i+1]){
      if (fix[i]!=-1 && fix[i]!=T[i]){
	printf("0\n");
	return 0;
      } else if (T[i]>max[i]){
	printf("0\n");
	return 0;
      } else {
	fix[i]=T[i];
      }
    } else {
      max[i]=std::min(max[i], T[i]);
    }
  }
  long long ans = 1;
  long long mod=1e9+7;
  for (int i=0; i<N; i++){
    if (fix[i]!=-1) continue;
    ans *= max[i];
    ans %= mod;
  }
  std::cout << ans << std::endl;
  return 0;
}
