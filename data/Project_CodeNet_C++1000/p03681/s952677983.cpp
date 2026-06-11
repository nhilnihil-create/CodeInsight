#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
#define NUM 1000000007
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ll n,m;
    cin>>n>>m;
    ll ans=1;
    if(abs(n-m)>1) ans=0;
    ll g=max(n,m),l=min(n,m);
    for(ll i=1;i<=l;i++){
        ans*=i*i;
        ans%=NUM;
    }
    for(ll i=l+1;i<=g;i++){
        ans*=i;
        ans%=NUM;
    }
    if(n==m) ans=(ans*2)%NUM;
    cout<<ans;
}