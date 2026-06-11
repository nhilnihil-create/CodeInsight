#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

bool inline chmin(int &a, int b){ if( a > b){ swap(a,b); return true;} return false;}

vector<vector<int>> calcNext(const string &S){
  int n = S.size();
  vector<vector<int>> res(n+1,vector<int>(26,n));
  
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      res[i][j] = res[i+1][j];
    }
    res[i][S[i]-'a'] = i;
  }
  
  return res;
}

int main(){ 
  string A; cin >> A;
  int n = A.size();
  
  vector<int> dp(n+1,n+1); //最短でも長さがn+1より短くなるということはない
  vector<pair<char,int>> recon(n+1,{'?',n});
  
  auto next = calcNext(A);
  
  for(int i = n-1; i >= 0; i--){
    for(int j = 0; j < 26; j++){
      
      if( next[i][j] == n){ //i以降で文字a+jが出ることはない
        
        if( dp[i] > 1){
          dp[i] = 1; recon[i] = {'a'+j,next[i][j]+1};
                             }
        }
        else if( chmin(dp[i], dp[next[i][j]+1]+1)){
          dp[i] = dp[next[i][j]+1]+1;
          recon[i] = {'a'+j,next[i][j]+1};
        }
      }
    }
    
    int index = 0;
    string res = "";
    while(index < n){
      auto p = recon[index];
      res += p.first;
      index = p.second;
    }
    
    cout << res << endl; return 0;
  }
          