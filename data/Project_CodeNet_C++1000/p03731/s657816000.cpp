#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int main() {
    int x,y;cin >> x >> y;
    ll ans = 0; int a[x];
    for(int i = 0;i < x;i++){
        cin >> a[i];
    }
    for(int i = 1;i < x;i++){
        ans+=min(y,a[i]-a[i-1]);
    }
    cout << ans+y;
}

