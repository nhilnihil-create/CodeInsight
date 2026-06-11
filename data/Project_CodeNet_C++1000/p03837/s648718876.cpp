#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> &vec){ return (ll)vec.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>> &pq) {return (ll)pq.size(); }
template<typename T>
ll sz(priority_queue<T, vector<T>, greater<T>> &pq) {return (ll)pq.size(); }
ll sz(string &s) {return (ll)s.size(); } 
ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }
bool checkindex(ll i,ll n){ return (i < n && i >= 0); }

int main(){
    ll n,m;
    cin >> n >> m;
    
    ll d[n][n] = {};
    rep(i,0,n) rep(j,0,n) d[i][j] = ((i == j)?0:LINF);
    
    ll a[m],b[m],c[m];
    rep(i,0,m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;b[i]--;
        d[a[i]][b[i]] = c[i]; d[b[i]][a[i]] = c[i];
    }

    rep(k,0,n) rep(i,0,n) rep(j,0,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

    ll cnt = 0;
    rep(i,0,m) if(d[a[i]][b[i]] != c[i]) cnt++;
    
    cout << cnt << endl;

    return 0;
}

