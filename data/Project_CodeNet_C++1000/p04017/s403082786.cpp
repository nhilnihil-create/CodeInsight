#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    int l, q;
    cin >> l >> q;
    vector<int> a(q);
    vector<int> b(q);
    for(int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
    }
    vector<vector<int>> next(21, vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        int ar = upper_bound(x.begin(), x.end(), x[i] + l) - x.begin();
        next[0][i] = ar-1;
    }
    for(int k = 0; k < 20; k++)
    {
        for(int i = 0; i < n; i++)
        {
            if(next[k][i] == n-1) next[k+1][i] = n-1;
            else next[k+1][i] = next[k][next[k][i]];
        }
    }
    for(int i = 0; i < q; i++)
    {
        int u = a[i];
        int v = b[i];
        if(u > v) swap(u, v);
        int ans = 0;
        for(int k = 20; k >= 0; k--)
        {
            if(next[k][u] < v)
            {
                u = next[k][u];
                ans += 1 << k;
            }
        }
        cout << ans + 1 << endl;
    }
}
