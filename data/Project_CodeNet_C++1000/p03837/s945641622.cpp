#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 1000000000000000000;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

ll N,M;
ll a[1010],b[1010],c[1010];
ll D[110][110];
int main(){
    cin >> N >> M;
    rep(i,110) rep(j,110){
        if(i == j) D[i][j] = 0;
        else D[i][j] = INF;
    }
    rep(i,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;b[i]--;
        D[a[i]][b[i]] = c[i];
        D[b[i]][a[i]] = c[i];
    }
    rep(k,N) rep(i,N) rep(j,N) D[i][j] = min(D[i][k] + D[k][j],D[i][j]);
    ll ans = 0;
    rep(i,M){
        if(D[a[i]][b[i]] != c[i]) ans++;
    }
    cout << ans << endl;
}
