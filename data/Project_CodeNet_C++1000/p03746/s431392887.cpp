#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
typedef long long int ll;

ll N, M;
vector<ll> edges[200000];
deque<ll> q;
set<ll> s;

void f(ll cur) {
  for (auto ch : edges[cur])
    if (s.find(ch) == s.end()) {
      q.push_front(ch);
      s.insert(ch);
      f(ch);
      return;
    }
  return;
}

void b(ll cur) {
  for (auto ch : edges[cur])
    if (s.find(ch) == s.end()) {
      q.push_back(ch);
      s.insert(ch);
      b(ch);
      return;
    }
  return;
}

int main(void) {
  cin >> N >> M;
  rep(_, M) {
    ll a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  s.insert(1);
  q.push_back(1);
  f(1);
  b(1);
  cout << q.size() << endl;
  for (auto x : q) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
