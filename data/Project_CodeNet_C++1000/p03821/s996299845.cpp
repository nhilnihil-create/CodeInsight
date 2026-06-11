#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
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
  int A[N], B[N];
  REP(i, N) cin >> A[i] >> B[i];
  ll count = 0;
  for (int i = N - 1; i >= 0; i--) {
    if ((A[i] + count) % B[i] == 0) continue;
    count += B[i] - ((A[i] + count) % B[i]);
  }
  cout << count << endl;
}