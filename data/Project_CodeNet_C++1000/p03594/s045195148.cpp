#include <stdio.h>
#include <bits/stdc++.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

const int N = 5000;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

int a[N][N];
int b[N][N];
vector<char> var = {'R', 'Y', 'G', 'B'};

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(20);
    int n, m, d;
    cin >> n >> m >> d;
    if (d % 2 == 1)
    {
        rep(i, 0, n)
        {
            rep(j, 0, m)
                cout << var[i % 2 * 2 + j % 2];
            cout << "\n";
        }
        return 0;
    }
    rep(i, 0, N)
        rep(j, 0, N)
            a[i][j] = (i / d) % 2 * 2 + (j / d) % 2;
    rep(i, 0, N)
        rep(j, 0, N)
            if ((i + j) % 2 == 0)
            {
                int x = (i + j) / 2, y = (i - j) / 2;
                if (x >= 0 && x < N && y >= 0 && y < N)
                    b[x][y] = a[i][j];
            }
    rep(i, 0, n)
    {
        rep(j, 0, m)
            cout << var[b[2000 + i][j]];
        cout << endl;
    }
    return 0;
}
