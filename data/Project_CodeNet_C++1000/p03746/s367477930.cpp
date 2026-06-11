#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653
#define INF 100000000000000
#define N 110000

vector<vector<ll>> conn(N);
vector<ll> reached(N,0);

ll jud(ll x){
    reached[x]=1;
    REP(i,conn[x].size()) if (1-reached[conn[x][i]]) return conn[x][i];
    return -1;
}

int main(){
    ll n, m, a, b, edj; cin >> n >> m;
    REP(i,m){
        cin >> a >> b;a--;b--;
        conn[a].pb(b);
        conn[b].pb(a);
    }
    vector<ll> ansl, ansr;
    reached[a]=1; reached[b]=1;
    ansl.pb(a); ansr.pb(b); edj = a;
    while(true){
        if (jud(edj)==-1) break;
        else {
            edj = jud(edj);
            ansl.pb(edj);
        }
    }
    edj = b;
    while(true){
        if (jud(edj)==-1) break;
        else {
            edj = jud(edj);
            ansr.pb(edj);
        }
    }
    
    cout << ansl.size()+ansr.size() << endl;
    FORD(i,ansl.size()-1,0) cout << ansl[i]+1 << " ";
    REP(i,ansr.size()) cout << ansr[i]+1 << " ";
    cout << endl;
}