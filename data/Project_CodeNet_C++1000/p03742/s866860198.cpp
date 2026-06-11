#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, __VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

// 500, 61min

#define MOD 1000000007
#define INF 1000000000
#define MAX_N 100010

//#define CONFIRM

ll X, Y;
#ifdef CONFIRM
int dp[100][100][2] = {}; // 0: Alice ターン、かち 1: Brown のターン、かち

// x, y でプレイヤーが 0 Alice, 1 Brown のときの勝者を返す
// 0 なら勝者 Alice, 1 なら勝者 Brown
int dfs(int x, int y, int cur) {
    if(dp[x][y][cur] != -1) { return dp[x][y][cur]; }
    if(x <= 2 && y <= 2) { return dp[x][y][cur]; }
    int next = (cur == 0) ? 1 : 0;
    // x を削る
    for(int i = 1; i * 2 <= x; ++i) {
        int ret = dfs(x - i * 2, y + i, next);
        if(ret == cur) {
            dp[x][y][cur] = ret;
            return ret;
        }
    }
    // y を削る
    for(int i = 1; i * 2 <= y; ++i) {
        int ret = dfs(x + i, y - i * 2, next);
        if(ret == cur) {
            dp[x][y][cur] = ret;
            return ret;
        }
    }
    dp[x][y][cur] = next;
    return next;
}
#endif

int main()
{
    cin >> X >> Y;
#ifdef CONFIRM
    MINUS(dp);
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][1][0] = 1;
    dp[0][1][1] = 0;
    dp[0][2][0] = 0;
    dp[0][2][1] = 1;
    dp[1][0][0] = 1;
    dp[1][0][1] = 0;
    dp[1][1][0] = 1;
    dp[1][1][1] = 0;
    dp[1][2][0] = 1;
    dp[1][2][1] = 0;
    dp[2][0][0] = 0;
    dp[2][0][1] = 1;
    dp[2][1][0] = 1;
    dp[2][1][1] = 0;
    dp[2][2][0] = 1;
    dp[2][2][1] = 0;
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            //printf("X: %d Y: %d Winner: %s\n", i, j, (dfs(i, j, 0) == 0) ? "Alice" : "Brown");
            if(dfs(i, j, 0) == 1 && abs(i-j) >= 2) {
                printf("predict is not correct %d %d\n", i, j);
                return 0;
            }
        }
    }
#endif
    if(abs(X-Y) < 2) { printf("Brown\n"); }
    else{ printf("Alice\n"); }
    return 0;
}
