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

const int N_MAX = 51;

ll C[N_MAX][N_MAX]; // C[n][k] -> nCk

void comb_table(int N)
{
    rep(i, N + 1)
    {
        rep(j, i + 1)
        {
            if (j == 0 || j == i)
            {
                C[i][j] = 1;
            }
            else
            {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
            }
        }
    }
}

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    comb_table(N);
    vector<ll> v(N);
    long double ans = 0;
    ll ans_cnt = 0;
    rep(i, N)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<ll>());
    rep(i, A)
    {
        ans += v[i];
    }
    ans /= A;

    int x = 0, y = 0;
    rep(i, N)
    {
        if (v[i] == v[A - 1])
        {
            x++;
            if (i < A)
            {
                y++;
            }
        }
    }
    // cout << x << " " << y << endl;
    if (v[0] == v[A - 1])
    {
        for (y = A; y <= min(x, B); ++y)
        {
            ans_cnt += C[x][y];
        }
    }
    else
    {
        ans_cnt += C[x][y];
    }

    cout.precision(20);
    cout << fixed << ans << endl;
    cout << ans_cnt << endl;
    return 0;
}
