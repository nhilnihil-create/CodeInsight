#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>> makeCH(string A){
  int n = A.size();
  
  vector<vector<int>> res(n+1, vector<int>(26,n));
 
  
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      
      res[i][j] = res[i+1][j];
      
      res[i][A[i]-'a'] = i;
    }
  }
  
  return res;
}
      
int main(){
  string S; cin >> S;
  
  int N = (int) S.size();
  
  auto ch = makeCH(S);
  
  vector<int> dp(N+1, N);
  vector<pair<char,int>> recon(N+1,{'?',N});
  
  for(int i = N-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      
      //次の文字がない場合
      if( ch[i][j] == N){
        if( dp[i] > 1){
         dp[i] = 1; recon[i] = {'a'+j, N};
        }
      }
      //次の文字がある場合
      else{
        if( dp[i] > dp[ch[i][j]+1]+1){
          dp[i] = dp[ch[i][j]+1]+1; 
          recon[i] = {'a'+j, ch[i][j]+1};
        }
      }
    }
  }
  
  int index = 0;
  string res = "";
  while( index < N){
    auto p = recon[index];
    
    res += p.first;
    index = p.second;
  }
  
  cout << res << endl;
  
  return 0;
}
    
    
        
        
      
      
      
  
  
  
  
  