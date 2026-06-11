#include <bits/stdc++.h>
#define MAXN 110
#define pii  pair<int, int>
#define pll  pair<long long, long long>
#define ss second
#define ff first
 
using ll = long long;
using namespace std;
const int mod = 1e9 + 7;


int main(){
    ll n, a , b, ans = 0;

    cin >> n >> a >> b;
    vector<ll> v(n);

    for (ll& x: v) cin >> x;

    for (ll i=0; i<n-1; i++){
        ans+= min((v[i+1] - v[i])*a, b);
    }

    cout << ans << endl;
    return 0;
}