#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rrep(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

int keta(ll n) {
  int cnt = 0;
  while (n > 0) {
    n /= 10;
    cnt++;
  }
  return cnt;
}

int f(ll a, ll b) {
  int na = keta(a);
  int nb = keta(b);
  return max(na,nb);
}

int main() {
  ll n;
  cin >> n;
  int ans = 10000;
  ll i = 0ll;
  while(i*i < n) {
    i++;
    if (n % i == 0) {
      int num = f(i, n/i);
      if (num < ans) ans = num;
    }
  }
  cout << ans << endl;
}
