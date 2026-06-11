#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 300100;
const int P = (1 << 17);
const int MAXP = 2 * P + 100;

int N, M;
vector <pair <int, int> > event[MAXN];
int seg[MAXP];

void upd (int x, int v)
{
    x += P;
    while (x)
    {
        seg[x] += v;
        x /= 2;
    }
}

int csum (int x)
{
    if (x >= P) return seg[1];
    x += P;
    int ctot = 0;
    while (x > 1)
    {
        if (x & 1) ctot += seg[x-1];
        x /= 2;
    }
    return ctot;
}

ll gogo (int K)
{
    ll ans = 0;
    ll cv = 0;
    for (int i = 0; i * K <= M; i++)
    {
        ll nc = csum ((i + 1) * K);
        ans += (nc - cv) * i;
        cv = nc;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;

        event[r-l].push_back(make_pair (l, r));
    }

    int nleft = N;
    for (int i = 1; i <= M; i++)
    {
        for (auto pp : event[i])
        {
            nleft--;
            upd (pp.first, -1);
            upd (pp.second, 1);
        }

        cout << nleft + gogo (i) << "\n";
    }
}