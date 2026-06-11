#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int numa = 0;
  int numb = 0;
  rep(i, n) {
    if(s.at(i) == 'a') {
      if(numa < a + b) {
        cout << "Yes" << endl;
        numa++;
      }
      else cout << "No" << endl;
    }
    else if(s.at(i) == 'b') {
      if(numa < a + b && numb < b) {
        cout << "Yes" << endl;
        numa++;
        numb++;
      }
      else {
        numb++;
        cout << "No" << endl;
      }
    }
    else cout << "No" << endl;
  }
}