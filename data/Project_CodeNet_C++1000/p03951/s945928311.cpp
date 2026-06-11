#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  int ans;
  for(int i=0; i<=n; i++) {
    if(s.substr(n-i,i)==t.substr(0,i)) {
      ans=2*n-i;
    }
  }
  cout << ans << endl;
}