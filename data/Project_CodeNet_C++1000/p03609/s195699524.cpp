#include "bits/stdc++.h"

using namespace std;

void Main() {
    int X, t;
    cin >> X >> t;

    if (t < X) {
        cout << X - t << endl;
    }
    else {
        cout << 0 << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
