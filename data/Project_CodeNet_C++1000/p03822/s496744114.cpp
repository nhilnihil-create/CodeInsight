#include <bits/stdc++.h>

#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define bug(x) cerr<<#x<<" is "<<x<<endl

using namespace std;

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

vector<int> g[maxn];
int p[maxn];
vector<int> lf[maxn];
int ch[maxn];
set<int> hl; // Have leaf children

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    FOR(i,1,n){
        int x; cin>>x; g[x-1].pb(i); p[i] = x-1;
        ch[x-1]++;
    }
    REP(i,n){
        if (ch[i] == 0) {
            lf[p[i]].pb(i);
            hl.insert(p[i]);
        }
    }
    int nr = 0;
    while (!hl.empty()) {
        nr++;
        vector<int> add, del;
        for (int x : hl){
            lf[x].pop_back(); ch[x]--; if (SZ(lf[x])==0) del.pb(x);
            if (ch[x]==0) {
                add.pb(p[x]);
                if (x==0) break;
            }
        }
        for (int x : del) hl.erase(x);
        for (int x : add) lf[x].pb(-1), hl.insert(x);
    }
    cout<<nr-1<<'\n';
} 