#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

ll COM(int n, int k) {
  ll res = 1;
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  for (int i = 0; i < k; i++) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  ll N, odd = 0, even = 0, ans = 0;
  int P;
  cin >> N >> P;
  vi A(N);
  REP(i, N) {
    cin >> A.at(i);
    if (A.at(i) % 2 == 0)
      even++;
    else
      odd++;
  }
  ll ALL = (ll)pow(2, N), allevens = (ll)pow(2, even);
  // cout << "odd = " << odd << " even = " << even << endl;

  REP(i, odd + 1) {
    if (i % 2 == 0) continue;
    ans += COM(odd, i) * allevens;
    //  cout << "i = " << i << " ans = " << ans << endl;
  }
  if (P == 1)
    cout << ans << endl;
  else
    cout << ALL - ans << endl;
}