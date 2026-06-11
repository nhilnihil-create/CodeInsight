#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);

const int MAX=200010;


ll binary_power(ll a, ll n) {
    if (n==0) return 1;
    ll k=binary_power(a,n/2);
    if (n%2==0) return k*k;
    else return k*k*a;
}


int main() {
    ios_base::sync_with_stdio(false); 

    int n,p;
    cin >> n >> p;
    int odd=0,even=0;
    rep(i,n) {
        int a;
        cin >> a;
        if (a%2==0) ++even;
        else ++odd;
    }
    ll ans;
    if (odd==0) {
        if (p==0) ans=binary_power(2,n);
        else ans=0;
    } else {
        ans=binary_power(2,n-1);
    }
    cout << ans << endl;

    return 0;
}
