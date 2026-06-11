#include <iostream>
#include <vector>

#define MAXN 100000

using namespace std;

vector < int > g[MAXN + 1], r[MAXN];
int a[MAXN + 1], h[MAXN + 1];
bool done[MAXN + 1], viz[MAXN + 1];

void dfs1(int x) {
    viz[x] = 1;
    r[h[x]].push_back(x);
    for (auto &y : g[x]) {
        if (viz[y] == 0) {
            h[y] = h[x] + 1;
            dfs1(y);
        }
    }
}

void dfs2(int x) {
    done[x] = 1;
    for (auto &y : g[x])
        if (done[y] == 0)
            dfs2(y);
}

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ans = 0;
    if (a[1] != 1)
        ans = 1;

    for (int i = 2; i <= n; i++)
        g[a[i]].push_back(i);

    dfs1(1);

    for (int i = n - 1; i > 0; i--) {
        for (auto &x : r[i]) {
            if (done[x] == 0) {
                int e = x, cnt = 1;
                while (a[e] != 1 && cnt < k) {
                    cnt++;
                    e = a[e];
                }
                if (a[e] != 1)
                    ans++;
                dfs2(e);
            }
        }
    }

    cout << ans;

    return 0;
}
