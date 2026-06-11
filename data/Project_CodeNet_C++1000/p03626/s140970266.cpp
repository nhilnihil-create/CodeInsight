#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int main(){
  int N; cin >> N;
  string S1, S2; cin >> S1 >> S2;
  vector<int> t;
  char last = '0';
  int cnt = 1;
  ll ans = 1;
  rep(i,N){
    if(last != S1[i]){
      cnt = 1;
      t.pb(cnt);
      last = S1[i];
    }
    else{
      t.back()++;
    }
  }
  // for(auto x:t) cout << x << endl;
  rep(i,(int)t.size()){
    if(i==0){
      if(t[i] == 2) ans *= 2;
      continue;
    }
    if(t[i] == 1 && t[i-1] == 1){
      ans *= 2;
    }
    else if(t[i] == 1 && t[i-1] == 2){
      ans *= 1;
    }
    else if(t[i] == 2 && t[i-1] == 1){
      ans *= 2;
    }
    else {
      ans *= 3;
    }
    ans %= mod;
  }
  cout << (ans * 3) % mod << endl;
  return 0;
}
