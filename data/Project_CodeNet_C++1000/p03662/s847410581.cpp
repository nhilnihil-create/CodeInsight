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

bool dfs(int u, int p, int t, vi& route)
{
    if(u == t) return true;
    each(v,G[u]){
        if(v != p){
            route.pb(v);
            if(dfs(v, u, t, route)) return true;
            route.pop_back();
        }
    }
    return false;
}

void dfs(int u, int p, int& cnt){
    cnt++;
    each(v,G[u]){
        if(v != p){
            dfs(v, u, cnt);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n-1){
        int u,v;
        cin >> u >> v;
        G[u-1].pb(v-1), G[v-1].pb(u-1);
    }
    int cnt = 0;
    vi route = {0};
    dfs(0, -1, n-1, route);
    rep(i,(len(route)+1)/2){
        int hoge = 1;
        int cand1 = -1, cand2 = -1;
        if(i >= 1){
            cand1 = route[i-1];
        }
        if(i < len(route)-1){
            cand2 = route[i+1];
        }
        each(v, G[route[i]]){
            if(v != cand1 && v != cand2){
                dfs(v, route[i], hoge);
            }
        }
        cnt += hoge;
    }
    if(cnt > n/2){
        cout << "Fennec\n";
    }else{
        cout << "Snuke\n";
    }
    return 0;
}