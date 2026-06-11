#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
vector<vector<int> > dp(500, vector<int>(500, INF));
vector<pii> drug(50);
vector<int> cost(50);
int n, ma, mb;
/* function */
void initDPTable() {dp[0][0] = 0;}
void calcDPTable() {
    for (int i = 0; i < n; i++) {
        for (int j = 400; j >= 0; j--) {
            for (int k = 400; k >= 0; k--) {
                int nj = j + drug[i].first;
                int nk = k + drug[i].second;
                dp[nj][nk] = min(dp[nj][nk], dp[j][k] + cost[i]);
            }
        }
    }
}
void calcAns() {
    int ans = INF;
    for (int j = 1; j <= 400; j++) {
        for (int k = 1; k <= 400; k++) {
            if (ma * k == mb * j) {
                ans = min(ans, dp[j][k]);
            }
        }
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}
/* main */
int main() {
    cin >> n >> ma >> mb;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        drug[i] = pii(a, b);
        cost[i] = c;
    }
    initDPTable();
    calcDPTable();
    calcAns();
}