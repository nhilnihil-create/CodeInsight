#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[300000];

const int inf = 1e8;

vector<vector<int>> makeCH(string S){
  int N = S.size();
  vector<vector<int>> res(N+1, vector<int>(26,N));
  // res[i][j] == Nは存在しないことを意味
  for(int i = N-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      res[i][j] = res[i+1][j];
    }
    res[i][S[i]-'a'] = i;
  }
  return res;
}
      

int main(){
  for(int i = 0; i < 300000; i++){ dp[i] = inf;}
  string A; cin >> A;
  int n = A.size();
  
  dp[n] = 1; //自明な初期値
  
  auto ch = makeCH(A); vector<pair<char,int>> recon(n+1, {'?',n});
  
  
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      
      if( ch[i][j] == n){ // A[i]以降、a+jが存在しない場合→一文字でいい
        if( dp[i] > 1){
          dp[i] = 1; recon[i] = {(char)(j+'a'), n};
        }
      }
      else{
        if( dp[i] > dp[ch[i][j]+1]+1){
          dp[i] = dp[ch[i][j]+1]+1; recon[i] = {(char)(j+'a'),ch[i][j]+1};
        }
      }
    }
  }
    
    int index = 0;
    string ans = "";
    while( index < n){
      auto p = recon[index];
      ans += p.first;
      index = p.second;
    }
    
    cout << ans << endl; return 0;
  }
      
        
         
  
  

        
      
      
      
  
  
  
  
  