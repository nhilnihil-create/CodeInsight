#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
unsigned gcd(unsigned a, unsigned b) {
  while(1) {
    if(a < b) swap(a, b);
    if(!b) break;
    a %= b;
  }
  return a;
}
int main(void){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    ll m=0,g;
    rep(0,i,n){
        cin>>a[i];
        m=max(m,a[i]);
        if(i==0) g=a[i];
        else g=gcd(g,a[i]);
        //cout<<g<<endl;
    }
    ll tmp=m;
    while(tmp>0){
        if(k==tmp){
            cout<<"POSSIBLE";
            return 0;
        }
        tmp-=g;
    }
    cout<<"IMPOSSIBLE";
}