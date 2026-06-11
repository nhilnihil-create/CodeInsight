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
vec ans(0);
vector<bool> used(100010,false);
void dfs(ll v){
    used[v] = true;
    for(ll to : G[v]){
        if(!used[to]){
            ans.push_back(to);
            dfs(to);
            return;
        }
    }
    return;
}

int main() {
    cin>>N>>M;
    rep(i,M){
        cin>>A>>B;
        --A; --B;
        G[A].push_back(B);
        G[B].push_back(A);
    }
    dfs(0);
    reverse(ALL(ans));
    ans.push_back(0);
    dfs(0);
    cout<<ans.size()<<endl;
    rep(i, ans.size()) {
        cout<<ans[i] + 1;
        i == ans.size() - 1 ? cout<<endl : cout<<' ';
    }
}