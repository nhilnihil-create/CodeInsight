#include<bits/stdc++.h>
const long long N = 1e5 + 5;
const long long inf = 1e9;
using namespace std;

vector <long long> adj[N];
long long n, a[N], u, v, root;

void dfs(long long u, long long p){
    long long sum = 0, maxx = -inf;
    for (long long i = 0; i < adj[u].size(); i++){
        long long v = adj[u][i];
        if (v == p) continue;
        dfs(v, u);
        sum += a[v]; maxx = max(maxx, a[v]);
    }
    if (adj[u].size() == 1) return;
    long long x = sum - a[u], y = a[u] - x;
    if (x < 0 || y < 0) {cout << "NO"; exit(0);}
    long long Max = ((maxx > sum/2) ? sum - maxx : sum/2);
    if (Max < x) {cout << "NO"; exit(0);}
    a[u] = 2*a[u]-sum;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    if (n == 2){
        if (a[1] == a[2]) {
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        return 0;
    }
    for (long long i = 1; i <= n; i++) if (adj[i].size() > 1) {root = i; break;}
    dfs(root, root);
    if (a[root] != 0){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
}
