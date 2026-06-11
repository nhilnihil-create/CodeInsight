#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> g[100001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<vector<int> > b(m, vector<int>(int(100000 + m - 1) / m));
    vector<int> s(m, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        b[x % m][x / m] += 1;
        s[x % m] += 1;
    }

    int ans = 0;
    for (int i = 0; i * 2 <= m; ++i) {
        if (i == 0 || i * 2 == m) {
            ans += s[i] / 2;
        } else {
            int mi = min(s[i], s[m - i]);
            ans += mi;
            if (s[i] - mi >= + 2) {
                for (int j = 0; j < int(100000 + m - 1) / m; ++j) {
                    for (int k = 0; b[i][j] >= 2 && s[i] - mi >= 2; ++k) {
                        b[i][j] -= 2;
                        ans += 1;
                        mi += 2;
                    }
                }
            } else if (s[m - i] - mi >= + 2) {
                for (int j = 0; j < int(100000 + m - 1) / m; ++j) {
                    for (int k = 0; b[m - i][j] >= 2 && s[m - i] - mi >= 2; ++k) {
                        b[m - i][j] -= 2;
                        ans += 1;
                        mi += 2;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
