#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

const int MAX_V = 1e5;
vector<int> es[MAX_V];
int flag = 0;
vector<int> path;
bool used[MAX_V];

//gとnowを結ぶパスをpathに収納
void dfs1(int now, int g, int par){
    if(now == g){
        flag++;
        path.pb(now);
    }
    else{
        for(auto &e: es[now]){
            if(e != par){
                dfs1(e, g, now);
                if(flag){
                    path.pb(now);
                    break;
                }
            }
        }
    } 
}

int dfs2(int now){
    used[now] = true;
    int sum = 1;
    for(auto &e: es[now]){
        if(used[e]) continue;
        sum += dfs2(e);
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        es[u].pb(v), es[v].pb(u);
    }
    fill(used, used+N, false);
    dfs1(N-1, 0, -1);
    for(auto &e: path) used[e] = true;
    int n = path.size();
    int F = 0, S = 0;
    rep(i, (n+1)/2){
        F += dfs2(path[i]);
    }
    rep2(i, (n+1)/2, n-1){
        S += dfs2(path[i]);
    }
    //cout << F << ' ' << S << endl;
    if(F > S) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;
}