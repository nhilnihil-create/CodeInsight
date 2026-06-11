#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (size_t i = 0; i < 3 * n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    sort(a.begin(), a.end());
    for (size_t i = 0; i < n; i++)
    {
        ans += a[n + 2 * i];
        /* code */
    }
    cout << ans << endl;

    return 0;
}