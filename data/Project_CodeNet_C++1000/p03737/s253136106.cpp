#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  string a, b, c;
  cin >> a >> b >> c;

  char dif = 'A' - 'a';
  cout << char(a.at(0) + dif) << char(b.at(0) + dif) << char(c.at(0) + dif) << endl;
}
