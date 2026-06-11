#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<int> to[200010];
bool ok;
int n,m;
void solve(){
    queue<pair<int,int>> que;
    que.push({0,0});
    int cnt = 0;
    while(1){
        auto now = que.front();
        que.pop();
        if(now.second == 2) break;
        for(auto u : to[now.first]){
            if(u == n-1){
                ok = 1;
                break;
            }
            que.push({u,now.second+1});
        }
    }
}
int main(){
    cout << fixed << setprecision(10);
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ok = 0;
    solve();
    if(ok) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}