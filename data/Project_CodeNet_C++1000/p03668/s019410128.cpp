#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N;
vector<int> G[100010];

int dfs(int v, int p){
    int res = 0;
    int son = 0;
    for(auto u : G[v]){
        if(u != p) res ^= dfs(u, v) + 1; 
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 1; i < N; i++){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
 
    }
    cout << (dfs(1, 0) == 0 ? "Bob" : "Alice") << endl;
    return 0;
}