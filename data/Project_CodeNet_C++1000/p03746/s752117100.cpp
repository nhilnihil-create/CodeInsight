#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

// ref : http://wk1080id.hatenablog.com/entry/2018/01/18/114818

vector<int> g[100010];
bool seen[100010];

int main(){
    int n, m, v; // v : スタート地点
    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        v = a;
    }

    vector<int> path;

    while(true){    
        bool flag = 0;
        for(auto nv : g[v]){
            if (seen[nv]) continue;
            path.push_back(nv);
            v = nv;
            seen[nv] = 1;
            flag = 1;
            break;
        }
        if(!flag) break;
    }

    v = path[0];
    reverse(path.begin(), path.end());

    while(true){    
        bool flag = 0;
        for(auto nv : g[v]){
            if (seen[nv]) continue;
            path.push_back(nv);
            v = nv;
            seen[nv] = 1;
            flag = 1;
            break;
        }
        if(!flag) break;
    }

    cout << path.size() << endl;
    for(auto e : path) cout << e + 1 << " ";
    cout << endl;

    return 0;
}
