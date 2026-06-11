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
  ll a, b;
  cin >> a >> b;
  if (a <= 0 && b >= 0)
    cout << "Zero" << endl;
  else if (a > 0 || (min(b, (ll)0) - a) % 2 == 1)
    cout << "Positive" << endl;
  else
    cout << "Negative" << endl;
}