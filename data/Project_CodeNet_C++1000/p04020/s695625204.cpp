#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ans += a[i]/2;
        a[i] %= 2;
        if(i != n-1 && a[i+1] > 0 && a[i] != 0){
            a[i+1]--;
            ans++;
        }
        //cout << ans << " " << i << endl;
    }
    cout << ans << endl;
    return 0;
}