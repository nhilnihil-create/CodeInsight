#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;
long long a[MAXN];
vector<int> adj[MAXN];
vector<long long> c[MAXN];
int n;
bool b = 1;

long long dfs(int v, int p = -1){
    if(adj[v].size() == 1){
        return a[v];
    }
    long long sum = 0;
    for(int i = 0; i < adj[v].size(); i++){
        int u = adj[v][i];
        if(u != p){
            c[v].push_back(dfs(u, v));
            if(c[v][c[v].size() - 1] < 0){
                b = 0;
            }
            sum += c[v][c[v].size() - 1];
        }
    }
    if(p == -1){
        if(sum != 2 * a[v]){
            b = 0;
        }
    }
    for(int i = 0; i < c[v].size(); i++){
        if(c[v][i] > a[v]){
            b = 0;
        }
    }
    if(2 * a[v] - sum > a[v]){
        b = 0;
    }
    return 2 * a[v] - sum;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n == 2){
        if(a[1] == a[2]){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        return 0;
    }
    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int d = 1;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() > 1){
            d = i;
        }
    }
    dfs(d);
    if(b){
        cout << "YES"; return 0;
    }
    cout << "NO";
}
