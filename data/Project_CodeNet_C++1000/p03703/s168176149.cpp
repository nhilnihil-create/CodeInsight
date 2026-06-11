#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;

ll N,M,H,W,K,Q,A,B,L,R;
string S;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

typedef vector<P> vp;
typedef vector<vp> matP;

const ll MAX_N = 200010;
vec bit(MAX_N,0);
ll sum(ll i){
    ll s = 0;
    while(i > 0){
        s += bit[i];
        i -= i & -i;
    }
    return s;
}
void add(ll i, ll x){
    while(i < MAX_N){
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    cin>>N>>K;
    vec a(N), ord(N+1), a_rank(N+1), sum_a(N+1);
    rep(i,N) cin>>a[i];
    rep(i,N+1) ord[i] = i;
    sum_a[0] = 0;
    rep(i,N) sum_a[i+1] = sum_a[i] + a[i] - K;
    sort(ord.begin(), ord.end(), [&](ll x, ll y){
        return sum_a[x] < sum_a[y];
    });
    ll last = INF, rank = 0;
    rep(i,N+1){
        rank += last != sum_a[ord[i]];
        add(rank, 1);
        a_rank[ord[i]] = rank;
        last = sum_a[ord[i]];
    }
    ll ans = 0;
    for(int i = N; i >= 0; --i){
        add(a_rank[i], -1);
        ans += sum(a_rank[i]);
    }
    cout<<ans<<endl;
}