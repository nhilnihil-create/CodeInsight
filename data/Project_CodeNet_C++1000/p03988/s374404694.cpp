#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<ll, ll> P;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int mx = 0;
    rep(i, n)
    {
        int x;
        cin >> x;
        mx = max(mx, x);
        v[x]++;
    }
    if (mx % 2)
    {
        for (int i = mx / 2 + 1; i <= mx; i++)
        {
            v[i] -= 2;
        }
        if (v[mx / 2 + 1] > 0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    else
    {
        for (int i = mx / 2; i <= mx; i++)
        {
            v[i] -= 2;
        }
        v[mx / 2]++;
        if (v[mx / 2] > 0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    rep(i, n + 1)
    {
        if (v[i] < 0)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
}