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

mat G(100010, vec(0));
ll dfs(ll v){
    vec child(0);
    for(ll to : G[v]){
        child.push_back(dfs(to));
    }
    ll size, ans;
    ans = size = child.size();
    sort(ALL(child));
    rep(i,size){
        ans = max(ans, size - i + child[i]);
    }
    return ans;
}

int main() {
    cin>>N;
    rep(i,N-1){
        cin>>A;
        --A;
        G[A].push_back(i + 1);
    }
    cout<<dfs(0)<<endl;
}