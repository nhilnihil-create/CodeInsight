#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double res = -1;
    int ressugar = 0;
    int reswater = 0;
    int index = 0;
    for (int na = 0; na < 31; na++)
    {
        for (int nb = 0; nb < 31; nb++)
        {
            for (int nc = 0; nc < 101; nc++)
            {
                for (int nd = 0; nd < 101; nd++)
                {
                    if (na == 0 & nb == 0 & nc == 0 & nd == 0)
                        continue;
                    if (a * 100 * na + b * 100 * nb + c * nc + d * nd > f)
                    {
                        continue;
                    }
                    if (c * nc + d * nd > (a * na + b * nb) * e)
                    {
                        continue;
                    }
                    int sugar = c * nc + d * nd;
                    int water = a * 100 * na + b * 100 * nb;
                    if (0 == water)
                        continue;
                    double conc_inv = (double)sugar / (double)water;
                    res = max(res, conc_inv);
                    if (res == conc_inv)
                    {
                        ressugar = sugar;
                        reswater = water;
                    }
                }
            }
        }
    }
    cout << ressugar + reswater << " " << ressugar << endl;
    return 0;
}