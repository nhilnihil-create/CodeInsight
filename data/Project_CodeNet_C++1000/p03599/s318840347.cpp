#include <bits/stdc++.h>

int main() {
    int A, B, C, D, E, F;
    std::cin >> A >> B >> C >> D >> E >> F;

    double max_den = -1;
    int max_w = 0, max_s = 0;
    for (int i = 0; i <= F / (100 * A); ++i) {
        for (int j = 0; j <= F / (100 * B); ++j) {
            for (int k = 0; k <= F / C; ++k) {
                for (int l = 0; l <= F / D; ++l) {
                    const int w = 100 * A * i + 100 * B * j;
                    const int s = C * k + D * l;

                    if (((w * E / 100.0) < s) || ((w + s) > F)) {
                        continue;
                    } 

                    const double den = 100.0 * s / (w + s);
                    if (max_den < den) {
                        max_den = den;
                        max_w = w;
                        max_s = s;  
                    }
                }
            }    
        }
    }

    std::printf("%d %d\n", max_w + max_s, max_s);
    
    return 0;
}
