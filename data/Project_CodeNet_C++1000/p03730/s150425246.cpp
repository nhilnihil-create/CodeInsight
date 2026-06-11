#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B, C;
    cin >> A >> B >> C;

    bool ans = false;
    for (int n = 1; n <= B; ++n) {
        if ((n * A) % B == C) {
            ans = true;
        }
    }
    cout << (ans ? "YES" : "NO") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
