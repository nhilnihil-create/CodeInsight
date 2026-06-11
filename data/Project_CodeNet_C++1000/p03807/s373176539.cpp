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
  int N, odd = 0, even = 0;
  cin >> N;
  REP(i, N) {
    int tmp;
    cin >> tmp;
    if (tmp % 2 == 0)
      even++;
    else
      odd++;
  }
  if (odd % 2 == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}