#include <bits/stdc++.h>
using  namespace std;

#define    ll     long long int

int main( )
{
    double mx_percent = 0.0;
    int mx_sugar_water = 0;
    int mx_sugar = 0;

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int i, j, k, l, mass_water, mass_sugar, need_sugar;
    double percent;

    for (i = 0; i <= 30; i++ ) {
        for (j = 0; j <= 30; j++) {
            mass_water = (i * a + j * b);
            if (mass_water == 0) continue;
            need_sugar = mass_water * e;
            for (k = 0; k <= f; k++) {
                for (l = 0; k * c + l * d <= need_sugar; l++) {
                    mass_sugar = k * c + l * d;
                    if (mass_sugar + mass_water * 100 <= f) {
                        percent = (100.0 * mass_sugar) / (mass_water * 100.0 + mass_sugar);
                        if (percent >= mx_percent) {
                            mx_percent = percent;
                            mx_sugar_water = (mass_sugar + mass_water * 100);
                            mx_sugar = mass_sugar;
                        }
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    cout << mx_sugar_water << ' ' << mx_sugar << '\n';
    return 0;
}
