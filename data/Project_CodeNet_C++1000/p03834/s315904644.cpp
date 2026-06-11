#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  string s;
  cin >> s;
  rep(i,5) cout << s[i];
  cout << " ";
  rep(i,7) cout << s[i+6];
  cout << " ";
  rep(i,5) cout << s[i+14];
}