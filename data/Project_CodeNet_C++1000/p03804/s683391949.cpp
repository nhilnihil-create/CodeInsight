#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define MOD 1000000007

int main(void) {
  int n, m;
  cin >> n >> m;
  string a[n], b[m];
  rep(i,n)cin >> a[i];
  rep(i,m)cin >> b[i];
  bool key = true;

  for(int i = 0; i <= n-m; i++) {
    for(int j = 0; j <= n-m; j++) {
      key = true;
      for(int k = 0; k < m; k++) {
        if(b[k].compare(0,m,a[k+j],i,m) != 0) {
           key = false; break;
        }
      }
      if(key) {break;}
    }
    if(key)break;
  }
  if(key)
  cout << "Yes" << endl;
  else
  {
    cout << "No" << endl;
  }
  
}