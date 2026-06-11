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

ll n;

priority_queue<ll,vector<ll>,greater<ll>> p;
priority_queue<ll> q;

int main(){
    cin >> n;
    vector<ll> a(3*n);
    rep(i,3*n)cin >> a[i];
    ll sum = 0;
    vector<ll> c1;
    rep(i,n){
        sum += a[i];
        p.push(a[i]);
    }
    c1.push_back(sum);
    FOR(i,n,2*n){
        p.push(a[i]);
        sum -= p.top();
        sum += a[i];
        c1.push_back(sum);
        p.pop();
    }
    // rep(i,c1.size()){
    //     cout << c1[i] << " ";
    // }
    // cout << endl;
    sum = 0;
    vector<ll> c2;
    FOR(i,2*n,3*n){
        sum += a[i];
        q.push(a[i]);
    }
    c2.push_back(sum);
    for(int i = 2*n-1;i >= n;i--){
        q.push(a[i]);
        sum -= q.top();
        sum += a[i];
        c2.push_back(sum);
        q.pop();
    }
    reverse(ALL(c2));
    ll ans = -INF;
    rep(i,c1.size()){
        // cout << c1[i] << " " << c2[i] << endl;
        ans = max(ans,c1[i] - c2[i]);
    }
    cout << ans << endl;
}