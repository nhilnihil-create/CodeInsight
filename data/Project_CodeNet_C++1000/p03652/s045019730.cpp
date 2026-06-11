#include "bits/stdc++.h"

using namespace std;

int mp[400][400];
int vis[400];


int n, m;


int slove() {
    int cnt[350];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[mp[i][j]]) {
                cnt[mp[i][j]]++;
                break;
            }
        }
    }
    int maxx = 0, pos = 0;
    for (int i = 1; i <= m; i++) {
        if (cnt[i] > maxx) {
            maxx = cnt[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mp[i][j]);
        }
    }
    int cnt[310];
    int ans = n;
    int temp;
    for (int i = 1; i <= m; i++) {
        temp = 0;

        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if (!vis[mp[j][k]]) {
                    cnt[mp[j][k]]++;
                    temp = max(temp, cnt[mp[j][k]]);
                    break;
                }
            }
        }
        vis[slove()] = 1;
        ans = min(ans, temp);
    }
    printf("%d\n", ans);
    return 0;
}