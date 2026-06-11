#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> ans;
    for (int i = 0; i < n; i++)
    {
        if (a[i] + a[i + 1] >= l)
        {
            ans.push_back(i);
            break;
        }
    }
    if (ans.empty())
    {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    int ind = ans[0];
    for (int i = ind + 1; i < n - 1; i++)
    {
        ans.push_back(i);
    }
    for (int i = ind - 1; i >= 0; i--)
    {
        ans.push_back(i);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        cout << ans[i] + 1 << endl;
    }
}
