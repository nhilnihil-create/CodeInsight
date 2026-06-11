#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  if(n==m) {
    rep(i,n) {
      if(a[i]!=b[i]) {
        cout << "No" << endl;
        return 0;
      }
      cout << "Yes" << endl;
      return 0;
    }
  }
  rep(i,n-m) {
    rep(j,n-m) {
      bool ok=true;
      rep(k,m) {
        rep(l,m) {
          if(a[i+k][j+l]!=b[k][l]) {
            ok=false;
            break;
          }
        }
        if(!ok) break;
      }
      if(ok) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}