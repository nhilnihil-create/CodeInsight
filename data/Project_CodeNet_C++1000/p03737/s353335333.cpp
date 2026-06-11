#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  cout << char(s1.at(0) - 32) << char(s2.at(0) - 32) << char(s3.at(0) - 32)
       << endl;

  return 0;
}
