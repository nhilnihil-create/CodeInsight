#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep2(i,a,b) for (ll i = (a); i < (b); ++i)

#define INF 1E18



int main(){
    vector<ll> a(3);
    rep(i,3) cin>>a[i];

    sort(a.begin(), a.end());

    if(a[2]%2==0)cout<<0<<endl;
    else cout<<a[0]*a[1]<<endl;

    return 0;
}