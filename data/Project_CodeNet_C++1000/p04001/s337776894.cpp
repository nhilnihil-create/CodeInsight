#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long many_number(string n, string s, int a) {
  if (a == n.size()) {
    string e = "";
    long d = 0;
    rep (i, s.size()) {
      if (s.at(i) == '+'){
        d += atol(e.c_str());
        e = "";
      }
      else {
        e += s.at(i);
      }
    }
    d += atol(e.c_str());
    return d;
  }
  
  return many_number(n, s + '+' + n.at(a), a + 1) +
  many_number(n, s + n.at(a), a + 1);

}

int main() {
  string n;
  cin >> n;
  string a;
  a = n.at(0);
  cout << many_number(n, a, 1) << endl;
}