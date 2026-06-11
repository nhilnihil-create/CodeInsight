#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
ll xsum, ysum;
ll MOD = 1e9+7LL;
int main(){
    ll n,m; cin >> n >> m;
    REP(i,n){
        ll x; cin >> x;
        xsum += x * (i - (n-1-i));
    }
    xsum %= MOD;
    REP(i,m){
        ll y; cin >> y;
        ysum += y * (i - (m-1-i));
    }
    ysum %= MOD ;
    cout << xsum * ysum  % MOD << endl;

}