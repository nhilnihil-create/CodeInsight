#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);rep(i,n)cin>>a[i];
    ll g=a[0];
    ll ma=a[0];
    REP(i,1,n){
        g=gcd(g,a[i]);
        ma=max(ma,a[i]);
    }
    if(k<=ma&&k%g==0){
        cout<<"POSSIBLE"<<endl;;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}