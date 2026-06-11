#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

vector<int> G[MAX_N];
int used[MAX_N];

bool dfs(int u, int cri, ll& sz){
    bool nbi = false;
    used[u] = cri;
    sz++;
    each(v, G[u]){
        if(used[v] == 0){
            nbi |= dfs(v, 3-cri, sz);
        }else if(used[v] == cri){
            nbi = true;
        }
    }
    return nbi;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b), G[b].pb(a);
    }
    ll bi = 0, al = 0;
    vector<pll> vec;
    rep(i,n){
        if(!used[i]){
            ll sz = 0;
            if(dfs(i, 1, sz)){
                vec.pb(pll(sz, 0));
            }else{
                if(sz == 1) continue;
                vec.pb(pll(sz, 1));
                bi++;
            }
            al += sz;
        }
    }
    ll ans = (ll)n*n;
    rep(i,len(vec)){
        ans -= vec[i].fi*al-len(vec);
        if(vec[i].se){
            ans += bi;
        }
    }
    cout << ans << "\n";
    return 0;
}
