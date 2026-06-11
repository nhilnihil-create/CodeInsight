#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  string s;
  cin >> s;
  if(s.at(0) == '0' + 9 || s.at(1) == '0' + 9) cout << "Yes" << endl;
  else cout << "No" << endl; 
}