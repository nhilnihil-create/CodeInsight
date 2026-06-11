#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pb emplace_back

const int MAXN = 100009;
int a[MAXN];
int n, m;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    pair<int, int> x(-1, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 1)
        {
            if (x.ff == -1)
                x.ff = a[i];
            else if (x.ss != -1)
            {
                cout << "Impossible";
                return 0;
            }
            else
                x.ss = a[i];
        }
    }
    vector<int> ans;
    if (x.ff != -1)
    {
        cout << x.ff << " ";
        for (int i = 1; i <= x.ff; i += 2)
            ans.pb(2);
    }
    else
        ans.pb(1);
    for (int i = 0; i < n; i++)
    {
        int y = a[i];
        if (y % 2 == 1)
            continue;
        cout << y << " ";
        if ((y / 2) % 2 == 1)
        {
            int e = 2;
            for (; e <= y / 2 - 3; e += 4)
                ans.pb(4);
            ans.pb(2);
            e += 2;
            for (; e < y; e += 4)
                ans.pb(4);
        }
        else
        {
            for (int e = 2; e < y; e += 4)
                ans.pb(4);
        }
    }
    if (x.ss == -1)
    {
        if (ans.back() == 2)
            ans.back() = 1;
        else if (ans.back() == 4)
        {
            ans.back() = 1;
            ans.pb(2);
        }
        else
            ans.pop_back();
    }
    else
    {
        cout << x.ss << " ";
        for (int e = 2; e < x.ss; e += 2)
            ans.pb(2);
    }
    cout << "\n";
    cout << ans.size() << "\n";
    for (int e : ans)
        cout << e << " ";
}
