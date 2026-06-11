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

int main()
{
    ll n, a, b, h[112345] = {0};
    cin >> n >> a >> b;
    REP(i, n)
    cin >> h[i];

    ll l = 0, r = 1000000000;
    while (r - l > 0)
    {
        ll m = (r + l) / 2; // ceil((r + l) / 2.0);

        /*
        ll h_[112345] = {0};
        REP(i, n)
        {
            h_[i] = h[i] - b * m;
        }

        ll ans_ = 0;
        sort(h_, h_ + 112345);
        int i = 112344;
        while (h_[i] > 0)
        {
            ans_ += ceil((float)h_[i] / (float)(a - b));

            //cout << ceil((float)h_[i] / (float)(a - b)) << endl;

            i--;
        }
        */
        ll ans = 0;
        REP(i, n)
        {
            if (h[i] - b * m > 0)
            {
                ans += (h[i] - m * b - 1) / (a - b) + 1;
            }
        }

        //cout << l << " " << r << " " << m << " " << ans_ << endl;

        if (ans > m)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    cout << l << endl;

    return 0;
}