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

int main() {
    cin>>N;
    vec a(N), inv(N);
    rep(i,N) cin>>a[i], --a[i];
    rep(i,N) inv[a[i]] = i;
    set<ll> id;
    id.insert(-1);
    id.insert(N);
    ll ans = 0;
    rep(i,N){
        id.insert(inv[i]);
        auto ite = id.find(inv[i]), ite2 = ++id.find(inv[i]);
        ll temp = *ite2 - *ite;
        --ite2; --ite;
        temp *= *ite2 - *ite;
        ans += temp * (i + 1);
    }
    cout<<ans<<endl;
}