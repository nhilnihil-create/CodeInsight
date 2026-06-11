#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;
const ll inf = 1e15;
ll power(ll a,ll b){return b?power(a*a%mod,b/2)*(b%2?a:1)%mod:1;}


int main(){FIN

    double base = 0;
    ll a,b,c,d,e,f; cin>>a>>b>>c>>d>>e>>f;
    ll ans0 = 0;
    ll ans1 = 0;
    ll ans2 = 0;
    FOR(i,0, f/(100*a) + 1){
        FOR(j,0, f / (100*b) + 1){
            FOR(s, 0, f / c + 1){
                FOR(t, 0, f / d + 1){
                    if(i==0 && j==0) continue;
                    if (100*a*i + 100*b*j + c*s + d*t > f) continue;
                    if ((c*s+d*t) > ((a*i+b*j) * e)) continue;
                    if (base <= double(c*s+d*t) / double(a*i+b*j)){
                        base = double(c*s+d*t) / double(a*i+b*j);
                        ans0 = 100*a*i + 100*b*j + c*s + d*t;
                        ans1 = c*s + d*t;
                        ans2 = s + t;
                    }
                }
            }
        }
    }
    cout<<ans0<<' '<<ans1<<endl;
    // cout<<ans2<<endl;
    return 0;
}
