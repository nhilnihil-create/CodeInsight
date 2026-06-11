#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    ll a,b;cin>>a>>b;
    ll x[n];rep(i,n)cin>>x[i];
    ll ans = 0;
    rep(i,n-1)ans+=min((x[i+1]-x[i])*a,b);
    cout<<ans<<endl;
	return 0;
}