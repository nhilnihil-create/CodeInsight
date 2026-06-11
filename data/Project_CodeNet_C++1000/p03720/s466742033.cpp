#define _GLIBCXX_DEBUG //エラーを出すためのおまじない
#include <bits/stdc++.h>
//#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
#include <math.h>
using namespace std;
#define coYES cout << "YES" << endl
#define coNO cout << "NO" << endl
#define coYes cout << "Yes" << endl
#define coNo cout << "No" << endl
#define coyes cout << "yes" << endl
#define cono cout << "no" << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  rep(i, m) {
    int numa, numb;
    cin >> numa >> numb;
    a.at(i) = numa;
    b.at(i) = numb;
    //cout << a.at(i) << b.at(i) << endl;
  }
  vector<int> city(n+1, 0);
  rep(i, m) {
    city.at(a.at(i))++;
    city.at(b.at(i))++;
  }
  rep(i, n) {
    cout << city.at(i+1) << endl;
  }
}
