#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    ll ns = sqrt(N) + 1;
    ll j = 0;
    int ans = 1e9;
    for (ll i = 1; i < ns; i++)
    {
        if (N % i == 0)
        {
            j = N / i;
            int cnt = 1;
            while (j >= 10)
            {
                j /= 10;
                cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}