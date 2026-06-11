#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll mpow(ll a, ll n){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mod;
        a = a*a %mod;
        n>>=1;
    }
    return re;
}

ll inv (ll b){
    if (b==1) return b;
    return (mod-mod/b) * inv(mod%b) % mod;
}

const int maxn = 1e5+5;

vector<ll> p;
ll pos[maxn];

bool done[maxn];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n; cin>>n;
    vector<ll> x(n); REP(i,n) cin>>x[i];
    ll m, k; cin>>m>>k;
    vector<ll> v(m);
    vector<ll> d;
    REP(i,m){
        cin>>v[i];
    }
    REP(i,n){
        if (i) d.pb(x[i] - x[i-1]);
    }
    // k%=2;
    k--;
    REP(i,n-1) p.pb(i);
    REP(i,m){
        swap(p[v[i]-2], p[v[i]-1]);
    }
    REP(i,n-1){
        if (done[i]) continue;
        vector<ll> tmp;
        ll at = i; 
        tmp.pb(at); at = p[at];
        while (at != i){
            tmp.pb(at); at = p[at];
        }
        ll j = tmp.size(); ll df = k%j;
        REP(h,j){
            pos[tmp[h]] = tmp[(h+df+1)%j];
            done[tmp[h]]=1;
        }
    }

    ll at = x[0];
    REP(i,n){
        cout<<at<<'\n';
        if (i!=n-1) at += d[pos[i]];
    }
} 