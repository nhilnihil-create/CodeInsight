#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  string f = s.substr(0, 5);
  string S= s.substr(6, 7);
  string t = s.substr(14, 5);
  cout << f << " " << S << " " << t << endl;
}