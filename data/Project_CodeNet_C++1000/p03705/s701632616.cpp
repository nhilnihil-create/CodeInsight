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
    ll n, a, b;
    cin >> n >> a >> b;
    if (a > b)
        cout << 0 << endl;
    else
    {
        if (n == 1)
        {
            if (a == b)
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (n == 2)
            cout << 1 << endl;
        else
            cout << abs(a + b * (n - 1) - (b + a * (n - 1))) + 1 << endl;
    }
}