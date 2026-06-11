#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll x, ll y) { return (x / __gcd(x, y)) * y; }

int main() {
  int n;
  cin >> n;
  queue<ll> que;
  for (int i = 0; i < n; i++) {
    ll temp;
    cin >> temp;
    que.push(temp);
    if (que.size() == 2) {
      ll a = que.front();
      que.pop();
      ll b = que.front();
      que.pop();
      que.push(lcm(a, b));
    }
  }
  cout << que.front() << endl;
}