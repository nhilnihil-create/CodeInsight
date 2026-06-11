#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int ans = 0;
    if (D <= A || B <= C) {
        ans = 0;
    }
    else {
        ans = min(B, D) - max(A, C);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
