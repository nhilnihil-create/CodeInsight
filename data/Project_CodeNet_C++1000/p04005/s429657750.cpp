#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll a, b, c;
ll suba, subb;

int main()
{

    cin >> a >> b >> c;
    suba = a * b * ((c + 1) / 2);
    subb = a * b * (c / 2);
    ll min = abs(suba - subb);

    suba = a * ((b + 1) / 2) * c;
    subb = a * (b / 2) * c;
    if (abs(suba - subb) < min)
    {
        min = abs(suba - subb);
    }

    suba = ((a + 1) / 2) * b * c;
    subb = (a / 2) * b * c;
    if (abs(suba - subb) < min)
    {
        min = abs(suba - subb);
    }
    cout << min << endl;
    return 0;
}
