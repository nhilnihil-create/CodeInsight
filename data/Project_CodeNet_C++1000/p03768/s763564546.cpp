#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
ll inf = llmax / 2;

struct edge {
    int to, cost;
};

vector<int> G[1000000];
int c[200000];

int dp[11][200000];

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < 11; i++) {
        fill(dp[i], dp[i] + N, -1);
    }
    for (int i = 0; i < Q; i++) {
        int v, d;
        cin >> v >> d >> c[i];
        dp[d][v - 1] = i;
    }
    for (int i = 10; i >= 1; i--) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] != -1) {
                dp[i - 1][j] = max(dp[i - 1][j], dp[i][j]);
                int len = G[j].size();
                for (int k = 0; k < len; k++) {
                    dp[i - 1][G[j][k]] = max(dp[i - 1][G[j][k]], dp[i][j]);
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        if (dp[0][i] == -1) {
            cout << 0 << endl;
        } else {
            cout << c[dp[0][i]] << endl;
        }
    }
}
