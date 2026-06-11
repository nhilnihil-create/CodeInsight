#include <bits/stdc++.h>
#define dbgi(x) cout << #x << " = " << (x) << "\n";
#define dbgvi(x) cout << #x << " = "; for(int i = 0; i < (x.size()); ++i) cout << x[i] << " ";
#define mrk() cout << "HERE\n"
#define int long long
#define vi vector < int >
#define vs vector < string >
#define vii vector < vi >
#define viii vector < vii >
#define viiii vector < viii >
#define pii pair < int, int >
#define vpii vector < pii >
#define foru(i, a, b) for(int i = a; i < b; ++i)
#define ford(i, b, a) for(int i = b; i > a; --i)
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ld long double
using namespace std;

int n;

vii g;
vi used;

void dfs(int start, int v, int dist, vi &a){
    used[v] = 1;
    a[v] = dist;
    for(int u: g[v]){
        if(!used[u]){
            dfs(start, u, dist + 1, a);
        }
    }
}


signed main(){
    cin >> n;
    g.resize(n);
    used.resize(n);
    foru(i, 0, n - 1){
        int v, u;
        cin >> v >> u;
        --v, --u;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill(used.begin(), used.end(), 0);
    vi cnt1(n);
    dfs(0, 0, 0, cnt1);
    fill(used.begin(), used.end(), 0);
    vi cnt2(n);
    dfs(n - 1, n - 1, 0, cnt2);
    int balance = 0;
    foru(i, 0, n){
        if(cnt1[i] <= cnt2[i]){
            balance++;
        } else {
            balance--;
        }
    }
    //cout << balance << "\n";
    if(balance > 0){
        cout << "Fennec";
    } else {
        cout << "Snuke";
    }

}

