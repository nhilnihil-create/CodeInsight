#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,n) for(ll i=0;i<=n;i++)
#define all(n) n.begin(),n.end()
#define yn(x) cout << (x ? "Yes":"No") << endl;


int main() {
  int k,s;
  cin >> k >> s;
  int cnt = 0;
  rep2(i,k){
    rep2(j,k){
      if((s-i-j)<=k && (s-i-j)>=0) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
