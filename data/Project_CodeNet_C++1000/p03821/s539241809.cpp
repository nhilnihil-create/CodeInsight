#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) cin >> a.at(i) >> b.at(i);

  ll ans=0;
  rep(i,n){
    int j = n-1-i;
    int r = (a.at(j)+ans)%b.at(j);
    if(r!=0) ans += b.at(j)-r;
  }

  cout << ans;
}