#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
// cout << fixed << setprecision(20);

int N;
int a[220000];
bool x[220000];
int dp[110][110];
bool judge() {
    if (x[N - 1] == x[N] || x[N] == x[N + 1])return x[N];
    int l, r;
    for (l = N - 1; l > 1; l--)if (x[l] == x[l - 1])break;
    for (r = N + 1; r < 2 * N - 1; r++)if (x[r] == x[r + 1])break;
    if (N - l < r - N)return x[l];
    return x[r];
}
signed main() {
    cin >> N;
    for (int i = 1; i <= 2 * N - 1; i++)cin >> a[i];
    // 解の存在範囲を初期化
    int lb = 0, ub = 2 * N - 1;

    // 解の存在範囲が1より大きい間、繰り返す
    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        for (int i = 1; i <= 2 * N - 1; i++)x[i] = a[i] <= mid;

        if (judge()) {
            // midが条件を満たせば、解の存在範囲は(lb, mid]
            ub = mid;
        } else {
            // midが条件を満たさなければ、解の存在範囲は(mid, ub]
            lb = mid;
        }
    }

    // この時点で、lb + 1 = ubとなっている
    cout << ub << endl;
}
