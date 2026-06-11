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
    ll n;
    cin>>n;
    vector<vector<P>> p(n);
    REP(i,n-1){
        ll a,b,c;cin>>a>>b>>c;
        a--; b--;
        p[a].push_back(make_pair(b,c));
        p[b].push_back(make_pair(a,c));
    }
    ll q,k;cin>>q>>k;
    k--;

    ll dis[n];
    REP(i,n) dis[i] = inf;
    dis[k] = 0;

    stack<ll> st;
    st.push(k);
    while(st.size()){
        ll now = st.top();
        st.pop();
        for(auto nex: p[now]){
            if (dis[nex.first]!=inf) continue;
            st.push(nex.first);
            dis[nex.first] = dis[now]+nex.second;
        }
    }

    REP(i,q){
        ll x,y;cin>>x>>y; 
        x--; y--;
        cout<<dis[x] + dis[y]<<endl;
    }
    return 0;
}
