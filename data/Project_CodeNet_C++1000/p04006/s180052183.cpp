#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 1000000000000000000
#define N 2100

vector<ll> sl(N);
vector<ll> minl(N);
ll n, x, y, a;

int main(){
    cin >> n >> x;
    REP(i,n) cin >> sl[i];
    ll ans = 0;
    REP(i,n) minl[i]=sl[i];
    REP(i,n) ans+=sl[i];
    FOR(i,1,n-1){
        ll ansl = i*x;
        REP(j,n){
            if (j-i<0) y=n+j-i;
            else y=j-i;
            minl[j]= min(minl[j],sl[y]);
            ansl+=minl[j];
        }
        ans = min(ansl,ans);
    }
    cout << ans << endl;
}