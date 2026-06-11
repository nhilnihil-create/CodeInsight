#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

#define MAX_N 100000

int n,m;
vector<int> G[MAX_N];
bool visited[MAX_N];
vector<int> ans;

void dfs(int now){
    ans.emplace_back(now);
    visited[now] = true;
    for(auto v : G[now]){
        if(!visited[v]){
            dfs(v);
            return;
        }
    }
}

signed main(){
    cin >> n >> m;
    REP(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs(0);
    reverse(ALL(ans));
    ans.pop_back();
    dfs(0);
    cout << ans.size() << endl;
    for(auto a : ans){
        cout << a + 1 << " ";
    }
    cout << endl;
    return 0;
}