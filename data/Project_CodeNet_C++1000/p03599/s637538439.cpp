#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

using namespace std;
using ll = long long;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    // もっとも高い濃度(%)
    double max_density = -1;
    // もっとも高い濃度の砂糖水の質量
    int ans1 = 0;
    // もっとも高い濃度の砂糖水の砂糖の質量
    int ans2 = 0;

    for (int i = 0; 100 * A * i <= F; i++) {
        for (int j = 0; 100 * A * i + 100 * B * j <= F; j++) {
            for (int k = 0; 100 * A * i + 100 * B * j + C * k <= F && C * k <= E * (A * i + B * j); k++) {
                for (int l = 0; 100 * A * i + 100 * B * j + C * k + D * l <= F && C * k + D * l <= E * (A * i + B * j); l++) {

                    double density = (double) (C * k + D * l) / (double) (100 * A * i + 100 * B * j + C * k + D * l) * 100;

                    if (max_density < density) {
                        max_density = density;
                        ans2 = C * k + D * l;
                        ans1 = 100 * A * i + 100 * B * j + C * k + D * l;
                    }
                }
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}
