#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep1(i, n) for(ll i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  ll n,a,b;
  cin >> n >> a >> b;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  ll ng = 0;
  ll ok = 1001001001;
  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2;
    ll dif = a-b;
    ll need = 0;
    rep(i,n){
      if(h[i] <= mid*b) continue;
      need += (h[i]-mid*b+dif-1)/dif;
    }
    if(need <= mid) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}