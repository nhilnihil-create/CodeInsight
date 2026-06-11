#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    set<int> waterS, sugarS;
    for (int i = 0; i <= 30; i++)
    {
        for (int j = 0; j <= 30; j++) {
            int x = A * 100 * i + B * 100 * j;
            if (x <= F)
                waterS.insert(x);
        }
    }

    for (int i = 0; i <= 3000; i++) {
        for (int j = 0; j <=  3000; j++)
        {
            int y = C * i + D * j;
            if ( y <= F)
                sugarS.insert(y);
        }
    }

    double max_per = -1.0;
    int max_f, max_s;

    for (auto x : waterS) {
        for (auto y : sugarS)
        {
            // cout << y << endl;
            // cout << x << " " << y << endl;
            if (x + y > F)
                continue;
            if (y > x/100*E)
                continue;
            double c_per = ((double)y * 100) / ((double)x + y);
            if (max_per < c_per) {
                max_per = c_per;
                max_f = x+y;
                max_s = y;
            }
        }
    }

    cout << max_f << " " << max_s << endl;
}
