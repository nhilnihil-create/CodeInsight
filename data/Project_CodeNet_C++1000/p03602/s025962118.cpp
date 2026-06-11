#include<bits/stdc++.h>
#define N 500
typedef long long LL;
using namespace std;
int a[N][N], h[N][N], n;

int main() {
    cin >> n;
    LL ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++) {
            if (i == k) continue;
            for(int j = i + 1; j <= n; j++) {
                if (j == k) continue;
                LL tmp = (LL)a[i][k] + a[k][j];
                if (a[i][j] > tmp) {cout << -1 << endl;return 0;}
                if (a[i][j] == tmp) h[i][j] = 1;
            }
        }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            ans += a[i][j] * (1 - h[i][j]);
    cout << ans << endl;
}
