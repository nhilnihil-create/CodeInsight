#include <bits/stdc++.h>
using namespace std;

const int DIM = 100005;

vector<int> edg[DIM];

int dfs(int x, int f)
{
    int val = 0;
    for (int y : edg[x]) if (y != f)
        val ^= (dfs(y, x) + 1);
    return val;
}

int main(void)
{
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    
    cout << (dfs(1, 0) ? "Alice" : "Bob") << endl;
    return 0;
}

