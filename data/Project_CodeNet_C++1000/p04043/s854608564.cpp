#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
const ll LINF = 1e18;

int main()
{
  map<int, int> m;
  int x;
  for (int i = 0; i < 3; ++i) {
    cin >> x; m[x]++;
  }
  if (m[5] == 2 && m[7] == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
