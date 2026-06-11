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
#define INF (ll)1e18
#define MOD (ll)1e9 + 7

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{
    ll i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;

    int I, J, L;
    I = i;
    J = j;
    L = l;

    ll res = 0;

    ll r_ = o;

    r_ += (i / 2) * 2;
    r_ += (j / 2) * 2;
    r_ += (l / 2) * 2;

    res = r_;

    r_ = o;

    if (i > 0 && j > 0 && l > 0)
    {
        r_ += 3;
        i--;
        j--;
        l--;

        r_ += (i / 2) * 2;
        r_ += (j / 2) * 2;
        r_ += (l / 2) * 2;

        res = max(r_, res);
    }

    cout << res << endl;

    return 0;
}