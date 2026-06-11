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
  ll N, A, B;
  cin >> N >> A >> B;
  ll M = A + (N - 1) * B, m = (N - 1) * A + B;
  if (A > B || A != B && N < 2)
    cout << 0 << endl;
  else if (N == 2)
    cout << 1 << endl;
  else
    cout << M - m + 1 << endl;
}