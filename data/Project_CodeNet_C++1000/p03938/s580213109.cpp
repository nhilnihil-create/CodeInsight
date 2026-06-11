#include <bits/stdc++.h>
#define INF 100000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main()
{
  ll N;
  cin >> N;
  vector<ll> p(N);
  for (ll i = 0; i < N; ++i) {
    cin >> p.at(i);
  }
  vector<ll> order(N);
  for (ll i = 0; i < N; ++i) {
    order.at(p.at(i) - 1) = i + 1;
  }
  vector<ll> a = order;
  vector<ll> b = order;
  for (ll i = 0; i < N - 1; ++i) {
    a.at(i + 1) += a.at(i);
  }
  for (ll i = N - 1; i >= 1; --i) {
    b.at(i - 1) += b.at(i);
  }
  for (ll i = 0; i < N; ++i) {
    cout << a.at(i) << ' ';
  }
  cout << endl;
  for (ll i = 0; i < N; ++i) {
    cout << b.at(i) << ' ';
  }
  cout << endl;
}
