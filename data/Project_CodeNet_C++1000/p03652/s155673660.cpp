#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> pref(n, vector<int>(m));
    rep(i, n)
    {
        rep(j, m)
        {
            int k;
            cin >> k;
            pref[i][k - 1] = j;
        }
    }

    int lb = 0, ub = n;
    while (ub - lb > 1)
    {
        int mid = (lb + ub) / 2;
        //cout << "lb: " << lb << " ub: " << ub << " mid: " << mid << endl;

        vector<map<int, int>> s(n, map<int, int>());
        rep(i, n)
        {
            rep(j, m)
            {
                s[i].insert(make_pair(pref[i][j], j));
            }
        }

        while (!s[0].empty())
        {
            vector<int> cnt(m, 0);
            rep(i, n)
            {
                cnt[s[i].begin()->second]++;
            }

            bool b = true;
            rep(j, m)
            {
                if (cnt[j] > mid)
                {
                    b = false;
                    rep(i, n)
                    {
                        s[i].erase(pref[i][j]);
                    }
                }
            }
            if (b)
            {
                break;
            }
        }

        (s[0].empty() ? lb : ub) = mid;
    }
    cout << ub << endl;

    return 0;
}