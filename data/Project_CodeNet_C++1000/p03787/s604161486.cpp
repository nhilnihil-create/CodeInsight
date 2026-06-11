#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto (a): (b))
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
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

int cnt[MAX_N];
vector<int> G[MAX_N];
int flag[MAX_N];

void dfs(int u,int k,int& sm,bool& nibu)
{
    flag[u] = k;
    sm++;
    rep(i,len(G[u])){
        if(flag[G[u][i]] == 0){
            dfs(G[u][i],-k,sm,nibu);
        }else if(flag[G[u][i]] == k){
            nibu = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].pb(b),G[b].pb(a);
    }
    ll x=0,y=0,z=0;
    rep(i,n){
        if(flag[i] == 0){
            int kazu = 0;
            bool nibu = true;
            dfs(i,1,kazu,nibu);
            if(kazu == 1){
                z++;
            }else if(nibu){
                y++;
            }else{
                x++;
            }
        }
    }
    cout << x*x+2*x*y+2*y*y+2*z*n-z*z << "\n";
    return 0;
}
