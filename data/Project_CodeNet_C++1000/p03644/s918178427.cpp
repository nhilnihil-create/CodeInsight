#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;

    int ans = 1;
    while ((ans << 1) <= n)
    {
        ans = ans << 1;
    }

    cout << ans << '\n';
    return (0);
}
