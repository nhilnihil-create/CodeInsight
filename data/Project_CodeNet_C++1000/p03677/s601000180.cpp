#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<complex>
#include<bitset>
#include<numeric>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N, M;
pii A[100100];
vector<pii> eve;
int sum[200200];
int sum2[200200];

signed main() {
    cin >> N >> M;
    int pre;
    cin >> pre;
    --pre;
    int ans = 0;
    rep(i, N - 1) {
        int cur;
        cin >> cur;
        --cur;
        if (pre < cur)A[i] = pii(pre, cur);
        else A[i] = pii(pre, cur + M);
        pre = cur;
        ans += A[i].second - A[i].first;
    }
    rep(i, N - 1) {
        eve.emplace_back(A[i].first, i);
        eve.emplace_back(A[i].second, i);
    }
    sort(eve.begin(), eve.end());

    for (pii e:eve) {
        int p = e.first;
        int i = e.second;
        if (p == A[i].first) {
            sum[p + 2] += 1;
        } else {
            int d = A[i].second - A[i].first;
            sum[p + 1] -= d;
            sum[p + 2] += d - 1;
        }
    }
    rep(i, 2 * M + 5)sum[i + 1] += sum[i];
    rep(i, 2 * M + 5)sum[i + 1] += sum[i];
    rep(i, 2 * M + 5)cerr << sum[i] << endl;
    int maxv = -INF;
    rep(i, M) {
        maxv = max(maxv, sum[i] + sum[i + M]);
    }
    cout << ans - maxv << endl;
    return 0;
}
