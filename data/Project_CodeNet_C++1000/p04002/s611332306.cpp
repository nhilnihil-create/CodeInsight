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
typedef map<int, bool> M;

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main()
{
    ll h, w, n, all, a[112345], b[112345], ans[10] = {0};
    map<P, bool> mp, pos;
    cin >> h >> w >> n;

    REP(i, n)
    {
        cin >> a[i] >> b[i];

        a[i]--, b[i]--;

        pos[P(a[i], b[i])] = true;
    }

    all = (h - 2) * (w - 2);

    REP(i, n)
    {

        for (int j = -2; j <= 0; j++)
        {
            if (j + a[i] < 0 || a[i] + j + 2 >= h)
                continue;

            for (int k = -2; k <= 0; k++)
            {
                if (k + b[i] < 0 || b[i] + k + 2 >= w)
                    continue;

                if (mp[P(a[i] + j, b[i] + k)])
                    continue;

                all--;

                mp[P(a[i] + j, b[i] + k)] = true;

                int num = 0;

                for (int l = 0; l <= 2; l++)
                {
                    for (int m = 0; m <= 2; m++)
                    {
                        if (pos[P(a[i] + j + l, b[i] + k + m)])
                            num++;
                    }
                }

                ans[num]++;
            }
        }
    }

    ans[0] = all;

    REP(i, 10)
    cout << ans[i] << endl;

    return 0;
}