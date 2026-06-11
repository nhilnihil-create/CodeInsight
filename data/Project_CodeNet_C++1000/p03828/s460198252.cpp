#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll n; cin >> n;
  map <ll, ll> score;
  for (ll i = 1; i <= n; i++) {
    ll tmp = i;
    for (ll j = 2; j*j <= tmp; j++) {
      if (tmp%j == 0) {
        if (!score.count(j)) score[j] = 0;
        while (tmp%j == 0){
          score.at(j)++;
          tmp /= j;
        }  
      }
    }
    if (tmp != 1) {
      if (score.count(tmp)) score.at(tmp)++;
      else score[tmp] = 1;
    }
  }
  ll res = 1;
  for (auto p : score) {
    res *= p.second+1;
    res %= mod;
  }
  cout << res << endl;
}