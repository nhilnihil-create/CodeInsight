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
  std::string s;
  std::cin >> s;
  std::vector<int > ans(N+4);
  // 1 sheep, 0 wolf
  int init1[4]={0, 0, 1, 1};
  int init2[4]={0, 1, 0, 1};
  
  for (int i=0; i<4; i++){
    ans[0]=init1[i];
    ans[1]=init2[i];
    for (int j=2; j<N; j++){
      if (s[j-1]=='o'){
	if (ans[j-1]==1){
	  ans[j]=ans[j-2];
	} else {
	  ans[j]=1-ans[j-2];
	}
      } else {
	if (ans[j-1]==1){
	  ans[j]=1-ans[j-2];
	} else {
	  ans[j]=ans[j-2];
	}
      }
    }
    // last check
    bool check=true;
    int index[2]={0, N-1};
    for (int j=0; j<2; j++){
      int i=index[j];
      if (s[i]=='o'){
	if (ans[i]==1){
	  if (ans[(i+N-1)%N]!=ans[(i+1)%N]){
	    check=false;
	  }
	} else {
	  if (ans[(i+N-1)%N]==ans[(i+1)%N]){
	    check=false;
	  }
	}
      } else {
	if (ans[i]==1){
	  if (ans[(i+N-1)%N]==ans[(i+1)%N]){
	    check=false;
	  }
	} else {
	  if (ans[(i+N-1)%N]!=ans[(i+1)%N]){
	    check=false;
	  }
	}
      }
    }
    if (check){
      for (int i=0; i<N; i++){
	printf("%c", ans[i]?'S':'W');
      }
      printf("\n");
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}