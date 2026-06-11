#include "bits/stdc++.h"

using namespace std;

void Main() {
    int A, B;
    cin >> A >> B;

    if (A == 1 && B == 1) {
        cout << "Draw" << endl;
    }
    else if (A == 1) {
        cout << "Alice" << endl;
    }
    else if (B == 1) {
        cout << "Bob" << endl;
    }
    else {
        cout << (A > B ? "Alice" : (A < B ? "Bob" : "Draw")) << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
