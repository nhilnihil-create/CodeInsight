#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

int main(){
    int n;  cin >> n;
    vector<ll> a(n);
    REP(i, n) cin >> a.at(i);
    
    ll ans=0;
    FORD(i, n-1, 1){
        ans += a[i]/2;
        a[i] %= 2; 
        ll x = min(a[i], a[i-1]);
        ans += x;
        a[i-1] -= x;
        
        //cout << ans << ' ' << a[i-1] << ' ' << a[i] << endl;
    }
    cout << ans+a[0]/2 << endl;
}