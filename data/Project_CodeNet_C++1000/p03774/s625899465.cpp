#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  int n, m;
  cin >> n >> m;
  ll a[n], b[n], c[m], d[m];
  rep(i, n) {
    cin >> a[i] >> b[i];
   }
  rep(i, m){
    cin >> c[i] >> d[i];
  }
  ll ans[n];

  rep(i, n){
    ll kyori = 4 * pow(10, 8) + 1;
    int num = 0;
    rep(j, m){
      ll man = abs(a[i]-c[j]) + abs(b[i]-d[j]);
      if (man < kyori){
        kyori = man;
        num = j+1;
      }
    }
    ans[i] = num;
  } 
  rep(i, n) cout << ans[i] << endl;
}