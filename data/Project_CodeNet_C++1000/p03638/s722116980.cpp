#include <bits/stdc++.h>
using namespace std;

#define VIC ios::sync_with_stdio(0);cin.tie(0);ios_base::sync_with_stdio(0);
#define wtf(s) freopen((s), "w", stdout)
#define rff(s) freopen((s), "r", stdin)
#define pi (2 * acos(0))
typedef long double ld;
typedef long long ll;
typedef complex<ld> point;
#define endl '\n'
#define matrix vector<vector<ll>>
#define EPS 1e-9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a) *(b)).imag())
#define lengthsqr(v) (dot(v, v))
#define length(v) ((ld)hypot((v).Y, (v).X))
#define same(a, b) (lengthsqr(vec(a, b)) < EPS)

const int N = 15 + 5, inf = 2e9, mod = 1e9 + 7;

int main()
{
    VIC
    int a[102][102];
    int n, m, c, x = 0;
    cin >> n >> m >> c;
    int i = 0, j = 0, cur = 0;
    while (true)
    {
        if (j == m)
            j = m - 1,
            i++;
        else if (j == -1)
            j = 0,
            i++;
        if (i == n)
            break;
        if (x == 0)
            cur++,
            cin >> x;
        x--;
        if (i % 2 == 0)
            a[i][j++] = cur;
        else
            a[i][j--] = cur;
    }
    for (int i = 0; i < n; i++, cout << endl)
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
    return 0;
}
