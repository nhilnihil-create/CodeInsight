#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))


int main(){
    int n, k;   cin >> n >> k;
    vector<ll> a(n);
    REP(i, n)   cin >> a[i];

    ll res=LINF;
    REP(bit, 1<<n){
        ll maxi=0, sum=0, cnt=0;
        REP(j, n){
            if(bit & 1<<j){
                ll x = max(maxi-a[j]+1, 0LL);
                sum +=  x; cnt += 1;
                if(0<x) maxi += 1;
            }
            maxi = max(a[j], maxi);
            //cout << sum << ' ';
        }
        //cout << bit << ' ' << sum << endl;
        if(k<=cnt)
            res = min(res, sum);
    }
    cout << res << endl;
}
