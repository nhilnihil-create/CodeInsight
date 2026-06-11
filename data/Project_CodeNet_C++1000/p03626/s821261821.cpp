#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

const ll MOD = 1000000007;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string S1, S2;
  cin >> S1 >> S2;

  vector<int> op;
  for(int i = 0; i < S1.length(); i++){
    if(S1[i] != S2[i]){
      op.push_back(1);
      i++;
    }else{
      op.push_back(0);
    }
  }

  ll ans;
  if(op[0] == 0){
    ans = 3;
  }else{
    ans = 6;
  }

  for(int i = 0; i + 1 < op.size(); i++){
    if(op[i] == 0 && op[i+1] == 0){
      ans = (ans * 2) % MOD;
    }else if(op[i] == 0 && op[i+1] == 1){
      ans = (ans * 2) % MOD;
    }else if(op[i] == 1 && op[i+1] == 1){
      ans = (ans * 3) % MOD;
    }
  }

  cout << ans << endl;

  return 0;
}
