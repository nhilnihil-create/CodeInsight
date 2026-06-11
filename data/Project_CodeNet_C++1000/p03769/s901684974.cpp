#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, ii> iiii;
typedef pair <ll, iiii> lli4;

const ll lim = 10000000000000;
const int Maxn = 205;

ll ways[Maxn][Maxn];
ll C[Maxn][Maxn];
vector <lli4> seq;
vector <int> res;

ll Mult(ll x, ll y)
{
    if (x == 0 || y == 0) return 0;
    if (x <= lim / y) return x * y;
    return lim;
}

ll F(int n)
{
    ll res = 0;
    for (int i = 2; i <= n; i += 2)
        res = min(lim, res + C[n][i]);
    return res;
}

int main()
{
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = min(lim, C[i - 1][j - 1] + C[i - 1][j]);
    }
    for (int i = 0; i < Maxn; i++)
        for (int j = 0; j < Maxn; j++)
            for (int k = 1; k <= i && k <= j; k++)
                ways[i][j] = min(lim, ways[i][j] + Mult(C[i][k], C[j][k]));
    ll sum = 0;
    for (int a1 = 1; a1 <= 25; a1++)
        for (int b1 = 1; b1 <= 25; b1++)
            for (int a2 = 1; a2 <= 25; a2++)
                for (int b2 = 1; b2 <= 25; b2++) {
                    ll my = min(lim, F(a1 + a2) + F(b1 + b2));
                    my = min(lim, my + Mult(ways[a1][a2], ways[b1][b2]));
                    if (my < lim)
                        seq.push_back(lli4(my, iiii(ii(a1, b1), ii(a2, b2))));
                }
    sort(seq.begin(), seq.end());
    ll n; scanf("%lld", &n);
    int pnt = 1;
    while (n > 0) {
        int ind = lower_bound(seq.begin(), seq.end(), lli4(n + 1, iiii(ii(0, 0), ii(0, 0)))) - seq.begin() - 1;
        if (ind >= 0) {
            int a1 = seq[ind].second.first.first, b1 = seq[ind].second.first.second;
            int a2 = seq[ind].second.second.first, b2 = seq[ind].second.second.second;
            for (int i = 0; i < a1; i++)
                res.push_back(pnt);
            for (int i = 0; i < b1; i++)
                res.push_back(pnt + 1);
            for (int i = 0; i < a2; i++)
                res.push_back(pnt);
            for (int i = 0; i < b2; i++)
                res.push_back(pnt + 1);
            pnt += 2;
            n -= seq[ind].first;
        } else break;
    }
    vector <ll> V;
    for (int i = 1; i <= 60; i++)
        V.push_back(F(i));
    while (n > 0) {
        int ind = upper_bound(V.begin(), V.end(), n) - V.begin() - 1;
        for (int i = 0; i <= ind; i++)
            res.push_back(pnt);
        n -= V[ind];
        pnt++;
    }
    //assert(res.size() <= 200);
    printf("%d\n", int(res.size()));
    for (int i = 0; i < res.size(); i++)
        printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
    return 0;
}
