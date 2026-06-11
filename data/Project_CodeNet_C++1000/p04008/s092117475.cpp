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

mat G(1e+5, vec(0));//子の方へ向かう有向グラフ
vec depth(1e+5, 0);
void dfs(int v, int k){
    depth[v] = k;
    for(int to : G[v]) dfs(to, k + 1);
}

vector<bool> used(1e+5, false);
void dfs2(int v){
    used[v] = true;
    for(int to : G[v]) if(!used[to]) dfs2(to);
}

int main() {
    cin>>N>>K;
    vec a(N), ord(N);
    ll ans = 0;
    rep(i,N){
        cin>>a[i];
        --a[i];
        if(i == 0) {
            ans += a[i] != 0;
            a[i] = 0;
        }else {
            G[a[i]].push_back(i);
        }
        ord[i] = i;
    }
    dfs(0, 0);
    sort(ALL(ord), [&](int x, int y){
        return depth[x] > depth[y];
    });
    rep(i,N){
        int id = ord[i];
        //cout<<id<<endl;
        if(!used[id]) {
            bool ng = false;
            rep(j, K - 1) {
                id = a[id];
                if(a[id] == 0) {
                    ng = true;
                    break;
                }
            }
            if(ng || a[id] == 0) break;
            ++ans;
            dfs2(id);
        }
    }
    cout<<ans<<endl;
}