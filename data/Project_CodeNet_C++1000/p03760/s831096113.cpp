#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string o,e;
  cin>>o>>e;
  
  int d = o.length() - e.length();
  
  rep(i,e.length()) {
    cout<<o[i]<<e[i];
  }
  
  if(d==1) {
    cout<<o[o.length()-1];
  }
  
  return 0;
}