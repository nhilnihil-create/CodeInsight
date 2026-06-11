#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int main(void)
{
    string s;
    cin >> s;
    int len = s.size();
    ll ans = 0;
    for (ll i = 0; i < (1 << len - 1); ++i)
    {
        vector<int> bt;
        rep(j, 0, len) if (i >> j & 1) bt.push_back(j);
        ll x = 0;
        ll y = 0;
        rep(j, 0, len)
        {
            if (find(all(bt), j - 1) != bt.end())
            {
                x += y;
                y = s[j] - '0';
            }
            else
                y = 10 * y + (s[j] - '0');
        }
        ans += x + y;
    }
    cout << ans << endl;
}
