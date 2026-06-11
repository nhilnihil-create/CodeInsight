#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int w, a, b;
    cin >> w >> a >> b;

    int ans;
    if (a > b)
    {
        ans = max(a - b - w, 0);
    }
    else
    {
        ans = max(b - a - w, 0);
    }

    cout << ans << endl;
    return 0;
}
