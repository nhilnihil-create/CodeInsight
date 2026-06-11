#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int mx = f / 100;
    //    int mani1, mani2, water,smax;
    double conc = 0.0;
    double cmax = 100.0 * (double)e / (100.0 + (double)e);
    //   cout << "cmax=" << cmax << endl;
    int w = 0, s = 0;
    //   cout << mx / a << " " << mx / b << endl;
    rep(i, mx / a + 1)
    {
        int mani1 = i * 100 * a;
        rep(j, mx / b + 1)
        {
            int mani2 = j * b * 100;
            int water = mani1 + mani2;
            int smax = f - water;
            rep(k, smax / c + 1)
            {
                int mani3 = k * c;
                rep(l, smax / d + 1)
                {
                    int mani4 = l * d;
                    int sugar = mani3 + mani4;
                    if ((sugar + water) <= f)
                    {
                        double ctmp = 100.0 * (double)sugar / ((double)sugar + (double)water + 1e-10);
                        //             cout << "sugar=" << sugar << endl;
                        //           cout << "water=" << water << endl;
                        //         cout << "ctmp=" << ctmp << endl;
                        if (ctmp >= conc && ctmp <= cmax)
                        {
                            conc = ctmp;
                            w = water;
                            s = sugar;
                            //       cout << "w=" << w << ",s=" << s << endl;
                        }
                    }
                }
            }
        }
    }
    cout << w + s << " " << s << endl;
}