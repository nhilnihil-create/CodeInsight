#include <bits/stdc++.h>
#include <bitset>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
#define ALL(a) a.begin(), a.end()
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

int main(){
    cin>>N;
    vec t(N), a(N), u(N, INF), b(N, 1);
    rep(i,N) cin>>t[i];
    rep(i,N) cin>>a[i];
    if(N == 1){
        cout<<int(a[0] == t[0])<<endl;
        return 0;
    }
    u[0] = b[0] = t[0];
    u[N-1] = b[N-1] = a[N-1];
    reps(i,1,N){
        u[i] = min(u[i], t[i]);
        if(t[i-1] < t[i]) b[i] = max(b[i], t[i]);
    }
    bool ok = u[N-1] >= a[N-1] && a[N-1] >= b[N-1];
    Rrep(i, N - 1){
        u[i] = min(u[i], a[i]);
        if(u[i] > u[i+1]) b[i] = max(b[i], a[i]);
        if(b[i] > u[i]) ok = false;
    }
    ll ans = ok;
    rep(i,N){
        (ans *= u[i] - b[i] + 1)%=MOD;
    }
    /*rep(i,N) cout<<u[i]<<' ';
    cout<<endl;
    rep(i,N) cout<<b[i]<<' ';
    cout<<endl;*/
    cout<<ans<<endl;
}