#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double getTime() {
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void print() {};

template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

ll get(ll a, ll b) {
  ll res = 1ll;
  while(b) {
    if(b & 1) res = (res * a) % MOD;
    b >>= 1ll;
    a = (a * a) % MOD;
  }
  return res;
}

int main() {
  int n; cin >> n;
  vector <ll> a(n);
  for(auto &x : a) cin >> x;
  ll sum = accumulate(a.begin(), a.end(), 0ll);
  ll cur = 0;
  ll ans = 1e16;
  for(int i = 0; i < n - 1; i++) {
    cur += a[i];
    ans = min(ans, abs(cur + cur - sum));
  }
  print(ans);
}