#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define ll long long
using namespace std;

int n, A;
ll dp[50][2501][50], x[51];

ll solve(int i, int sum, int c) {
    if (i == n) {
//        printf("sum:%d c:%d\n", sum , c);
        return c == 0 ? 0 : ((sum / c) == A) && (sum % c) == 0;
    }
    ll &ret = dp[i][sum][c];
    if (ret != -1) return ret;
    ret = 0;
    ret = solve(i + 1, sum, c);
    ret += solve(i + 1, sum + x[i], c + 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//    freopen("input.txt", "r", stdin);
    cin >> n >> A;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    cout << solve(0, 0, 0) << endl;
    return 0;
}
