#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define se second
#define fi first
#define mp make_pair
#define pb push_back
#define all(_v) _v.begin(), _v.end()
const int mod = (int)1e9 + 7;
const int INF = (int)1e9;
const ll LINF = (ll)1e18;
const int N = (int)1e5 + 100;
const int MAXA = (int)3e6;
int n,k;
int d[N];
vector<int> g[N];
pair<int, int> quer[N];
int bfsvert(int s){
    queue<int> q;
    q.push(s);
    for(int i = 1;i <= n;i++)d[i] = INF;
    d[s] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int to: g[v]){
            if(d[to] > d[v] + 1){
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)if(d[i] > (k / 2))cnt++;
    return cnt;
}

int bfsedge(int i){
    queue<int> q;
    q.push(quer[i].fi);
    q.push(quer[i].se);
    for(int i = 1;i <= n;i++)d[i] = INF;
    d[quer[i].fi] = 1;
    d[quer[i].se] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int to: g[v]){
            if(d[to] > d[v] + 1){
                d[to] = d[v] + 1;
                q.push(to);
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)if(d[i] > ((k + 1) / 2))cnt++;
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    // ifstream cin("input.txt");
    // ofstream cout("output.txt");
    cin >> n >> k;
    for(int i = 1;i <= n - 1;i++){
        int u,v;
        cin >> u >> v;
        quer[i] = {u, v};
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = INT_MAX;
    for(int i = 1;i <= n;i++){
        ans = min(bfsvert(i), ans);
    }
    for(int i = 1;i <= n - 1;i++){
        ans = min(bfsedge(i), ans);
    }
    cout << ans;
    return 0;
}
