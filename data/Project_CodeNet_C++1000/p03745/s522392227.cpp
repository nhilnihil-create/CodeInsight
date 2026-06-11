#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    ll n, tmp = 0, cnt = 1;
    cin >> n;
    vector<ll> a(n), ok(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            continue;

        if (a[i-1] < a[i])
        {
            if (tmp == -1) {
                tmp = 0;
                cnt++;
            } else {
                tmp = 1;
            }
        }
        if (a[i-1] > a[i])
        {
            if (tmp == 1) {
                tmp = 0;
                cnt++;
            } else {
                tmp = -1;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
