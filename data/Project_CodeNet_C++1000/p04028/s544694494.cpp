#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const llint MAXN = 5005;
const llint MOD = 1000000007;

llint m, n;
string s;
int dp[MAXN*2][MAXN];

int f (int x, int y) {
    if (y == 0) return (x == 0);
    if (dp[x][y] != -1) return dp[x][y];
    if (x == 0) return dp[x][y] = (f(x+1, y-1) + f(x, y-1)) % MOD;
    return dp[x][y] = (f(x+1, y-1) + 2*f(x-1, y-1)%MOD) % MOD;
}

int main () {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    llint m = s.size();
    llint sol = f(m, n);
    for (llint i=0; i<m; i++) sol = (sol * (MOD + 1)/2) % MOD;
    cout << sol;
    return 0;
}
