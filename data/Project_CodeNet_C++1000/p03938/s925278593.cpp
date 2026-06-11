#include <bits/stdc++.h>
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

ll N,M,H,W,K,Q,A,B,L,R;
string S, T;
const ll MOD = 998244353;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;
const ll MAX_N = 100010;
mat bit(2, vec(MAX_N,0));
ll sum(ll ifb, ll i){
    ll s = 0;
    while(i > 0){
        s += bit[ifb][i];
        i -= i & -i;
    }
    return s;
}
void add(ll ifb, ll i, ll x){
    while(i < MAX_N){
        bit[ifb][i] += x;
        i += i & -i;
    }
}
int main() {
    cin>>N;
    vec a(N), b(N), p(N);
    rep(i,N) cin>>A, p[i] = A;
    rep(i,N) a[i] = b[i] = i + 1;
    rep(i,N) add(0, p[i], i + 1), add(1, N - p[i] + 1, i + 1);
    rep(i,N){
        a[i] += sum(0, i + 1);
        b[i] += sum(1, i + 1);
        //cout<<sum(1, N - p[i])<<endl;
    }
    reverse(ALL(b));
    rep(i,N){
        cout<<a[i];
        i == N - 1 ? cout<<endl : cout<<' ';
    }
    rep(i,N){
        cout<<b[i];
        i == N - 1 ? cout<<endl : cout<<' ';
    }
}