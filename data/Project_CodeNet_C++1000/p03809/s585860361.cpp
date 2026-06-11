#include <bits/stdc++.h>
using namespace std;
#define finish(x){cout << x << endl; exit(0);}
#define ll long long

const int N = 100001;

int n;
vector <int> a, v[N];

ll dfs(int node, int pnode){
    ll s = 0;
    ll mx = 0;
    for(auto &i : v[node]){
        if(i == pnode) continue;
        ll cur = dfs(i, node);
        s += cur;
        mx = max(mx, cur);
    }
    if(v[node].size() == 1) return a[node];
    ll x = 2 * a[node] - s;
    ll y = s - a[node];
    if(x < max(0LL, 2 * mx - s) || y < 0) finish("NO");
    if(pnode == -1 && x) finish("NO");
    return x;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(auto &i : a) cin >> i;
    for(int i = 0 ; i < n - 1 ; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    if(n == 2){
        if(a[0] == a[1]) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    int root = 0;
    for(int i = 0 ; i < n ; i++){
        if(v[i].size() != 1) root = i;
    }
    dfs(root, -1);
    cout << "YES" << endl;
}
