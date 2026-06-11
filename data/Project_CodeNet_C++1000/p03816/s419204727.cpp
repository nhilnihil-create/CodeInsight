#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef complex<double> Point;

#define PI acos(-1.0)
#define EPS 1e-10
const ll INF = 1e16;
const ll MOD = 1e9 + 7;

#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,N) for(ll i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
#define fi first
#define se second
#define N_SIZE (1LL << 20)
#define NIL -1

ll mod_add(ll a, ll b) { return (a + b) % MOD; }
ll mod_sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mod_mul(ll a, ll b) { return a*b % MOD; }

int n;
map<ll,ll> m;

int main(){
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
        m[a[i]]++;
    }
    ll ans = m.size();
    ll cnt = 0;
    for(auto it = m.begin();it != m.end();it++){
        if((it -> second)%2 == 0)cnt++;
    }
    if(cnt % 2)ans--;
    cout << ans << endl;
    // sort(ALL(a));
    // rep(i,n)cout << a[i] << " ";
    // cout << endl;
}