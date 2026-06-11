#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  string s,ss = "CODEFESTIVAL2016";
  cin >> s;
  int ans = 0;
  rep(i,0,s.size()) if(s[i] != ss[i]) ans++;
  cout << ans << endl;
}