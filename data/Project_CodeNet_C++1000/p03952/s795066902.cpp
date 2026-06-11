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
    int n, x, i, ans[200003] = {}, t;
    bool u[200003] = { false };

    scanf("%d%d", &n, &x);

    if (x == 1 || x == n * 2 - 1) {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");

    if (n == 2) {
        for (i = 0; i < n * 2 - 1; i++) {
            printf("%d\n", i + 1);
        }
        return 0;
    }

    ans[n] = x;
    u[x] = true;
    if (x == n * 2 - 2) {
        ans[n + 1] = n * 2 - 1;
        ans[n - 1] = 1;
        ans[n + 2] = 2;
        u[1] = u[2] = u[n * 2 - 1] = true;
    }
    else {
        ans[n + 1] = x - 1;
        ans[n - 1] = x + 1;
        ans[n + 2] = x + 2;
        u[x - 1] = u[x + 1] = u[x + 2] = true;
    }

    t = 1;
    for (i = 1; i <= n * 2 - 1; i++) {
        if (ans[i] == 0) {
            while (u[t]) {
                t++;
            }
            ans[i] = t;
            u[t] = true;
        }
    }

    for (i = 1; i <= n * 2 - 1; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}