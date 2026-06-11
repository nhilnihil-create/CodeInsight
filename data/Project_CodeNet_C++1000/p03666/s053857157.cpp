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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  N -= 1;// Nを移動回数に

  ll tar = abs(B-A);

  ll O = (N-N/2) * C - (N/2) * D;
  
  tar -= O; // 原点を移動

  ll kai = tar / (C+D);

  if(tar >= (N/2) * (C+D)){
    tar -= (N/2) * (C+D);
  }else{
    tar = tar % (C+D);//原点より小さかったら
  }

  // tarが [0, N(D-C)]に入っていればOK

  if(0<=tar && tar <= N*(D-C)){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  
  return 0;
}
