#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//iに負けた人の番号をG[i]に格納
vector<ll> G[100000];

ll depth(ll n) {
  if (G[n].size() == 0) return 0;
  priority_queue<ll> que;
  for (ll i = 0; i < G[n].size(); i++) {
    ll p = G[n][i];
    que.push(depth(p));
  }
  ll res = 0;
  for (ll i = 0; i < G[n].size(); i++) {
    ll q = que.top(); que.pop();
    res = max(res, q+i+1);
  }
  return res;
}

int main() {
  ll N; cin >> N;
  for (ll i = 0; i < N-1; i++) {
    ll x; cin >> x; x--;
    G[x].push_back(i+1);
  }
  cout << depth(0) << endl;
}