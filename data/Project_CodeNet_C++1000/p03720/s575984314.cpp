#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,n) {
        cout << (int)g[i].size() << endl; 
    }

    return 0;
}