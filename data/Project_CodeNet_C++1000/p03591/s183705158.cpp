#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  string s; cin >> s;
  cout << (s.substr(0, 4) == "YAKI" ? "Yes" : "No") << endl;
}