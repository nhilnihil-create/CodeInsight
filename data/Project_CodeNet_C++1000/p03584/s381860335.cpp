#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

constexpr ll INF = 1e18;
constexpr ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, a[112345], b[112345];

    cin >> n >> k;
    REP(i, n)
    cin >> a[i] >> b[i];

    ll res = 0;
    for (int i = -1; i <= 30; i++)
    {
        if (i > -1 && !(k & (1 << i)))
            continue;

        ll tmp = 0;

        REP(j, n)
        {
            if (i == -1 || !(a[j] & (1 << i)))
            {
                bool check = true;
                for (int l = i + 1; l <= 30; l++)
                {
                    if (!((k & (1 << l)) || !(a[j] & (1 << l))))
                        check = false;
                }

                if (check)
                    tmp += b[j];
            }
        }
        res = max(res, tmp);
    }

    cout << res << endl;

    return 0;
}