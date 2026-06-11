#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += a[i] / 2;
        if(i > 0 && a[i-1] == 1)
        {
            if(a[i] % 2 == 1)
            {
                ans++;
                a[i] = 0;
            }
            else if(a[i] > 0)
            {
                a[i] = 1;
            }
        }
        else
        {
            a[i] %= 2;
        }
    }
    cout << ans << endl;
}

