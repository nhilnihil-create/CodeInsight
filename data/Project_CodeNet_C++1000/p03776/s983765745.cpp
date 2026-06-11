#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for (int i = x; i < n; i++)
#define OP(m) cout << m << endl
typedef long long ll;
typedef unsigned long long ull;

vector<vector<ll>> com(51, vector<ll>(51, 0));

void combination()
{
    rep(i, com.size())
    {
        com[i][0] = 1;
    }
    for (int i = 1; i < com.size(); i++)
    {
        for (int j = 1; j < com.size(); j++)
        {
            com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
        }
    }
}

int main()
{
    combination();
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];
    sort(ALL(v), greater<ll>());

    double sumv = 0;
    rep(i, a) sumv += v[i];
    printf("%.10f\n", sumv / a);

    ll ans = 0;
    int m = count(ALL(v), v[a - 1]);

    if (v[0] == v[a - 1])
    {
        for (int i = a; i <= b; i++)
        {
            ans += com[m][i];
        }
    }
    else
    {
        int r = count(v.begin(), v.begin() + a, v[a - 1]);

        ans = com[m][r];
    }
    OP(ans);

    return 0;
}