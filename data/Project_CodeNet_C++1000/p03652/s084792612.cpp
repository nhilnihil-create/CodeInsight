#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())

typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

int main()
{
    int n, m, a[310][310];

    cin >> n >> m;
    REP(i, n)
    REP(j, m)
    cin >> a[i][j];

    bool usin[310];
    fill(usin, usin + m + 1, false);
    bool used[310];
    fill(used, used + m + 1, false);
    int ind[310];
    fill(ind, ind + n, 0);

    priority_queue<P> q;

    int res = 1e9;

    map<int, int> mp;

    REP(i, m)
    {
        mp.clear();
        REP(j, n)
        {
            while (used[a[j][ind[j]]])
                ind[j]++;
            mp[a[j][ind[j]]]++;
            usin[a[j][ind[j]]] = true;
        }

        int ma = 0;
        int man = 0;

        int mas = 0;

        for (int j = 1; j <= m; j++)
        {
            if (!usin[j])
                continue;

            mas = max(mp[j], mas);

            if (ma < mp[j])
            {
                ma = mp[j];
                man = j;
            }
        }

        used[man] = true;
        usin[man] = false;

        res = min(res, mas);

        //cout << "#" << mas << " " << man << endl;
    }

    cout << res << endl;

    return 0;
}