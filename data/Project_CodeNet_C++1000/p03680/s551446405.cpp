#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  rep(i, N) {
    cin >> vec.at(i);
  }
  int co = 1;
  int co2 = 0;
  int con = 0;
  int coa = 0;
  while(true) {
    co2 = vec.at(co - 1);
    con++;
    vec.at(co - 1) = 0;
    co = co2;
    if(co2 == 0) {
      coa = 1;
      break;
    }
    if(co2 == 2) {
      break;
    }
  }
  if(coa == 1) {
    cout << -1 << endl;
  }
  else {
    cout << con << endl;
  }
}
