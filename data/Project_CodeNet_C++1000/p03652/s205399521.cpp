#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
    int n, m, i, j, a[303][303], k[303] = {}, ans;
    bool ps[303] = { false };

    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
        scanf("%d", &a[i][j]);
    }

    for (j = 0; j < m; j++) {
        ps[j] = true;
    }

    ans = INF;
    for (int t = 0; t < m; t++) {
        int sel[303] = {}, selmax, seli;
        for (i = 0; i < n; i++) {
            while (!ps[a[i][k[i]] - 1]) {
                k[i]++;
            }
            sel[a[i][k[i]] - 1]++;
        }
        selmax = 0;
        seli = 0;
        for (j = 0; j < m; j++) {
            if (selmax < sel[j]) {
                selmax = sel[j];
                seli = j;
            }
        }
        ans = min(ans, selmax);
        ps[seli] = false;
    }

    printf("%d\n", ans);

    return 0;
}