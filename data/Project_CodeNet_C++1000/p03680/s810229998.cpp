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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int dfs(int now, vector<bool> &flg, vector<int> &g, int cnt) {
    //cout << now << endl;
    if (now == 1) return cnt;
    if (flg[now]) return -1;
    flg[now] = true;
    int next = g[now];
    if (flg[next]) return -1;
    return dfs(next, flg, g, cnt + 1);
}

int main() {
    int n;
    cin >> n;
    vector<int> g(n);
    rep(i, n) {
        int a;
        cin >> a;
        --a;
        g[i] = a;
    }

    vector<bool> flg(n, false);
    int num = dfs(0, flg, g, 0);
    cout << num << endl;
    return 0;
}
