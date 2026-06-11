#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int K, S;
    cin >> K >> S;

    ll ans = 0;
    for (int i = max(0, S - 2 * K); i <= min(S, K); i++)
    {
        for (int j = max(0, S - i - K); j <= min(S - i, K); j++)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}