#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Nmax = 1e5 + 5;

vector <int> c;

int a[Nmax];
int pos[Nmax];
int b[Nmax];
int maxx[Nmax];
int T[Nmax];
int num[Nmax];
int ans[Nmax];
int n,N;

void updatesum(int i, int val)
{
    while (i <= N)
    {
        T[i] += val;
        i += i & -i;
    }
}

int getsum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += T[i];
        i -= i & -i;
    }
    return res;
}

void updatenum(int i, int val)
{
    while (i <= N)
    {
        num[i] += val;
        i += i & -i;
    }
}

int getnum(int i)
{
    int res = 0;
    while (i > 0)
    {
        res += num[i];
        i -= i & -i;
    }
    return res;
}

signed main()
{
   // freopen("file.inp","r",stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < c.size(); i++)
    {
        if (c[i] != b[N]) b[++N] = c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int l = 1;
        int r = N + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (b[mid] <= a[i]) l = mid;
            else r = mid;
        }
        pos[i] = l;
        updatesum(pos[i], a[i]);
        updatenum(pos[i], 1);
        maxx[i] = max(pos[i], maxx[i - 1]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (maxx[i - 1] >= pos[i]) continue;
        ans[i] += (a[i] - b[maxx[i - 1]]) * (getnum(N) - getnum(pos[i] - 1));
        int x = getsum(pos[i] - 1) - getsum(maxx[i - 1]);
        int y = b[maxx[i - 1]] * (getnum(pos[i] - 1) - getnum(maxx[i - 1]));
        ans[i] += x - y;
        updatesum(pos[i], -a[i]);
        updatenum(pos[i], -1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
