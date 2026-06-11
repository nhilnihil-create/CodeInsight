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
  std::string S;
  std::cin >> S;
  int K;
  scanf("%d", &K);
  int n = S.length();
  std::string ans;
  for (int i=0; i<n; i++){
    int value = int(S[i])-int('a');
    if (value==0) {
      ans += S[i];
    } else if (K>=26-value){
      ans += 'a';
      K -= 26-value;
    } else {
      ans += S[i];
    }
  }
  //printf("K=%d\n", K);
  if (K>0) {
    int value = int(ans[n-1])-int('a');
    value += K%26;
    value %=26;
    ans[n-1] = 'a'+value;
  }
  std::cout << ans << std::endl;
  return 0;
}
