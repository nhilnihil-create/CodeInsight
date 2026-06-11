#include <bits/stdc++.h>
#define rep(i, n) for(long long i = 0; i < n; i++)
using ll = long long;
using ld = long double;
using namespace std;
int main() {
  ll N, T, X;
  cin >> N >> T;
  X = T;
  vector<int>t(N), u(N - 1);
  rep(i, N) {cin >> t.at(i);}
  rep(i, N - 1) {u.at(i) = t.at(i + 1) - t.at(i);}
  rep(i, N - 1) {
    if (u.at(i) < T) {X += u.at(i);}
    else {X += T;}
  }
  cout << X << endl;
}
