// Crt. 2019-12-15  16:11:58
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005
using namespace std;

int n, m, a[N];
vector<int> pls[N], mns[N];

inline int Goto(int x, int y) {
    if (x < y) {
        pls[x].push_back(0);
        mns[y].push_back(x - y);
        return y - x;
    } else {
        pls[x].push_back(0);
        pls[1].push_back(m - x + 1);
        mns[y].push_back(-(y + m - x));
        return y + m - x;
    }
}

int main() {
#ifdef LOCAL_JUDGE
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);

    long long ans = 0;
    for (int i = 2; i <= n; ++i)
        ans += Goto(a[i - 1], a[i]);

    long long now = 0, num = 0, res = 0;
    for (int i = 1; i <= m; ++i) {
        now += num;
        for (int j = pls[i].size() - 1; ~j; --j)
            now += pls[i][j];
        num += pls[i].size();
        for (int j = mns[i].size() - 1; ~j; --j)
            now += mns[i][j];
        num -= mns[i].size();
        res = max(res, now);
    }

    cout << ans - res << endl;

    return 0;
}
// 215068256
