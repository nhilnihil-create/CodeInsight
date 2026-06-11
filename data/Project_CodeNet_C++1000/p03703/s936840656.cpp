#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = (1 << 19);
const int MAXP = 2 * P + 100;

int N, K;
pair <ll, int> ps[MAXN];

int seg[MAXP];

void upd (int x)
{
    x += P;
    while (x)
    {
        seg[x]++;
        x /= 2;
    }
}

int cg (int x)
{
    int res = 0;
    x += P;
    while (x > 1)
    {
        if (x % 2 == 1)
            res += seg[x-1];
        x /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N >> K;
    ps[0] = make_pair (0, 0);
    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;
        ps[i+1] = make_pair (ps[i].first + (x - K), i + 1);
    }
    N++;

    sort (ps, ps + N);
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += cg (ps[i].second);
        upd (ps[i].second);
    }
    cout << ans << "\n";
}