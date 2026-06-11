#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int main(){
    ll n, t;
    cin >> n >> t;
    ll m = LINF, dif = 0;
    vector<ll> a(n);
    REP(i,n){
        cin >>  a[i];
        m = min(m,a[i]);
        if(i!=0 && a[i] - m > dif){
                dif = a[i] - m;
        }
    }
    m = LINF;
    ll smtmp = 0;
    ll bgtmp = 0;
    ll ans = 0;
    REP(i,n){
        if(a[i] < m){
            m = a[i];
            if(smtmp & bgtmp) ans += max(smtmp, bgtmp);
            smtmp = 1;
            bgtmp = 0;
        }else if(a[i] == m){
            smtmp++;
        }
        if(i!=0 && a[i] - m == dif){
            bgtmp++;
        }
    }
    if(smtmp & bgtmp) ans += max(smtmp, bgtmp);
    cout << ans << endl;
}