#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> PLL;
typedef pair<P,P> PP;
typedef vector<ll> llVEC;
typedef vector<P> PVEC;
typedef priority_queue<P,PVEC,greater<P> > PPQ;
typedef priority_queue<ll, llVEC, greater<ll> > llPQ;

#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n-1; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue;
#define LINF (ll)1e18
#define INF (int)1e9
#define fs first
#define sc second

template<typename T>
ll sz(vector<T> vec){ return (ll)vec.size(); }
ll sz(string s){ return (ll)s.size(); }

ll gcd(ll a,ll b){ return ((!b) ?a :gcd(b, a%b)); }

int main(){
    ll n,m,r;
    cin >> n >> m >> r;
    
    ll d[n][n] = {};
    rep(i,0,n) rep(j,0,n) if(i != j) d[i][j] = LINF;

    ll memo[r] = {};
    rep(i,0,r){
        cin >> memo[i];
        memo[i]--;
    }

    rep(i,0,m){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        d[a][b] = c;
        d[b][a] = c;
    }
    rep(k,0,n) rep(i,0,n) rep(j,0,n) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    
    ll array[r] = {};
    rep(i,0,r) array[i] = i;

    ll ans = LINF;
    do{
        ll temp = 0;
        rep(i,1,r){
            temp += d[memo[array[i-1]]][memo[array[i]]];
        }
        ans = min(ans,temp);
    }while(next_permutation(array,array+r));
    
    cout << ans << endl;

    return 0;
}
