#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n, k;
  cin >> n >> k;
  int M = k;
  int a[n]; ll b[n];
  rep(i,n) {
    cin >> a[i] >> b[i];
    M = max(a[i],M);
  }
  int bit = 0;
  while(M > 0) {
    M /= 2;
    bit++;
  }
  vector<int> bitk;
  vector<vector<int>> bita(n);
  rep(i,n) {
    rep(j,bit) {
      bita[i].push_back(a[i]%2);
      a[i] /= 2;
    }
    reverse(bita[i].begin(),bita[i].end());  
  }
  rep(j,bit) {
    bitk.push_back(k%2);
    k /= 2;
  }
  reverse(bitk.begin(),bitk.end());
  ll ans = 0;
  rep(i,bit+1) {
    ll c = 0;
    if(i < bit) {
      if(bitk[i] == 1) {
        rep(j,n) {
          bool can = true;
          rep(l,i) {
            if(bita[j][l] == 1 && bitk[l] == 0) can = false;
          }
          if(bita[j][i] == 1) can = false;
          if(can) c += b[j];
        } 
      }
    } else {
      rep(j,n) {
        bool can = true;
        rep(l,bit) {
          if(bita[j][l] == 1 && bitk[l] == 0) can = false;
        }
        if(can) c += b[j];
      } 
    }
    ans = max(ans,c);
  }
  
  cout << ans << endl;
  return 0;
}