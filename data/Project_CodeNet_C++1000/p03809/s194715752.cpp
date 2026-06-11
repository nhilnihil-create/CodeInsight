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
#define sar(a,n) cout<<#a<<":";rep(kbrni,n)cout<<" "<<a[kbrni];cout<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define svecp(v) cout<<#v<<":";each(kbrni,v)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

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
vi a;

int dfs(int u,int p)
{
    vi vec;
    int nx = 0;
    each(v,G[u]){
        if(v != p){
            nx++;
            int res = dfs(v,u);
            if(res < 0){
                return -1;
            }else{
                vec.pb(res);
            }
        }
    }
    if(nx == 0){
        return a[u];
    }
    int sm = accumulate(all(vec),0);
    int mx = *max_element(all(vec));
    if(nx == 1){
        if(sm != a[u]){
            return -1;
        }else{
            if(u == 0){
                return 0;
            }else{
                return sm;
            }
        }
    }else{
        if(sm < a[u] || 2*a[u] < sm){
            return -1;
        }else{
            if(a[u] < mx){
                return -1;
            }else{
                return 2*a[u] - sm;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    a.resize(n);
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n-1){
        int x,y;
        cin >> x >> y;
        --x,--y;
        G[x].pb(y),G[y].pb(x);
    }
    if(dfs(0,-1) == 0){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
