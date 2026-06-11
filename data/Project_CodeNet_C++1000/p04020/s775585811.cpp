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
int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  long long ans = 0;
  for (int i=0; i<N; i++){
    if (i>0){
      ans += std::min(A[i-1], A[i]);
      A[i] -= std::min(A[i-1], A[i]);
    }
    ans += A[i]/2;
    A[i] = A[i]%2;
  }
  std::cout << ans << std::endl;
  return 0;
}
