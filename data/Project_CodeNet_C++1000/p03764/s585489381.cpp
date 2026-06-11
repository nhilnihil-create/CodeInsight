#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>

using namespace std;

#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

const ll MOD = 1e9 + 7;

int main()
{
    ll n, m, x[112345], y[112345];
    cin >> n >> m;
    REP(i, n)
    cin >> x[i];
    REP(i, m)
    cin >> y[i];

    ll areax = 0;
    ll areay = 0;

    REP(i, n)
    {
        areax += (i + 1 - 1) * x[i] - (n - i - 1) * x[i];

        areax %= MOD;
    }

    REP(i, m)
    {
        areay += (i + 1 - 1) * y[i] - (m - i - 1) * y[i];

        areay %= MOD;
    }

    cout << (areax * areay) % MOD << endl;

    return 0;
}