#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string s;
  ll n;
  cin >> s >> n;
  rep(i, s.size()-1) {
    if (s.at(i) == 'a') continue;
    ll num = 'z' - s.at(i);
    if (n >= num+1) {
      s.at(i) = 'a';
      n -= num+1;
    }
  }
  ll num = s.at(s.size()-1) - 'a';
  n += num;
  n %= 26;
  char c = 'a' + n;
  s.at(s.size()-1) = c;
  cout << s << endl;
}