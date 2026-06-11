#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;
    int ans = A + B;
    if (ans >= 24) {
        ans -= 24;
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
