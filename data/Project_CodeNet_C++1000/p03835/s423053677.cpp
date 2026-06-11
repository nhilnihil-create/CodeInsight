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
    int k, s;
    cin >> k >> s;
    int ans = 0;
    rep(x, 0, k + 1) rep(y, 0, k + 1) if (0 <= s - x - y && s - x - y <= k) ans++;
    cout << ans << endl;
}
