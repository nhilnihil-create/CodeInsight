#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#define ill long long
#define rep(i, a, b) for(ill i = (ill)(a); i < (ill)(b); i++)
#define fcout cout << fixed << setprecision(10)
using namespace std;

int main() {
  string s, t, r;
  cin >> s >> t >> r;
  if(s[(int)s.size()-1] == t[0] && t[(int)t.size()-1] == r[0]) cout << "YES\n";
  else cout << "NO\n";
}
