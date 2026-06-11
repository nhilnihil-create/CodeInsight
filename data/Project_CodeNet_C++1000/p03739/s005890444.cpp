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
  std::vector<int > A(N);
  for (int i=0; i<N; i++) {
    scanf("%d", &A[i]);
  }
  long long ans = 1e18;
  long long sum;
  int target[2]={1, 0};
  for (int j=0; j<2; j++){
    long long add = 0;
    sum=0;
    for (int i=0; i<N; i++){
      //printf("i=%d\n", i);
      sum += A[i];
      //printf("sum=%lld\n", sum);
      if (i%2==target[j]){
	// target = 1;
	if (sum<1){
	  add += 1-sum;
	  sum=1;
	  //printf("add=%lld\n", add);
	}
      } else {
	// target = -1
	if (sum>-1){
	  add += sum+1;
	  sum=-1;
	  //printf("add=%lld\n", add);
	}
      }
    }
    //printf("add=%lld\n", add);
    ans = std::min(ans, add);
  }
  std::cout << ans << std::endl;
  return 0;
}
