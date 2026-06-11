#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n,x;
    cin >> n >> x;
    vector<ll> a(n),sum(n-1);
    ll ans = 0;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n-1; i++) sum[i] = a[i]+a[i+1];
    for(ll i = 0; i < n-2; i++){
        if(sum[i] > x){
            if(a[i+1] >= sum[i]-x){
                ans += sum[i]-x;
                a[i+1] -= sum[i]-x;
                sum[i+1] -= sum[i]-x;
                sum[i] = x;
            } else {
                ans += sum[i]-x;
                sum[i+1] -= a[i+1];
            }
        }
    }
    ans += max((ll)0,sum[n-2]-x);
    cout << ans << endl;
    return 0;
}