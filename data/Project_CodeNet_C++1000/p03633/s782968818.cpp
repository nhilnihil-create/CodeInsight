#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
    int n;cin>>n;
    ll t[n];
    rep(i,n)cin>>t[i];
    
    ll ans=t[0];
    rep(i,n-1){
        ans = ans / __gcd(ans, t[i+1]) * t[i+1];
    }
    cout<<ans<<endl;
	return 0;
}