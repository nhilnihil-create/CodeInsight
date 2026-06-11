#include "bits/stdc++.h"

using namespace std;

void Main() {
    int K, S;
    cin >> K >> S;

    map<int, int> YpZ;
    for (int Y = 0; Y <= K; ++Y) {
        for (int Z = 0; Z <= K; ++Z) {
            int YZ = Y + Z;
            if (YpZ.count(YZ) == 0) {
                YpZ.insert(make_pair(YZ, 0));
            }
            YpZ[YZ] += 1;
        }
    }
    int ans = 0;
    for (int X = 0; X <= K; ++X) {
        if (S < X) {
            break;
        }
        if (YpZ.count(S - X) == 0) {
            continue;
        }
        ans += YpZ[S - X];
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
