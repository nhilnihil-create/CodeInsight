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
  std::map<int, int > mp;
  std::vector<int> A(N), order(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
    mp[A[i]]=i;
  }
  int cnt = 0;
  for (auto entry : mp){
    order[entry.second] = cnt;
    cnt++;
  }
  int diff0=0;
  int diff1=0;
  for (int i=0; i<N; i++){
    //printf("i=%d, order=%d\n", i, order[i]);
    if (i%2==0){
      if (order[i]%2==1) diff0++;
    } else {
      if (order[i]%2==0) diff1++;
    }
  }
  std::cout << diff0 << std::endl;
  return 0;
}
