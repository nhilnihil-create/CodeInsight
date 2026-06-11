#include <bits/stdc++.h>

#define INF 1000000010
#define INFLL ((1LL<<62)-5)
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/
#define MAX_N 5005

int N, K;
vector <int> allC[MAX_N];
int par[MAX_N];
int dp[MAX_N][MAX_N];
int newDP[MAX_N];
int sz[MAX_N];

vector <int> allE[MAX_N];

int ans(INF);
void makeTree (int c) {
    FO (i,0,allE[c].size()) {
        if (allE[c][i] != par[c]) {
            int nx = allE[c][i];
            par[nx] = c;
            allC[c].push_back (nx);
            makeTree(nx);
            sz[c] += sz[nx];
        }
    }
    sz[c]++;
}

void doDP(int c) {
    FO (i,0,allC[c].size()) doDP(allC[c][i]);
    FO (i,0,allC[c].size()) {
        int cC = allC[c][i];
        for (int p = K-1; p >= 0; p--) {
            dp[cC][p+1] = dp[cC][p];
        }
        dp[cC][0]++;
        FO (p,0,K+1) {
            newDP[p] = INF;
        }
        FO (p,0,K+1) {
            int oth = K-p;
            newDP[p] = min(dp[c][p]+dp[cC][min(p,oth)],dp[c][min(p,oth)]+dp[cC][p]);
        }
        FO (p,0,K+1) dp[c][p] = newDP[p];
        FO (p,1,K+1) dp[c][p] = min(dp[c][p],dp[c][p-1]);
    }
    ans = min (ans, dp[c][K]+N-sz[c]);
    /*FO (p,0,K+1) {
        printf ("dp[%d][%d]: %d\n", c, p, dp[c][p]);
    }*/
}

int main() {
    scanf ("%d %d", &N, &K);
    FO (i,0,N-1) {
        int _a, _b;
        scanf ("%d %d", &_a, &_b);
        allE[_a].push_back (_b);
        allE[_b].push_back (_a);
    }
    makeTree(1);
    doDP(1);
    printf ("%d\n", ans);
    return 0;
}
