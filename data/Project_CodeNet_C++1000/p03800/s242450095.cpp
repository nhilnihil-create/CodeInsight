#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int N;
string s;
vector<int> ans;

bool solve(){
  FOR(i, 1, N-1){
    if(ans[i] == 0){
      if(s[i] == 'o'){
        ans[i+1] = (ans[i-1] + 1) % 2;
      }
      else{
        ans[i+1] = ans[i-1];
      }
    }
    else{
      if(s[i] == 'o'){
        ans[i+1] = ans[i-1];
      }
      else{
        ans[i+1] = (ans[i-1] + 1) % 2;
      }
    }
  }
  if((ans[N-1] == 0 && s[N-1] == 'o') || (ans[N-1] == 1 && s[N-1] == 'x')){
    if(ans[N-2] != ans[0]){
      if(ans[0] == 0 && s[0] == 'o' || ans[0] == 1 && s[0] == 'x'){
        return ans[N-1] != ans[1];
      }
      else{
        return ans[N-1] == ans[1];
      }
    }
    else{
      return false;
    }
  }
  else{
    if(ans[N-2] == ans[0]){
      if(ans[0] == 0 && s[0] == 'o' || ans[0] == 1 && s[0] == 'x'){
        return ans[N-1] != ans[1];
      }
      else{
        return ans[N-1] == ans[1];
      }
    }
    else{
      return false;
    }
  }
}

int main(){
  cin >> N;
  cin >> s;
  ans.resize(N, 0);
  
  REP(i, 2){
    REP(j, 2){
      ans[0] = i, ans[1] = j;
      if(solve()){
        REP(i, N){
          cout << (ans[i] ? 'S': 'W');
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}
