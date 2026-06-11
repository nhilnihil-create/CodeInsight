#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
#define rep1(i, n) for (ll i=0; i<(n); i++) 
#define rep2(i, k, n) for (ll i=k; i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    ll n;
    cin >> n;
    map<ll, ll> m;
    rep1(i, n){
        ll a;
        cin >> a;
        m[a]++;
    }
    ll init = (n%2==0);
    for (ll i=init; i<n; i+=2){
        if (i==0){
            if (m[i]!=1){
                cout << 0 << endl;
                return 0;
            }
        }
        else if (m[i]!=2){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    rep1(i, n/2){
        ans *= 2;
        ans %= MOD;
    }
    cout << ans << endl;
    //printf("%.12f", ans);
}