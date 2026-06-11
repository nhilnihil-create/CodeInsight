#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    //cout << "test" << endl;
    queue<pair<int, int>> que;
    que.push(make_pair(0, 0));
    vector<bool> flg(n, false);
    while(1) {
        if (que.empty()) break;
        pair<int, int> now = que.front();
        que.pop();
        if (flg[now.first]) continue;
        if (now.first == n-1 && now.second <= 2) {
            cout << "POSSIBLE" << endl;
            return 0;
        }
        flg[now.first] = true;
        for (auto v: g[now.first]) {
            if (flg[v]) continue;
            que.push(make_pair(v, now.second+1));
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
