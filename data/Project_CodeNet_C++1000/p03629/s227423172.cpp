#include <bits/stdc++.h>


using namespace std;

const int N = 200002;
typedef pair<int, int> pii;

char s[N];
int g[N][26];
int pre[N], dis[N];

int main(void) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) {
        int o = s[i] - 'a';
        for (int j = i - 1; j >= 0 && !g[j][o]; --j)
            g[j][o] = i;
    }

    string ans; int y = 0, x = -1;
    queue<int> q;
    dis[0] = 1; pre[0] = -1; q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int o = 0; o != 26; ++o) {
            int v = g[u][o];
            if (!v) {
                x = u;
                break;
            }
            else {
                if (dis[v]) continue;
                dis[v] = dis[u] + 1;
                pre[v] = u; q.push(v);
            }
        }
        if (x != -1) break;
    }

    while (x != -1) {
        for (int o = 0; o != 26; ++o) {
            if (g[x][o] != y) continue;
            ans.push_back(o + 'a');
            y = x; x = pre[x];
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    printf("%s", ans.c_str());
    return 0;
}