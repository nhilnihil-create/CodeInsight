#include <bits/stdc++.h>

using namespace std;

const int  Nmax = 1e5 + 5;
int n, a[Nmax], i;

bool solve()
{
    int i, cnt = 0;
    for(i=1; i<=n; ++i)
        if(a[i] & 1) ++cnt;

    if(n % 2 == 0) return (cnt&1);
    if(cnt % 2 == 0) return 1;
    if(cnt > 2) return 0;

    for(i=1; i<=n; ++i)
        if(a[i] == 1) return 0;
            else if(a[i] & 1) --a[i];

    int g = a[1];
    for(i=2; i<=n; ++i)
        g = __gcd(g, a[i]);

    for(i=1; i<=n; ++i)
        a[i] /= g;

    return solve() ^ 1;
}

int main()
{
  //  freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n;
    for(i=1; i<=n; ++i)
        cin >> a[i];

    //if(n == 1) cout << (a[i]&1 ? "Second" : "First") << '\n';
    cout << (solve() ? "First" : "Second") << '\n';

    return 0;
}
