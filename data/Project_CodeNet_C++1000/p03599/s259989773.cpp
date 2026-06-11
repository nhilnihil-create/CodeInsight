#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, n) for (int i = 1; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    int maxWater = 100 * A, maxSuger = 0;
    double maxV = -1;
    rep(b, 31) {
        int water = 100 * B * b;
        if (water > F) {
            continue;
        }
        rep(a, 31) {
            water = 100 * B * b + 100 * A * a;
            if (water > F) {
                continue;
            }
            if (water <= 0) {
                continue; 
            }

            for (int d = 0; d * D + water <= F; d++) {
                for (int c = 0; c * C + water <= F; c++) {
                    int suger = c * C + d * D;
                    if (suger <= 0 || water + suger > F || suger > water / 100 * E) {
                        continue;
                    }
                    double v = (double)suger / (suger + water);
                    if (maxV < v) {
                        maxWater = water;
                        maxSuger = suger;
                        maxV = v;
                    }

                }
            }

            // // 3000以下
            // int maxS = water * E / 100;
            // rep(d, maxS / D + 1) {
            //     if (maxS - d * D < 0) {
            //         continue;
            //     }
            //     int c = (maxS - d * D) / C;
            //     int suger = c * C + d * D;
            //     if (suger <= 0 || water + suger > F || suger > water / 100 * E) {
            //         continue;
            //     }
            //     double v = (double)suger / (suger + water);
            //     if (maxV < v) {
            //         maxWater = water;
            //         maxSuger = suger;
            //         maxV = v;
            //     }
            // }
        }
    }

    cout << (maxWater + maxSuger) << " " << maxSuger << endl;
    

    return 0;
}