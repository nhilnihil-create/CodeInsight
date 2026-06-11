#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<int, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e5 + 9;
vector<int> T[N];

int n;
int pi[N];
int dd[N];
int subt[N];

void dfs(int u, int par){
    pi[u] = par;
    subt[u] = 1;
    for(auto x : T[u]){
        if(x == par)
            continue;
        dd[x] = dd[u] + 1;
        dfs(x, u);
        subt[u] += subt[x];
    }
}

int main(){
    fastIO;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1,-1);
    int climb = (dd[n]-1)/2;
    int k = n;
    for(int j = 0 ; j < climb; j ++ ){
        k = pi[k];
    }
    int v1 = subt[k];
    int v2 = n - v1;
    if(v1 < v2){
        cout << "Fennec\n";
    }
    else{
        cout << "Snuke\n";
    }
    return 0;
}