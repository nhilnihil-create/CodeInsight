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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N;
  cin >> N;
  vi a(N);
  REP(i, N) cin >> a.at(i);
  int ad2 = 0, ad4 = 0, noad = 0;
  REP(i, N) {
    if (a.at(i) % 4 == 0)
      ad4++;
    else if (a.at(i) % 2 == 0)
      ad2++;
    else
      noad++;
  }
  if (noad == 0 || noad <= ad4 || N - noad == ad4 && noad == ad4 + 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}