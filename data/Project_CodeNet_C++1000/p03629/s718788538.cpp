#include <bits/stdc++.h>
using namespace std;

int memo[200010][30];
int n;

int mm[200010];

int dfs(int idx){

  if(mm[idx] != -1){
    return mm[idx];
  }


  int mi = 17191727;

  for(int i = 0;i < 26;i++){
    if(memo[idx][i] != -1){
      mi = min(dfs(memo[idx][i]), mi);
    }else{
      return mm[idx] = 1;
    }
  }

  return mm[idx] = mi+1;
}


int kotae_size;
char kotae[300010] = {};

void ansSearch(int idx, int num){
  if(num+1 == kotae_size){
    for(int i = 0;i < 26;i++){
      if(memo[idx][i] == -1){
        kotae[num] = 'a' + i;
        kotae[num+1] = '\0';
        cout << kotae << endl;
        return;
      }
    }
  }

  for(int i = 0;i < 26;i++){
    if(mm[memo[idx][i]] == kotae_size-num-1){
      kotae[num] = 'a' + i;
      ansSearch(memo[idx][i], num+1);
      return;
    }
  }
}

int main(){
  memset(mm,-1,sizeof(mm));
  string s;
  cin >> s;

  n = s.size();

  for(int i = 0;i < 26;i++) memo[n][i] = -1;

  for(int i = n-1;i >= 0;i--){
    for(int j = 0;j < 26;j++){
      if(s[i]-'a' == j){
        memo[i][j] = i+1;
      }else{
        memo[i][j] = memo[i+1][j];
      }
    }
  }

  dfs(0);
  kotae_size = mm[0];
  ansSearch(0, 0);

  return 0;
}
