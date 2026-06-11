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
    cin>>W>>H;
    vec pq(W + H), ord(W + H);
    ll sum = 0;
    rep(i,W + H) cin>>pq[i], sum += pq[i], ord[i] = i;
    sort(ALL(ord), [&](ll x, ll y){
        return pq[x] < pq[y];
    });
    ll usedp, usedq;
    usedp = usedq = 0;
    rep(i, W + H){
        ll id = ord[i];
        bool p = id < W;
        sum += p ? (H - usedq) * pq[id] : (W - usedp) * pq[id];
        p ? ++usedp : ++usedq;
    }
    cout<<sum<<endl;
}