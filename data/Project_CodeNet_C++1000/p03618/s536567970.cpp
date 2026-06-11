#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  string a;
  cin >> a;

  map<char, ll> ma;
  for (auto&& i : a) {
    ma[i]++;
  }

  ll ans = 1;
  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = i+1; j <= 'z'; j++) {
      ans += ma[i] * ma[j];
    }
  }

  cout << ans << endl;
}
