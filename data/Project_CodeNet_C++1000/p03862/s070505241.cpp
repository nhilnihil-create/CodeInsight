#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n;
    ll x;
    cin>>n>>x;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    vector<ll> v2 = v;
    ll ans1 = 0;
    ll ans2 = 0;
    rep(i, n-1){
        if(v[i] + v[i+1]>x){
            ll s = v[i];
            ll t = v[i+1]; 
            ll a = min(t, s+t-x);
            v[i+1] -= a;
            v[i] -= (s+t-x)-a;
            ans1 += s+t-x;
        }
    }
    reverse(v2.begin(), v2.end());
    rep(i, n-1){
        if(v2[i] + v2[i+1]>x){
            ll s = v2[i];
            ll t = v2[i+1]; 
            ll a = min(t, s+t-x);
            v2[i+1] -= a;
            v2[i] -= (s+t-x)-a;
            ans2 += s+t-x;
        }
    }
    cout<<min(ans1, ans2)<<endl;
    return 0;
}