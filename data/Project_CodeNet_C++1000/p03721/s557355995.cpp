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
  ll N, K;
  cin >> N >> K;
  vector<Pi> Query(N);
  REP(i, N) cin >> Query.at(i).first >> Query.at(i).second;
  ll num = 0, tmp;
  sort(Query.begin(), Query.end());
  for (auto a : Query) {
    tmp = a.first;
    num += a.second;
    if (num >= K) {
      cout << tmp << endl;
      return 0;
    }
  }
  cout << tmp << endl;
  return 0;
}