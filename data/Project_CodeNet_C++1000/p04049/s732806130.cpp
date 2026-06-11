#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

int main() {
  ll N, K;
  cin >> N >> K;

  vi A(N - 1), B(N - 1);
  for (ll i = 0; i < N - 1; i++) {
    cin >> A[i] >> B[i];
    A[i] -= 1;
    B[i] -= 1;
  }

  vvi G(N);
  for (ll i = 0; i < N - 1; i++) {
    G[A[i]].push_back(B[i]);
    G[B[i]].push_back(A[i]);
  }

  ll ans = 1ll << 30;

  if (K % 2 == 0) {
    for (ll i = 0; i < N; i++) {
      unordered_map<ll, ll> dist;
      queue<ll> q;
      q.push(i);
      dist[i] = 0;
      while (q.size()) {
        ll fr = q.front();
        q.pop();
        for (ll to: G[fr]) {
          if (dist.find(to) == dist.end()) {
            dist[to] = dist[fr] + 1;
            q.push(to);
          }
        }
      }
      ll cnt = 0;
      for (auto p: dist) {
        if (p.second > K / 2) {
          cnt += 1;
        }
      }
      ans = min(cnt, ans);
    }
  } else {
    for (ll i = 0; i < N - 1; i++) {
      unordered_map<ll, ll> dist;
      queue<ll> q;
      q.push(A[i]);
      q.push(B[i]);
      dist[A[i]] = 0;
      dist[B[i]] = 0;
      while (q.size()) {
        ll fr = q.front();
        q.pop();
        for (ll to: G[fr]) {
          if (dist.find(to) == dist.end()) {
            dist[to] = dist[fr] + 1;
            q.push(to);
          }
        }
      }
      ll cnt = 0;
      for (auto p: dist) {
        if (p.second > K / 2) {
          cnt += 1;
        }
      }
      ans = min(cnt, ans);
    }
  }

  cout << ans << endl;
}