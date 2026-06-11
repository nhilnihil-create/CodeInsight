#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define INF 10e9
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
    {
        if (a % 2 == 1)
            cout << 0 << endl;
        else
            cout << -1 << endl;
    }
    else
    {
        int res = 0;
        while (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
        {
            int x, y, z;
            x = b / 2 + c / 2;
            y = a / 2 + c / 2;
            z = a / 2 + b / 2;
            a = x, b = y, c = z;
            res++;
        }
        cout << res << endl;
    }
}