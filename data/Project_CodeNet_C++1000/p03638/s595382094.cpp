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
    ll h,w;cin>>h>>w;
    ll n;cin>>n;
    ll ans[h][w];
    ll id1 =0, id2=0;
    REP(i,n){
        ll cnt;cin>>cnt;
        REP(j,cnt){
            ans[id1][id2] = i+1;
            if(id1 % 2==0 && id2<w-1) id2++;
            else if (id1 % 2==0 && id2==w-1) id1++;
            else if(id1%2==1 && id2>0) id2--;
            else if(id1%2==1 && id2==0) id1++;
        }
    }
    REP(i,h){
        REP(j,w) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
