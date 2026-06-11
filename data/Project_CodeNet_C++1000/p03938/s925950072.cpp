#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

signed main(){
    ll n,m=0,x,A=0,B=0;cin>>n;
    vector<ll> s(n),a(n),b(n);

    rep(i,n){
        cin>>x;
        s[x-1]=i;
    }

    rep(i,n){
        if(A+B>=s[i]){
            A++;
            B=s[i]-A;
        }else{
            B--;
            A=s[i]-B;
        }
        a[i]=A;b[i]=B;
        m=min(m,B-1);
    }

    rep(i,n)cout<<a[i]-m<< (i==n-1 ? '\n':' ');

    rep(i,n)cout<<b[i]-m<< (i==n-1 ? '\n':' ');
    
}