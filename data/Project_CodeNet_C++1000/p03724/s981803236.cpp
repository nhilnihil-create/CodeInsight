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
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::map<int, int > mp;
  int a, b;
  for (int i=0; i<M; i++){
    scanf("%d", &a);
    scanf("%d", &b);
    mp[a]++;
    mp[b]++;
  }
  bool ok = true;
  for (auto &entry: mp){
    if (entry.second%2==1){
      ok=false;
      break;
    }
  }
  printf("%s\n", ok?"YES":"NO");
  return 0;
}
