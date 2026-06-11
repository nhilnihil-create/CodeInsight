#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define rep1(i, n) for (int i = 1; i < int(n); ++i)
#define repx(i, x, n) for (int i = int(x); i < int(n); ++i)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define ALL(n) begin(n), end(n)
#define IN(a, x, b) ((a) <= (x) && (x) < (b))
#define OUT(a, x, b) ((x) < (a) || (x) < (b))
typedef long long ll;
typedef long double ld;
const ll INF = 1e18;
const ll MOD = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;
    int a[N], b[N], c[M], d[M];
    rep(i, N)
    {
        cin >> a[i] >> b[i];
    }
    rep(i, M)
    {
        cin >> c[i] >> d[i];
    }
    rep(i, N)
    {
        ll now = 1e10, tmp, ans_idx;
        rep(j, M)
        {
            tmp = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (now > tmp)
            {
                now = tmp;
                ans_idx = j + 1;
            }
        }
        cout << ans_idx << endl;
    }
    return 0;
}
