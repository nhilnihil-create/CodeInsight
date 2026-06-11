#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int rnk[DIM], val[DIM], cst[DIM];
vector<pair<int, int>> edg[DIM];

void dfs(int x, int f, bool &ok) {
    if (rnk[x] > 1)
        val[x] *= 2;
    
    for (pair<int, int> y : edg[x]) {
        if (y.first == f)
            continue;
        
        dfs(y.first, x, ok);
        cst[y.second] = val[y.first];
        val[x] -= val[y.first];
    }
    
    ok &= (val[x] >= 0);
    if (!f) ok &= !val[x];
    
    return;
}

int main(void) {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i)
        cin >> val[i];
    
    for (int i = 2; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        
        ++rnk[x]; ++rnk[y];
        edg[x].push_back(make_pair(y, i));
        edg[y].push_back(make_pair(x, i));
    }
    
    bool ok = true;
    
    if (n == 2)
        ok = (val[1] == val[2]);
    else {
        int r = 1;
        for (int i = 2; i <= n; ++i)
            if (rnk[i] > 1) r = i;
        
        dfs(r, 0, ok);
        for (int x = 1; x <= n; ++x) {
            if (rnk[x] == 1)
                continue;
            
            int s = 0, mx = 0;
            for (pair<int, int> y : edg[x]) {
                s += cst[y.second];
                mx = max(mx, cst[y.second]);
            }
            
            ok &= (mx <= s / 2);
        }
    }
    
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}