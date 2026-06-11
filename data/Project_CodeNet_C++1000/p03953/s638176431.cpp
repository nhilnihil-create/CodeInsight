#include <bits/stdc++.h>

using namespace std;

const int Nmax = 1e5 + 5;
int a[Nmax], b[Nmax], c[Nmax], p[Nmax], x, n, i, m;
long long K;

void power(long long k)
{
    if(!k) return;

    int i;
    if(k&1)
    {
        for(i=1; i<n; ++i) c[i] = b[a[i]];
        for(i=1; i<n; ++i) b[i] = c[i];
    }

    for(i=1; i<n; ++i) c[i] = a[a[i]];
    for(i=1; i<n; ++i) a[i] = c[i];

    power(k/2);
}

int main()
{
  //  freopen("input", "r", stdin);
    cin.sync_with_stdio(false);

    cin >> n;
    for(i=1; i<=n; ++i) cin >> p[i], a[i] = i;

    cin >> m >> K;
    for(i=1; i<=m; ++i)
    {
        cin >> x;
        swap(a[x], a[x-1]);
    }

    p[0] = p[1];
    for(i=1; i<n; ++i) b[i] = i, p[i] = p[i+1] - p[i];
    power(K);

    long long s = p[0];
    for(i=1; i<=n; ++i)
    {
        cout << s << '\n';
        s += p[b[i]];
    }

    return 0;
}
