#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;


vector<vector<int>> g;
int N,M;
vector<int> p;
vector<bool> v;
void dfs(int nowv){
    bool ok = 1;
    for(int i=0;i<g[nowv].size();i++){
        int next = g[nowv][i];
        if(v[next])continue;
        v[next] = 1;
        p.push_back(next);
        dfs(next);
        return ;
    }
}

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> M;
    g.resize(N);
    v.resize(N);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    p.push_back(0);
    v[0] = 1;
    dfs(0);
    reverse(ALL(p));
    dfs(0);
    cout << p.size() << endl;
    for(auto x:p)cout << x+1 << " ";
    cout << endl;
}