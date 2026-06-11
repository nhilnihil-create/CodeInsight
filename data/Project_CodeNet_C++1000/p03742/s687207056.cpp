 //#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <time.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

const ll nmax = 1e9 + 7;
const ll Mod = 998244353;
const double PI = 2 * asin(1);

ll Pow(ll A, ll B, ll mod){
  if (B == 0) return 1;
  else{
    if (B % 2 == 0){
      return Pow(A * A % mod, B / 2, mod) % mod;
    }else{
      return A * Pow(A * A % mod, B / 2, mod) % mod;
    }
  }
}

ll nCr(ll N, ll C, ll mod){
  ll ans = 1; C = min(C, N - C);
  for (ll i = 1; i <= C; i++){
    ans *= N - i + 1; ans %= mod;
    ans *= Pow(i, mod - 2, mod); ans %= mod;
  }
  return ans;
}

int main(){
  ll X, Y; cin >> X >> Y;
  if (abs(X - Y) <= 1){
    cout << "Brown" << endl;
  }else{
    cout << "Alice" << endl;
  }
  
  return 0;
}
