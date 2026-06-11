#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll N;
ll MAX = 100005;
vector<vector<llll>> G;
vector<ll> d(MAX, -1);
void dfs(ll v){
    for (llll next_v : G[v]){
        if(d[next_v.first] != -1) continue;
        d[next_v.first] = d[v] + next_v.second;
        dfs(next_v.first);
    }
}


int main(){
    cin >> N;
    G.resize(N);
    ll a, b, c;
    for (ll i = 0; i < N-1; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }
    d.resize(N);
    ll Q, K;
    cin >> Q >> K;
    K--;
    d[K] = 0;
    dfs(K);
    ll x, y;
    for (ll i = 0; i < Q; i++) {
        cin >> x >> y;
        x--; y--;
        printf("%lld\n", d[x] + d[y]);
    }

}   