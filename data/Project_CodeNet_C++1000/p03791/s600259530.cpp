#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
constexpr ll MOD = ll(1e9+7);


int main(){
    ll n, ans = 1, d = 0;
    cin >> n;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    for(ll i=0;i<n;i++){
        ans *= i-d+1;
        ans %= MOD;
        d = max(d, (i*2+1-x[i]+1)/2);
    }
    cout << ans << endl;
    return 0;
}