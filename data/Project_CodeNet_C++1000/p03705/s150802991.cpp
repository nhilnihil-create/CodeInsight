#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll N, A, B;
ll ans;
int main()
{
    cin >> N >> A >> B;

    if (A > B)
    {
        ans = 0;
    }
    else
    {
        if (N == 1)
        {
            if (A == B)
            {
                ans = 1;
            }
            else
            {
                ans = 0;
            }
        }
        else
        {
            ans = (B - A) * (N - 2) + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
