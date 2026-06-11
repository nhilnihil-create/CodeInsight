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
    int w, h;
    cin >> w >> h;
    vector<int> p(w), q(h);
    rep(i, w)
    {
        cin >> p[i];
    }
    rep(i, h)
    {
        cin >> q[i];
    }

    using A = pair<int, int>;
    vector<A> axes;
    rep(i, w)
    {
        axes.push_back(make_pair(p[i], 0));
    }
    rep(i, h)
    {
        axes.push_back(make_pair(q[i], 1));
    }
    sort(axes.begin(), axes.end());

    int64_t result = 0;
    int x = 0, y = 0;
    rep(i, w + h)
    {
        int v;
        int dir;
        tie(v, dir) = axes[i];

        if (dir == 0) {
            result += (int64_t)v * (h + 1 - y);
            x++;
        } else {
            result += (int64_t)v * (w + 1 - x);
            y++;
        }
        //cout << i << " " << v << " " << x << " " << y << " " << result << endl;
    }
    cout << result << endl;
    return 0;
}