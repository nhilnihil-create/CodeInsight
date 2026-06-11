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
  std::string S1, S2;
  std::cin >> S1;
  std::cin >> S2;
  int i=0;
  std::vector<int > input;
  while (i<N){
    if (S1[i]==S2[i]){
      input.push_back(0); // 0:縦
      i++;
    } else {
      input.push_back(1); // 1:横
      i+=2;
    }
  }
  long long ans = 1;
  long long mod = 1e9+7;
  for (int i=0; i<input.size(); i++){
    if (i==0){
      if (input[i]==0){
        ans *= 3;
      } else {
        ans *= 6;
      }
      ans %= mod;
    } else {
      if (input[i-1]==0 && input[i]==0){
        ans *= 2;
      } else if (input[i-1]==0 && input[i]==1){
        ans *= 2;
      } else if (input[i-1]==1 && input[i]==0){
        ans *= 1;
      } else if (input[i-1]==1 && input[i]==1){
        ans *= 3;
      }
      ans %= mod;
    }
  }
  //ans %= mod;
  //ans *= 6;
  printf("%lld\n", ans);
  return 0;
}
