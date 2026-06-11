#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main()
{
    int n, t, a[112345], m[112345], d[112345];
    cin >> n >> t;
    REP(i, n)
    {
        cin >> a[i];
    }

    m[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        m[i] = max(a[i], m[i + 1]);
        d[i] = m[i] - a[i];
    }

    //t = (t / 2) * 2;

    sort(d, d + n);

    int ans = 0;
    int i = n - 1;
    d[n] = d[n - 1];
    while (d[i] == d[i + 1] && i >= 0)
    {
        ans++;
        i--;
    }

    cout << ans << endl;

    return 0;
}