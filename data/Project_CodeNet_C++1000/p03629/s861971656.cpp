#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> calcCH(string A){
  int N =  A.size();
  vector<vector<int>> res(N+1, vector<int>(26,N));
  //res[i][j]で、i以降に初めて'a'+jが出る位置　ここで存在しなければNとする
  
  for(int i = N-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){ 
      res[i][j] = res[i+1][j];
    }
     res[i][A[i]-'a'] = i;
  }
  
  return res;
}

int main(){
  string S; cin >> S;
  int N = (int) S.size();
  
  auto ch = calcCH(S);
  
  vector<int> dp(N+1, 1 << 29);
  
  vector<pair<char,int>> rec(N+1, {'?',N});
  
  dp[N] = 1;
  
  for(int i = N-1; i >= 0; i--){
     for(int j = 0; j < 26; j++){
      
      // 次の文字がないとき
      if( ch[i][j] == N){
        if( dp[i] > 1){
          rec[i] = {'a'+j, N};
          dp[i] = 1;
        }
      }
      
      //次の文字がある時
      else{
      if( dp[i] > dp[ch[i][j]+1]+1){
        rec[i] = {'a'+j, ch[i][j]+1};
        dp[i] = dp[ch[i][j]+1]+1;
      }
      }
     }
  }
    
    
    string ans = "";
    
    int index = 0;
    
    while( index < N){
      auto p = rec[index];
      
      ans += p.first;
      index = p.second;
    }
    
    cout << ans << endl; return 0;
  }

    
  