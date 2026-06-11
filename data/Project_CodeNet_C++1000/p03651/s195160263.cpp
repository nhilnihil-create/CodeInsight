#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    int mx=0;
    rep(i,n)cin>>a[i],mx=max(mx,a[i]);
    if(n==1){
        if(k==a[0])cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    if(k>mx){cout<<"IMPOSSIBLE"<<endl; return 0;}
    rep(i,n)if(a[i]==k){cout<<"POSSIBLE"<<endl; return 0;}
    int g=__gcd(a[0],a[1]);
    rep(i,n){
        g=__gcd(g,a[i]);
    }
    if(k%g==0)cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}