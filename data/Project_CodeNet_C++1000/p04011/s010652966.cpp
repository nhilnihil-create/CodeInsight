#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll n,k,x,y;
void solve(){
    cin >> n >> k >> x >> y;
    ll ans = min(n,k)*x + (n-min(n,k))*y;
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t =1;
    while(t--)
        solve();
    return 0;
}

