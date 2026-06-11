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
  Vl A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  if (A[0] % 2 == A[1] % 2 == A[2] % 2 == 1)
    cout << A[0] * A[1] << endl;
  else
    cout << 0 << endl;
}