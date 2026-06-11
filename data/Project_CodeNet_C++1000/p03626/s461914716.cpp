#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <math.h>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

struct edge{
  ll to;
  ll cost;
};

int solve() {
  ll n;
  string a1,s2;
  cin >> n;
  vector<vector<char> > s(2, vector<char> (n));
  for(ll i = 0;i < 2; i++){
    for(ll j = 0;j < n; j++){
      cin >> s[i][j];
    }
  }
  const ll MOD = 1000000007;
  // cout << MOD <<endl;
  ll lasttype = 0;
  ll type = 0;
  // x = 1, y = 2
  ll ans = 1;
  for(ll j = 0;j < n; j++){
    if(s[0][j] == s[1][j]){
      type = 1;
    }else{
      // cout << s[0][i] << " " << s[1][i] << endl;
      j++;
      type = 2;
    }
    if(lasttype == 0 && type == 1){
      ans *= 1;
    }else if(lasttype == 0 && type == 2){
      ans = (ans * 2) % MOD;
    }else if(lasttype == 1 && type == 1){
      ans = (ans * 2) % MOD;
    }else if(lasttype == 1 && type == 2){
      ans = (ans * 2) % MOD;
    }else if(lasttype == 2 && type == 1){
      ans *= 1;
    }else if(lasttype == 2 && type == 2){
      ans = (ans * 3) % MOD;
    }
    lasttype = type;
  }
  cout << (ans * 3) % MOD << endl;
  return 0;
}


int main(void){
  solve();
  return 0;
}
