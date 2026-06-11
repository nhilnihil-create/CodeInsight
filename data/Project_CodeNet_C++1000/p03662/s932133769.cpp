#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;

int main() {
  ll N;
  cin >> N;

  vi a(N - 1), b(N - 1);
  for (ll i = 0; i < N - 1; i++) {
    cin >> a[i] >> b[i];
    a[i] -= 1;
    b[i] -= 1;
  }

  vector<unordered_set<ll>> G(N);
  for (ll i = 0; i < N - 1; i++) {
    G[a[i]].insert(b[i]);
    G[b[i]].insert(a[i]);
  }

  vi v(N);
  queue<ll> q1, q2;
  q1.push(0);
  q2.push(N - 1);
  v[0] = 1;
  v[N - 1] = 2;

  while (true) {
    if (q1.size() + q2.size() == 0) {
      break;
    }

    for (ll i = q1.size(); i > 0; i--) {
      ll fr = q1.front();
      q1.pop();
      for (ll to: G[fr]) {
        if (v[to] == 0) {
          v[to] = 1;
          q1.push(to);
        }
      }
    }

    for (ll i = q2.size(); i > 0; i--) {
      ll fr = q2.front();
      q2.pop();
      for (ll to: G[fr]) {
        if (v[to] == 0) {
          v[to] = 2;
          q2.push(to);
        }
      }

    }
  }

  ll cnt1 = 0, cnt2 = 0;
  for (ll i: v) {
    if (i == 1) cnt1 += 1;
    else if (i == 2) cnt2 += 1;
  }

  if (cnt1 > cnt2) {
    cout << "Fennec" << endl;
  } else {
    cout << "Snuke" << endl;
  }
}