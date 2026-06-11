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

ll N,M,H,W,K,Q,A,B;
string S, T;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
const ll INF = 1LL << 60;
typedef pair<ll,ll> P;

mat G(100010, vec(0));
vector<bool> used(100010, false);
ll dfs(ll v){
    used[v] = true;
    ll res = 0;
    for(ll to : G[v]){
        if(!used[to]){
            res = res ^ (dfs(to) + 1);
        }
    }
    return res;
}
int main(){
    cin>>N;
    rep(i,N-1){
        cin>>A>>B;
        --A, --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    ll ans = dfs(0);
    cout<<(ans == 0 ? "Bob" : "Alice")<<endl;
    //cout<<ans<<endl;
}